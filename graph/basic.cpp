#include "Graph.h"

int main(){
    Graph g(5);
    g.addEdge(0,1); 
    g.addEdge(1,2); 
    g.addEdge(1,3); 
    g.addEdge(2,3); 
    g.addEdge(2,4); 
    
    g.printAdjList();

    return 0;
}