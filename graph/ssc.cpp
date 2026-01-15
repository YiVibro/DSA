//storongly connected components
//kosarajus algo
//questions-->finds out number of scc and print scc
//scc--->only valid for directed graphs
//for any pair of vertices in a graph if you can go from one to the
//other then it is strongly connected

//how it works
//first reverse all the edges
//then you will get components which are not rechable
//reversal will still keep scc
///starting time
//finishing time
//algo
//1)sort all the edges accor t finishing time(dfs)
//2)reverse the graph
//3)do dfs

void dfs(int i,vector<int>&vis,vector<int>&adj[],stack<int>&st)
{
    vis[i]=1;
    for(auto neig:adj[i])
    {
        if(!vis[neig])
        {
            dfs(neig,vis,adj,st);
        }
    }
    st.push(neig);
}

void dfs3(int node,vector<int>&vis,vector<int>&adjT[])
{
    vis[node]=true;
    
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs3(it,vis,adjT);
        }
    }
}
int kosaraju(int V,vector<int>adj[])
{
    //s1--sort all the nodes accr to finishing time
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,st);
        }
    }

    //s2--reverse the graph
    vector<int>adjT[V];
    for(int i=0;i<V;i++)
    {
        vis[i]=0;
        for(auto it:adj[i])
        {
            //i-->it
            //we need it-->i
            adjT[it].push_back(i);
        }
    }

    //s3)call dfs
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            scc++;
            dfs3(node,vis,adjT);
        }
    }
    return scc;
}