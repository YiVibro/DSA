#include "Graph.h"

void dfs(int n,Graph &g,vector<bool>&vis,stack<int>&st)
{
    vis[n]=true;
    for(auto neig:g.l[n])
    {
        if(!vis[neig])
        {
            dfs(neig,g,vis,st);
        }
    }
    st.push(n);
}
void dfs3(int n,Graph &g,vector<bool>&vis)
{
    vis[n]=true;
    for(auto neig:g.l[n])
    {
        if(!vis[neig])
        {
            dfs3(neig,g,vis);
        }
    }
}
int ssc(Graph &g)
{
    int ssc=0;
//    for(int i=0;i<8;i++)
//    {
//      cout<< i << " : ";
//     for(auto k:g.l[i])cout<<k<<" ";
//     cout<<endl;
//    }

 stack<int>st;
 vector<bool>vis(9,false);

 for(int i=0;i<8;i++)
 {
    if(!vis[i])
    {
       dfs(i,g,vis,st);
    }
 }

 Graph gT(8);
 for(int i=0;i<8;i++)
 {
    for(auto neig:g.l[i])
    {
        gT.l[neig].push_back(i);
    }
 }
for(int i=0;i<8;i++)
{
    vis[i]=false;
}
//    for(int i=0;i<8;i++)
//    {
//      cout<< i << " : ";
//     for(auto k:gT.l[i])cout<<k<<" ";
//     cout<<endl;
//    }
 while(!st.empty())
 {
    if(!vis[st.top()])
    {
        dfs3(st.top(),gT,vis);
        ssc++;
    }
    st.pop();
 }

   return ssc;
}
int main()
{
    Graph g(8);
    g.addEdgeDirected(0,1);
    g.addEdgeDirected(1,2);
    g.addEdgeDirected(2,0);
    g.addEdgeDirected(1,3);
    g.addEdgeDirected(3,4);
    g.addEdgeDirected(4,5);
    g.addEdgeDirected(5,6);
    g.addEdgeDirected(6,4);
    g.addEdgeDirected(5,7);
    g.addEdgeDirected(6,7);
    // g.printAdjList();
    // g.dfs(0);
    cout<<ssc(g);
}