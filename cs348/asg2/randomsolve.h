/*
    Copyright Michael Busby 2010
*/

#ifndef __RADNOMSOLVER_H__
#define __RANDOMSOLVER_H__

#include "bicut.h"

class RandomBiCutSolver: public BiCutSolver
{
    private:
        BiCutProblem prob;
        std::list<BiCutEdge> edges;
        BiCutSolution bestsoln;
        float bestrating;
        BiCutSolution getRandomSolution();
        float evaluateFitness(BiCutSolution);
        unsigned int seed;
        const char * logname;
        const char * outfile;
    public: // custom
        void setRandomSeed(unsigned int rseed)
        {
            seed=rseed;
        }
    public: // inherited
        RandomBiCutSolver() { bestrating = 0.0; }
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


