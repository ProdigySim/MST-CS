/*
    Copyright Michael Busby 2010
*/

#include "evosolve.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using std::list;
using std::ofstream;
using std::endl;
using std::cout;

// Uniform random in a range
unsigned int randrange(unsigned int low, unsigned int high)
{
	return low + ((rand() * ( 1.0 / ( RAND_MAX + 1.0 ))) * (high - low));
}

// configured by variable numParentSelect 
void EABiCutSolver::FitnessProportionalParentSelect()
{
	// Expects sorted population
	parents.assign( population.rbegin(), population.rbegin()+1+numParentSelect );
}

// configured by variables numParentSelect and ParentTourneyK
void EABiCutSolver::kTournamentParentSelect()
{
	list<BCFitSoln> parentpool( population.begin(), population.end() );
	list<BCFitSoln> tourneypool;
	parents.clear();
	for(unsigned int i=numParentSelect; i; --i)
	{
		tourneypool.assign(parentpool.begin(), parentpool.end());
		while (tourneypool.size() > ParentTourneyK)
		{
			tourneypool.erase(tourneypool.begin()+randrange(0, tourneypool.size()));
		}
		// best in tourney pool is at the end of the vector.
		parents.push_back(*tourneypool.rbegin());
		parentpool.erase(*tourneypool.rbegin());
	}
}

void EABiCutSolver::solve(const size_t evals)
{
    ofstream logout(logname);
    
    logout << logname << endl;
    // Seed random number gen
    if(!seed) seed = time(0);
    srand( seed );
    logout << "Seed: " << seed << endl;
    
    InitializePool();
    
	EvaluatePool();
	
    while(!ShouldTerminate())
    {
		p_ParentSelection();
        p_Recombination();
        p_PerformMutation();
        p_SurvivalSelection();
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

