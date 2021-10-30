/*
    Copyright Michael Busby 2010
*/

#include <iostream>
#include <string>
#include "ConfigFile.h"
#include "bicut.h"
#include "randomsolve.h"

using std::string;
using std::cout;
using std::endl;

ConfigFile *gConfig;
BiCutSolver *gSolver;

int main(int argc, char *argv[])
{
	if(argc >1)
	{
		gConfig = new ConfigFile(argv[1]);
	}
	else
	{
		gConfig = new ConfigFile("default.cfg");
	}
	
	string inputfile = gConfig->read<string>("inputfile");
	string logfile = gConfig->read<string>("logfile");
	string outfile = gConfig->read<string>("solnfile");
	size_t evals = gConfig->read<size_t>("evals");
	
	cout << "Input file: " << inputfile << endl;		
	cout << "Log file: " << logfile << endl;
	cout << "Solution File: " << outfile << endl;
	
	BiCutProblem myProblem(inputfile.c_str());
	cout << "Vertices: " << myProblem.GetVertexCount() << endl;
	cout << "Edges: " << myProblem.GetEdgeCount() << " (" << myProblem.GetEdgeList()->size() << ")"<<endl;

    gSolver = new RandomBiCutSolver();
    
    ((RandomBiCutSolver*)gSolver)->setRandomSeed(gConfig->read<unsigned int>("rndseed"));
    
    gSolver->setProblem(myProblem);
    gSolver->setLogFile(logfile.c_str());
    gSolver->setSolnFile(outfile.c_str());
    gSolver->solve(evals);
    
    delete gSolver;
    delete gConfig;
	return 0;
}
