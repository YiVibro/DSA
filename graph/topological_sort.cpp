//Directed acyclic grapg(DAG)
//use dfs approach
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int v;
    list<int> *l;

    Graph(int V)
    {
        this->v=V;
        l= new list<int>[v];
    }

    void addEdge(int u,int v)
    {
        l[u].push_back(v);
    }

    void printEdge()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<":";
            for(int l:l[i])
            {
                cout<<l<<" ";
            }
            cout<<endl;
        }
    }
    void dfs(int cur,vector<bool>&visited,stack<int>&st)
{
   visited[cur]=true;

   for(int v:l[cur])
   {
    if(!visited[cur])
    {
        dfs(v,visited,st);
    }
   }
   st.push(cur);
}

void toposort(){
    vector<bool>vis(v,false);
    stack<int>s;

    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,s);
        }
    }

    while(!s.empty())
    {
        cout<< s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
};

int main()
{
    int V=6;
   Graph g(V);

   g.addEdge(5,0);
     g.addEdge(4,0);
       g.addEdge(5,2);
         g.addEdge(4,1);
           g.addEdge(2,3);
             g.addEdge(3,1);

             //g.printEdge();

   g.toposort();
   

}