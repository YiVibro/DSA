//cycle detecion for undirected graph
//back edge==there exists a node which is not the parent 
//but it is the neighobur and already visited
//then ther is a cycle


#include "Graph.h"

class DerivedClass:public Graph{
    public:
    DerivedClass(int v):Graph(v){};

    bool isCycleUndirDFS(int src,int par,vector<bool>&vis)
    {
        vis[src]=true;
        list<int>neighbours=l[src];

        for(int v:neighbours)
        {
            if(!vis[v])
            {
                if(isCycleUndirDFS(v,src,vis))return true;
            }else if(v!=par){
                return true;
            }
        }
        return false;
    }
    
    bool isCycle()
    {
        vector<bool>&vis(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleUndirDFS(v,src,vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// void helper(Graph &g,int v,bool visited[],parent)
// {
//     visited[v]=true;

//     for(auto neig:g[v])
//     {
//         if(!visited[neig])
//         {
//             if(helper(g,v,visited,neig))return true;
//         }else if(v!=parent)
//         {
//             return true;
//         }
//         }
//     }
//     return false;

// }

// void  cylceDetection(Graph &g,int v)
// {
//    bool visited[v]={false};
//    helper(g,v,visited,-1);
// }
int main()
{
    DerivedClass g(5);
   
   g.addEdge(0,1);
   g.addEdge(0,2);
   g.addEdge(0,3);
   g.addEdge(3,4);

   cout<<g.isCycle()<<endl;
//    g.printAdjList();

//    cylceDetection(g,5);
}