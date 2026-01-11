#include "Graph.h"

Graph::Graph(int V)
{
  this->v=V;
  l= new list<int>[v];

  visited.resize(v,false);
}
 
 void Graph::addEdge(int u,int v)
 {
    l[u].push_back(v);
    l[v].push_back(u);
 }

 void Graph::addEdgeDirected(int u,int v)
 {
   l[u].push_back(v);
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

void Graph::bfs(int s)
{
   vector<bool>visited(v,false);
   q.push(s);
   visited[s]=true;
   while(!q.empty())
   {
      int p= q.front();
      q.pop();

      cout<<p<<" ";
      for(auto i:l[p])
      {
         if(!visited[i])
         {
            q.push(i); 
            visited[i]=true;
         }
      }
   }
}


void Graph::dfs(int s)
{
   visited[s]=true;
   st.push(s);
    cout<<s<<" ";
   for(int i:l[s])
   {
      if(!visited[i])
      {
         dfs(i);
      }
   }
}

