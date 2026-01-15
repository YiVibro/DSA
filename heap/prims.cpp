#include <bits/stdc++.h>
using namespace std;

int primMST(int V, vector<vector<pair<int,int>>> &adj)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<bool> inMST(V, false);

    pq.push({0, 0}); // {weight, node}
    int mstCost = 0;

    while(!pq.empty())
    {
        auto [wt, u] = pq.top();
        pq.pop();

        if(inMST[u]) continue;

        inMST[u] = true;
        mstCost += wt;

        for(auto [v, w] : adj[u])
        {
            if(!inMST[v])
                pq.push({w, v});
        }
    }

    return mstCost;
}
