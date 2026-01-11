#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int v;
        int wt;

        Edge(int v,int wt)
        {
            this->v=v;
            this->wt=wt;
        }
};

void bellmanford(vector<vector<Edge>>g,int src)
{
    
    int V=g.size();
    int dis[V]={INT_MAX};
    dis[src]=0;
    for(int i=0;i<V-1;i++)
    {
        for(int u=0;u<V;u++)
        {
            for(Edge e:g[u])
            {
                if(dis[e.v]>dis[u]+e.wt)
                {
                    dis[e.v]=dis[u]+e.wt;
                }
            }
        }
    }
}

int main()
{
   int V=6;
   vector<vector<Edge>>g(V);

   g[0].push_back(Edge(1,2));
   g[0].push_back(Edge(2,4));

   g[1].push_back(Edge(2,1));
   g[1].push_back(Edge(3,7));

   g[2].push_back(Edge(4,3));
   
   g[3].push_back(Edge(5,1));

   g[4].push_back(Edge(3,2));
   g[4].push_back(Edge(5,5));

   dijkstra(g,0,V);

   return 0;
}
