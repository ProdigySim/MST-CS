import random
from time import time
from bitstring import Bits
import itertools
import fileinput
import configparser
import sys

def UniformMutate(bitstrs):
	for i in range(len(bitstrs)):
		for j in range(vertNum):
			if(random.random() < mutatechance):
				bitstrs[i][j] += (bitstrs[i][j]+1)%2
	
def UniformRecombination(bitstrs):
	return [random.choice(bitstrs)[x] for x in range(vertNum)]
	
def getFitness(soln):
	part1=soln.count(1)
	denominator=min(vertNum-part1, part1)
	numerator=sum(1 for edge in edges if soln[edge[0]-1] != soln[edge[1]-1])
	return (1/numerator, denominator)
	

def fixSolution(soln):
	okay=[False, False]
	for i in soln:
		okay[soln[i]]=True
	if not (okay[0] and okay[1]):
		soln[0]=(soln[0]+1)%2
	return soln
	
	
def GenerateInitialPopulation():
	return [(x, getFitness(x)) for x in [fixSolution([random.getrandbits(1) for verts in range(vertNum)]) for i in range(populationSize)]]
	
	
def Dominates(x, y):
	onegreater=False
	for i in range(len(x)):
		if x[i] < y[i]:
			return False
		if x[i] > y[i]:
			onegreater=True
	return onegreater
	
def EvaluatePopulation(pop):
	evoPop=[]
	front=0
	frontstart=0
	while len(pop) != 0:
		for i in pop:
			dominated=False
			for j in pop:
				if Dominates(j[1], i[1]):
					dominated=True
					break
			if not dominated:
				evoPop.append((i, front))
		for i in evoPop[frontstart:]:
			pop.remove(i[0])
		frontstart=len(evoPop)
		front+=1
	return evoPop

def MOEASelect(evoPop):
	if evoPop[populationSize][1] != evoPop[populationSize-1][1]:
		return evoPop[:populationSize]
	
	brokenFront=evoPop[populationSize][1]
	first=populationSize
	last=populationSize
	while first >= brokenFront and evoPop[first][1] == brokenFront:
		first-=1
	first+=1
	while last < len(evoPop) and evoPop[last][1] == brokenFront:
		last+=1
	
	redfront=ReduceFront(evoPop[first:last], populationSize-first)
	return evoPop[:first]+redfront
	
def ReduceFront(front, limit):
	crowds=[crowdingDistance(front, i) for i in front]
	while len(front) > limit:
		lilind=0
		for i in range(len(crowds)):
			if crowds[i] < crowds[lilind]:
				lilind = i 
		crowds.pop(lilind)
		front.pop(lilind)
	return front
	
def crowdingDistance(evopop, ffsoln):
	myFront=[i for i in evopop if i[1] == ffsoln[1] and i != ffsoln]
	if len(myFront) > 0:
		return sum((Bits(ffsoln[0][0])^Bits(i[0][0])).count(1) for i in myFront)/len(myFront)
	return 0
	
				
def BinaryTournament(evopop, numoutputs):
	if numoutputs == len(evopop):
		return evopop
	parents=[]
	while len(parents) < numoutputs:
		pair=random.sample(evopop, 2)
		while pair[0] in parents or pair[1] in parents:
			pair=random.sample(evopop, 2)
		
		if pair[0][1] < pair[1][1]:
			parents.append(pair[0])
		elif pair[1][1] < pair[0][1]:
			parents.append(pair[0])
		else:
			crow1=crowdingDistance(evopop, pair[0])
			crow2=crowdingDistance(evopop, pair[1])
			if crow1 > crow2:
				parents.append(pair[0])
			else:
				parents.append(pair[1])
	return parents	
	
def CreateOffspring(parents, numChild):
	children=[]
	while len(children) < numChild:
		mates=random.sample(parents, 2)
		children.append(Recombination((mates[0][0][0], mates[1][0][0])))
	return children
		

## debugging functions
def printEvoPopulation(epop):
	for i in epop:
		printFrontFitSoln(i)
		print("")

def printFrontFitSoln(ffsoln):
	printFitSoln(ffsoln[0])
	print("Front:", ffsoln[1], end=" ")

def printPopulation(pop):
	for i in pop:
		printFitSoln(i)
		print("")

def printFitSoln(fitSoln):
	printSoln(fitSoln[0])
	print(fitSoln[1], fitSoln[1][1]*fitSoln[1][0], end=" ")

