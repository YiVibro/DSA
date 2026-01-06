#ifndef GRAPH_H
#define GRAPH_H

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>*l;

public:
 Graph(int V); 
 
 void addEdge(int u,int v);

 void printAdjList();
};

#endif