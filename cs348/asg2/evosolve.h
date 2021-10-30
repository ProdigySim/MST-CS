/*
    Copyright Michael Busby 2010
*/

#ifndef __EABICUTSOLVER_H__
#define __EABICUTSOLVER_H__

#include "bicut.h"

struct BCSolnFit {
	BiCutSolution soln;
	float fitness;
	bool operator<(const BCSolnFit &bcsf) { return fitness < bcsf.fitness; }
	bool operator>(const BCSolnFit &bcsf) { return fitness > bcsf.fitness; }
}

class EABiCutSolver: public BiCutSolver
{
    private:
        BiCutProblem prob;
        std::list<BiCutEdge> edges;
		vector<BCSolnFit> population;
		vector<BCSolnFit> parents;
        BiCutSolution bestsoln;
        unsigned int seed;
        const char * logname;
        const char * outfile;
		void (*p_ParentSelection)() = NULL;
		void (*p_Recombination)() = NULL;
		void (*p_SurvivalSelection)() = NULL;
		void (*p_PerformMutation)() = NULL;
		
		void InitializePool();
		void EvaluatePool();
		bool ShouldTerminate();
    public: // custom
		void Init(unsigned int flags, ... );
		void FitnessProportionalParentSelect();
        void setRandomSeed(unsigned int rseed)
        {
            seed=rseed;
        }
    public: // inherited
        EABiCutSolver() { }
        ~RandomBiCutSolver() {}

        void setProblem(const BiCutProblem p)
        {
            prob = p;
            edges = *(p.GetEdgeList());
        }
        void setLogFile(const char * logfile)
        {
            logname = logfile;
        }
        void setSolnFile(const char * solnfile)
        {
            outfile = solnfile;
        }
        void solve(const size_t evals);
};


#endif