def printSolns(solns):
	for i in solns:
		printSoln(i)
		print("")

def printSoln(soln):
	print(Bits(soln).bin[2:], end=" ")
	
def MakePopFromSolns(solns):
	mypop=[]
	for i in solns:
		soln=fixSolution(i)
		fit=getFitness(soln)
		mypop.append((soln, fit))
	return mypop


	
## files
infile="G4.dat"
logfile="log-G4.txt"
outfile="soln-G1.txt"
logout=None
solnout=None

## problem
vertNum=0
edgeNum=0
edges=tuple()

## evo vars
numRuns=30
numEvals=10000
mu=150
LMBDR=300
seed=0
mutatechance=1/2000
numOffspring=LMBDR
populationSize=mu
parentK=50

## evo functions
#ParentSelect=BinaryTournament
Recombination=UniformRecombination
Mutate=UniformMutate
SurvivalSelect=MOEASelect


def GetOpts(cfg):
	global infile, logfile, outfile, numRuns, numEvals, mu, LMBDR, seed
	global mutatechance, numOffspring, populationSize, parentK
	config = configparser.RawConfigParser()
	config.read(cfg)
	infile=config.get("Configuration", "input")
	logfile=config.get("Configuration", "log")
	outfile=config.get("Configuration","output")
	numRuns=config.getint("Configuration","runs")
	numEvals=config.getint("Configuration","evals")
	mu=config.getint("Configuration", "mu")
	LMBDR=config.getint("Configuration", "lambda")
	mutatechance=config.getfloat("Configuration", "mutatechance")
	parentK=config.getint("Configuration", "numParents")
	seed=config.getint("Configuration", "seed")
	populationSize=mu
	numOffspring=LMBDR
	
	
	
def ReadProblem(infile):
	global vertNum
	global edgeNum
	global edges
	p=open(infile)
	vertNum=int(p.readline())
	edgeNum=int(p.readline())
	edges=tuple((int(line.split()[0]), int(line.split()[1])) for line in p.readlines())
	return (vertNum, edgeNum, edges)
	
def EvalRun(runNumber):
	logout.write("Run "+str(runNumber)+"\n")
	print("")
	print("Generating population size:", populationSize)
	print("")
	
	population = GenerateInitialPopulation()
	print("")
	avg=0	
	evalpopulation=EvaluatePopulation(population)
	for evals in itertools.count(mu,LMBDR):
		print("Evals:", evals)
		avg=sum(x[0][1][0]*x[0][1][1] for x in evalpopulation)/len(evalpopulation)
		best=max(x[0][1][0]*x[0][1][1] for x in evalpopulation)
		logout.write(str(evals)+"\t"+str(avg)+"\t"+str(best)+"\n")
		if(evals >=numEvals):
			break
		lasttime=time()
		
		#print("Making Parents...")
		parents=BinaryTournament(evalpopulation, parentK)
		
		#print("Creating Offspring...")
		offspring=CreateOffspring(parents, numOffspring)
				
		#print("Mutating Offspring...")
		Mutate(offspring)
		
		#print("Mixing population and offspring...")
		population=MakePopFromSolns(offspring)+[ffsoln[0] for ffsoln in evalpopulation]
		
		#print("Evaluating bigpop...")
		evalpopulation=EvaluatePopulation(population)
		
		#print("Survival Selection...")
		evalpopulation = SurvivalSelect(evalpopulation)
		print(time()-lasttime)
	
	return ([x for x in evalpopulation if x[1] == 0], avg)

def main(cfg):
	global seed, logout, solnout
	GetOpts(cfg)
	vertNum, edgeNum, edges = ReadProblem(infile)
	if seed == 0:
		seed = int(time()*1000)
	random.seed(seed)
	
	logout=open(logfile, "w")
	logout.write("Result Log\n")
	print("Seed:", seed)
	# find the best front out of numRuns runs of our algorithm, sorted on average run fitness
	bestfront=max(map(EvalRun, list(range(1,numRuns+1))), key=lambda frontavg: frontavg[1])
	solnout=open(outfile, "w")
	for soln in bestfront[0]:
		solnout.write(str(int(1/soln[0][1][0]))+"\t"+str(soln[0][1][1])+"\t"+Bits(soln[0][0]).bin[2:]+"\n")
	solnout.close()
	logout.close()
	
if __name__ == "__main__":
	if len(sys.argv) == 1:
		main("default.cfg")
	else:
		for arg in sys.argv[1:]:
			main(arg)
		
		
