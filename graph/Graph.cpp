#include "Graph.h"

Graph::Graph(int V)
{
  this->v=V;
   l= new list<int>[v];
}
 
 void Graph::addEdge(int u,int v)
 {
    l[u].push_back(v);
    l[v].push_back(u);
 }

 void Graph::printAdjList()
 {
    for(int i=0;i<v;i++)
    {
        cout<< i << " : ";
        for(int neigh:l[i])
        {
            cout<<neigh<<" ";
        }
      cout<<endl;
    }
 }


