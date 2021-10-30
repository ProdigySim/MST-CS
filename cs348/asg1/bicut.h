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

#endif


