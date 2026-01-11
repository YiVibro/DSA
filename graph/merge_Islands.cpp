#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b){
        int pa=find(a), pb=find(b);
        if(pa==pb) return false;

        if(size[pa]<size[pb]){
            parent[pa]=pb;
            size[pb]+=size[pa];
        }else{
            parent[pb]=pa;
            size[pa]+=size[pb];
        }
        return true;
    }
};

int main(){

    int R = 3, C = 3;

    vector<pair<int,int>> queries = {
        {0,0},{0,1},{1,2},{2,1},{1,1}
    };

    DSU dsu(R*C);
    vector<vector<bool>> land(R, vector<bool>(C,false));

    auto id = [&](int r,int c){
        return r*C + c;
    };

    int islands = 0;

    vector<int> dr = {1,-1,0,0};
    vector<int> dc = {0,0,1,-1};

    cout << "Island counts after each add:\n";

    for(auto &q:queries){
        int r=q.first, c=q.second;

        if(land[r][c]){
            cout << islands << " ";
            continue;
        }

        land[r][c]=true;
        islands++;

        int curr = id(r,c);

        for(int k=0;k<4;k++){
            int nr=r+dr[k], nc=c+dc[k];
            if(nr>=0 && nr<R && nc>=0 && nc<C && land[nr][nc]){
                if(dsu.unite(curr, id(nr,nc))){
                    islands--; // merged two islands
                }
            }
        }

        cout << islands << " ";
    }

    cout << "\n";
    return 0;
}
