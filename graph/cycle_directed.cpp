//detect cycle in directed graph
//create an visited like array which stores the
//recursive tree nodes which a;ready we have visited

#include "Graph.h"

class DerivedClass:public Graph{
    public:
    DerivedClass(V):Graph(v){};

    bool detectdfs(int curr,vector<bool>&vis,vector<bool>&recPath)
    {
        vis[curr]=true;
        recPath[curr]=true;

        for(int v:l[curr])
        {
            if(!vis[v]){
                if(dfs(v,vis,recPath))return true;
            }else if(recPath[v])
            {
                return true;
            }
        }
        recPath[curr]=false;
        return false;
    }
    bool isClycle()
    {
        vector<bool>vis(v,false);
        vector<bool>recPath(v,false);

        for(int i=0;i<v;i++)
        {
            if(detectdfs(i,vis,recPath))return true;
        }
        return false;
    }
};
int main()
{
    DerivedClass g(4);
    g.addEdgeDirected(1,0);
    g.addEdgeDirected(3,0);
    g.addEdgeDirected(0,2);
    g.addEdgeDirected(2,3);

    g.printAdjList();
}