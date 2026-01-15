//also called Tarjans algo
//defination
//any edge if removal breaks down graph into two or
//more components
//use dfs
//tin[](tim of insertion)-->keep track of in which step we are reaching a node
//low[]-->lowest time of insertion
//min lowest time insertion of all adajacent nodes apart from parents

 //leetcode 1192
 #include "Graph.h"

 void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],
int tin[],int low[],vector<vector<int>>&bridges)
{
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it:adj[node]){
        if(it==parent)continue;
        if(vis[it]==0){
            dfs(it,node,vis,adj,tin,low,bridges);
            low[node]=min(low[node],low[it]);
            //node--it
            if(low[it]>tin[node]){
                bridges.push_back({it,node});
            }

        }else{
             low[node]=min(low[node],low[it]);
        }
    }
}
 vector<vector<int>>criticalConnection(int n,
   vector<vector<int>&connections){

int timer=1;
    vector<int>vis(n,0);
    int tin[n];
    int low[n];
   }
 
 int main()
{
    Graph g(8);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6,9);
    g.addEdge(7,8);
    g.addEdge(9,8);
    g.addEdge(8,10);
    g.addEdge(10,12);
    g.addEdge(10,11);
    g.addEdge(11,12);
    // g.printAdjList();
    // g.dfs(0);
    dfs(0,-1,vis,tin,low,bridges);
    cout<<ssc(g);
}