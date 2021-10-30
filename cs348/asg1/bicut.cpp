/*
    Copyright Michael Busby 2010
*/

#include "bicut.h"
#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::cout;
using std::endl;
using std::list;


BiCutProblem::BiCutProblem(const char *inputfile)
{
    BiCutEdge tedge;
    ifstream fin(inputfile);
    
    fin >> vertexcnt;
    fin >> edgecnt;
    
    for (size_t i = 0; i < edgecnt; i++)
    {
        fin >> tedge.v1;
        fin >> tedge.v2;
        AddEdge(tedge);
    }
    fin.close();
}
