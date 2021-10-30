/*
    Copyright Michael Busby 2010
*/
    
#ifndef __BICUTSOLVER_H__
#define __BICUTSOLVER_H__

#include <list>
#include <vector>

struct BiCutEdge {
	int v1;
	int v2;
};

typedef std::vector<bool> BiCutSolution;

class BiCutProblem
{
	private:
		int vertexcnt;
		int edgecnt;
		std::list<BiCutEdge> edges;
	public:
		BiCutProblem() : vertexcnt(0), edgecnt(0) { }
		BiCutProblem(const char *inputfile);
		BiCutProblem & operator=(const BiCutProblem &rhs)
		{
		    vertexcnt = rhs.GetVertexCount();
		    edgecnt = rhs.GetEdgeCount();
		    edges = *rhs.GetEdgeList();
		}
		void AddEdge(BiCutEdge e)
		{
			int bigv = e.v1 > e.v2 ? e.v1 : e.v2;
			if(bigv > vertexcnt) vertexcnt = bigv;
			edges.push_back(e);
		}
		int GetEdgeCount() const { return edgecnt; }
		int GetVertexCount() const { return vertexcnt; }
		const std::list<BiCutEdge> * GetEdgeList() const { return &edges; }
};

class BiCutSolver
{
    public:
    BiCutSolver() {}
    ~BiCutSolver() {}
    
    virtual void setProblem(const BiCutProblem)=0;
    virtual void setLogFile(const char*)=0;
    virtual void setSolnFile(const char*)=0;
    virtual void solve(const size_t)=0;
};

BiCutSolution GetRandomBiCutSolution()
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

float EvaluateSolutionFitness(BiCutSolution soln)
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

#endif


