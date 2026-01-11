//cycle detection in undirected graph
//use back edge conecpt
//check the node which is visited and not the parent
#include "Graph.h"

class DerivedClass : public Graph {
public:
    DerivedClass(int V) : Graph(V) {}

    bool isCyclebfs(int src, vector<bool>& visited)
    {
        visited[src] = true;
        queue<pair<int,int>> q;
        q.push({src, -1});

        while(!q.empty())
        {
            int u = q.front().first;
            int parU = q.front().second;
            q.pop();

            for(int v : l[u])
            {
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push({v, u});
                }
                else if(v != parU)
                {
                    return true; // cycle found
                }
            }
        }
        return false;
    }

    bool isCycle()
    {
        vector<bool> visited(v, false);

        for(int i = 0; i < v; i++)
        {
            if(!visited[i])
            {
                if(isCyclebfs(i, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
   DerivedClass g(5);

   g.addEdge(0,1);
   g.addEdge(0,2);
   g.addEdge(0,3);
   g.addEdge(3,4);

   cout << g.isCycle() << endl;  // should print 0 (false)
}
