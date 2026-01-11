#include "Graph.h"

class ExtendedClass:public Graph{
   
    public:
     vector<bool>vis;
        ExtendedClass(int n):Graph(n){
            vis.resize(n,false);
        }

        bool cycleDetect(int src){
            queue<pair<int,int>>q;
            vis[src]=true;
            q.push({src,-1});

            while(!q.empty())
            {
                int n=q.front().first;
                int p=q.front().second;
                q.pop();

                for(auto neig:l[n])
                {
                    if(!vis[neig])
                    {
                        q.push({neig,n});
                        vis[neig]=true;
                    }else if(neig!=p){
                        return true;
                    }
                }

            }
            return false;
        }

        bool dfsDirectedCycle(int cur,vector<bool>vis,recPath)
        {
            vis[curr]=true;
            recPath[cur]=true;

            for(auto neig:l[cur])
            {
                if(!vis[neig])
                {
                   if(solve(neig,vis,recPath))
                   {
                    return true;
                   }
                }else if(recPath[neig]){
                    return true;
                }
                recPath[curr]=false;
                return false;
            }
        }

};
int main()
{
    ExtendedClass g(5);

    // g.addEdge(1,0);
    // g.addEdge(0,2);
    // g.addEdge(0,3);
    // g.addEdge(3,4);
    g.addEdge(1,0);
    g.addEdge(2,3);

    for(int i=0;i<5;i++)
    {
        if(!g.vis[i])
        {
            if(g.cycleDetect(i))
            {
                cout<<"Detected cycle\n";
                return 0;
            }

        }
    }
    
}