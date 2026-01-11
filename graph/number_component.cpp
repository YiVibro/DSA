class Solution {
public:
    void bfs(int src,vector<vector<int>>&grd,vector<bool>&vis)
    {   int n=grd.size();
        queue<int>q;
        vis[src]=true;
        q.push(src);

        while(!q.empty())
        {
            int u=q.front();
            q.pop();

            //scan for all nodes
            for(int v=0;v<n;v++)
            {
                if(grd[u][v]==1&&!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        int count=0;
       for(int i=0;i<n;i++)
       {
        if(!vis[i])
        {
             bfs(i,isConnected,vis);
             count++;
        }
       
       } 
       return count;
    }
};