#include<bits/stdc++.h>
using namespace std;

int solve(int i,vector<int>&arr,vector<int>&dp)
{
    if(i==0)
    {
        return 0;
    }
    if(dp[i]!=-1)return dp[i];

    int one=solve(i-1,arr,dp)+abs(arr[i]-arr[i-1]);

    int two=INT_MAX;

    if(i>1){
        two=solve(i-1,arr,dp)+abs(arr[i]-arr[i-2]);
    }
    return dp[i]=min(one,two);
}

int main()
{
    vector<int>arr={10,20,30,10};
    vector<int>dp(arr.size(),-1);
    cout<<solve(arr.size()-1,arr,dp);
}