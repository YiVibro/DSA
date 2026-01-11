//used to find if two elements are in same group
//merge two groups
/*If you see:

“connected components”

“merge groups”

“detect cycle in undirected graph”

“minimum spanning tree”

First thought should be DSU, not DFS.
*/
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ru = find(u);
        int rv = find(v);

        if (ru != rv) {
            if (size[ru] < size[rv]) {
                parent[ru] = rv;
                size[rv] += size[ru];
            } else {
                parent[rv] = ru;
                size[ru] += size[rv];
            }
        }
    }
};

int main() {

    // --------------------------------------------------
    // 1) CONNECTED COMPONENTS (UNDIRECTED GRAPH)
    // --------------------------------------------------
    cout << "---- Connected Components ----\n";

    int n1 = 6;
    vector<pair<int,int>> edges1 = {
        {0,1},{1,2},{3,4}
    };

    DSU dsu1(n1);

    for(auto &e : edges1)
        dsu1.unionBySize(e.first, e.second);

    unordered_set<int> comps;
    for(int i = 0; i < n1; i++)
        comps.insert(dsu1.find(i));
           
    cout << "Connected Components = " << comps.size() << "\n\n";

      // --------------------------------------------------
    // 2) CYCLE DETECTION (UNDIRECTED GRAPH)
    // --------------------------------------------------
    cout << "---- Cycle Detection ----\n";

     vector<pair<int,int>> edges2 = {
        {0,1},{1,2},{2,3},{3,1} // cycle here
    };

    DSU dsu2(5);
    bool hasCycle = false;

    for(auto &e:edges2){
        if(dsu2.find(e.first)==dsu2.find(e.second)){
            hasCycle=true;
             cout << "Cycle detected at edge: "
                 << e.first << "-" << e.second << "\n";
        }else {
            dsu2.unionBySize(e.first, e.second);
        }
    }
      cout << "Has Cycle: " << (hasCycle ? "YES" : "NO") << "\n\n";

    // --------------------------------------------------
    // 3) REDUNDANT CONNECTION
    // --------------------------------------------------
    cout << "---- Redundant Edge ----\n";

    vector<pair<int,int>> edges3 = {
        {1,2},{1,3},{2,3}
    };

    DSU dsu3(3);
    for(auto &e : edges3) {
        if(dsu3.find(e.first) == dsu3.find(e.second)) {
            cout << "Redundant Edge: "
                 << e.first << "-" << e.second << "\n";
        } else {
            dsu3.unionBySize(e.first, e.second);
        }
    }
    cout << "\n";

     // --------------------------------------------------
    // 4) KRUSKAL MST
    // --------------------------------------------------
    cout << "---- Kruskal MST ----\n";

    int n4=4;
    vector<tuple<int,int,int>>edges4={
        {1,0,1},{4,0,2},{3,1,2},{2,1,3},{5,2,3}
    };

    sort(edges4.begin(),edges4.end());

    DSU dsu4(n4);
    int mstCost=0;

    for(auto &[w,u,v]:edges4){
        if(dsu4.find(u)!=dsu4.find(v))
        {
            dsu4.unionBySize(u,v);
            mstCost+=w;
            cout<<"Edge in MST: "<<u<<"-"<<v
            <<"(wt="<<w<<")\n";
        }
    }
    
    cout << "Total MST Cost = " << mstCost << "\n\n";

     // --------------------------------------------------
    // 5) NUMBER OF ISLANDS (GRID -> DSU)
    // --------------------------------------------------
    cout << "---- Number of Islands ----\n";

     vector<vector<char>> grid = {
        {'1','1','0','0'},
        {'0','1','0','1'},
        {'1','0','0','1'},
        {'0','0','1','1'}
    };

    int R=grid.size(),C=grid[0].size();
    
    DSU dsu5(R*C);

    auto id=[&](int r,int c){
        return r*C+c;
    };

    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            if(grid[r][c]=='1'){
                if(r+1<R&&grid[r+1][c]=='1')
                    dsu5.unionBySize(id(r,c),id(r+1,c));
                if(c+1<C&&grid[r][c+1]=='1')
                   dsu5.unionBySize(id(r,c),id(r,c+1));
            }
        }
    }

    unordered_set<int>islands;
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            if(grid[r][c]=='1')
               islands.insert(dsu5.find(id(r,c)));
        }

    }
      cout << "Number of Islands = " << islands.size() << "\n";

    return 0;
}