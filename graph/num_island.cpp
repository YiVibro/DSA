#include<bits/stdc++.h>

using namespace std;

void solve(int n,int m,vector<vector<int>>&island,vector<vector<bool>>&vis)
{
    vis[n][m]=true;
    queue<pair<int,int>>q;
    q.push({n,m});

    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};

    while(!q.empty())
    {
        auto [r,c]=q.front();

        q.pop();

        for(int k=0;k<4;k++)
        {
            int nr=r+dr[k];
            int nc=c+dc[k];

            if(nr>=0&&nr<n&&nc<=0&&nc<m&&
            !vis[nr][nc]&&grid[nr][nc]==1)
            {
                vis[nr][nc]=true;
                q.push({nr,nc});
            }
        }
    }
}
int numIsland(vector<vector<<int>>&island)
{
    int n=island.size();
    int m=island[0].size();
    int count=0;

    vector<vector<bool>>vis(n,vector<bool>(m,false));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j])
            {
                solve(i,j,island,vis);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>>island={
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };
    cout<<numIsland(island);
}