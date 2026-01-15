#include<bits/stdc++.h>
using namespace std;

bool solve(int target,vector<int>&set,int n, vector<vector<int>>&dp)
{
    if(target==0)return true;
    if(n==0)return (set[0]==target);
    if(dp[n][target]!=-1)return dp[n][target];
    bool select=solve(target-set[n],set,n-1);

    bool notSelect=false;
    if(target<=set[n])
    {
        notSelect=solve(target,set,n-1);
    }

    return dp[n][target]=(select||notSelect);
}
int main()
{
    vector<int>set={1,5,11,5};
    int target=7;
    int n=set.size();
    vector<vector<int>>dp(n+1,vector<int>(target,-1));
    cout<<"Target exists: "<<solve(target,set,n-1,dp)<<endl;
}