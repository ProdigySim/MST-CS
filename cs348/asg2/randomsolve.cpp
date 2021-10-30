/*
    Copyright Michael Busby 2010
*/

#include "randomsolve.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using std::list;
using std::ofstream;
using std::endl;
using std::cout;

BiCutSolution RandomBiCutSolver::getRandomSolution()
{
    BiCutSolution soln;
    bool valid[2]={0};
    int next;
    for(int i = 0; i < prob.GetVertexCount(); i++)
    {
        next=rand()%2;
        valid[next]=1;
        soln.push_back(next != 0);
    }
    if(!valid[0] || !valid[1])
    {
        soln[0] = !soln[0];
    }
    return soln;

}

float RandomBiCutSolver::evaluateFitness(BiCutSolution soln)
{
    int part1=0,part2=0;
    for(int i =0; i < soln.size(); i++)
    {
        if(soln[i]) ++part1;
        else ++part2;
    }

    int minpart = part1 >part2 ? part2 : part1;
    
    int cutedges=0;
    for(list<BiCutEdge>::iterator i = edges.begin(); i != edges.end(); i++)
    {
        if(soln[(i->v1)-1] != soln[(i->v2)-1]) ++cutedges;
    }
    return float(minpart)/float(cutedges);
}

void RandomBiCutSolver::solve(const size_t evals)
{
    ofstream logout(logname);
    
    logout << logname << endl;
    // Seed random number gen
    if(!seed) seed = time(0);
    srand( seed );
    logout << "Seed: " << seed << endl;
    
    
    for (size_t i = 0; i < evals; i++)
    {
        static BiCutSolution cursoln;
        static float curfitness;
        cursoln = getRandomSolution();
        curfitness = evaluateFitness(cursoln);

        if(curfitness > bestrating)
        {
            logout << i << "\t" << curfitness << endl;
            bestrating = curfitness;
            bestsoln = cursoln;
        }
    }
    
    logout.close();
    
    cout << "Final solution after " << evals << " evaluations" << endl;
    ofstream solnfile(outfile);
    for(size_t i =0;i < bestsoln.size(); i++)
    {
        cout << bestsoln[i];
        solnfile << bestsoln[i];
    }
    cout << endl;
    solnfile << endl;
    solnfile.close();
}

