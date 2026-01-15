#include<heap>
#include<iostream>

using namespace std;

vector<int>dijkstras(int V,vector<vector<pair<int,int>>&adj,int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    vector<int>dis(V,INT_MAX);

    dis[src]=0;
    pq.push({0,src});

    while(!pq.empty())
    {
        auto[d,u]=pq.top();
        pq.pop();

        if(d>dis[u])continue;

        for(auto [v,wt]:adj[u]){
            if(dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
            }
        }
    }
}
int main()
{

}