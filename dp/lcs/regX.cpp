#include<bits/stdc++.h>
using namespace std;

bool solve(int m,int n,string s,string p,vector<vector<int>> &dp)
{
    if(m<0&&n<n)return true;

    if(m>=0&&n<0)return false;

    if(m<0&&n>=0)
    {
        for(int k=0;k<=n;k++)
        {
            if(p[k]!='*')return 0;
        }
        return 1;
    }

    if(p[n]=='?'||s[m]==p[n]){
        return dp[m][n]=solve(m+1,n+1,s,p,dp);
    }
    if (dp[m][n] != -1) return dp[n][n];

    if(p[n]=='*'){
        return dp[m][n]=solve(m,n-1,s,p,dp)||solve(m-1,n,s,p,dp);
    }
    return dp[m][n]=0;
}
bool regX(string s,string p)
{
    int m=s.length();
    int n=s.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(m-1,n-1,s,p,dp);
}
int main()
{
    string s="hello";
    string p="h*o";

   cout<<regX(s,p);
    return 0;
}