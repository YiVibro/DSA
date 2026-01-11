#ifndef GRAPH_H
#define GRAPH_H

#include<bits/stdc++.h>
using namespace std;

class Graph{
    vector<bool> visited;
    stack<int> st;
    queue<int> q;

public:

 int v;
 list<int>*l;

 Graph(int V); 
 
 void addEdge(int u,int v);

 void addEdgeDirected(int u,int v);

 void printAdjList();

 void bfs(int v);

 void dfs(int v);

};

#endif