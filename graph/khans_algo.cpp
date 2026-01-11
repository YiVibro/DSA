//used for finding topological sorting
//uses BFS
//find indegree of all the nodes
//stpes
//findout all indegrees of all node
//loop through all the neighbours and decrees indegree
//if indegree becones 0 then push it on to queue
//
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int v;
    list<int> *l;

    Graph(int V)
    {
        this->v=V;
        l=new list<int>[v];
    }

    void addEdge(int u,int v)
    {
        l[u].push_back(v);
    }

    void khans()
    {
        vector<int>indegree(v,0);
        queue<int>q;
        vector<int>res(v,0);

        //s1) findout all indegree
        for(int i=0;i<v;i++)
        {
            for(int u:l[i])
            {
                indegree[u]++;
            }
        }
        //s2) push node with indegree of 0
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        //s3)
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            for(auto i:l[curr])
            {
                indegree[i]--;
                if(indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }

        for(int i:res)
        {
            cout<<i<<" ";
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

   //g.toposort();

   g.khans();
}