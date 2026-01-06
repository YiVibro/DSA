#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int helper(string &s1,string &s2,int m,int n)
{
  if(m==0||n==0)return 0;
  
  if(dp[m][n]!=-1)return dp[m][n];
  
  if(s1[m-1]==s2[n-1])
  {
      dp[m][n]= 1+helper(s1,s2,m-1,n-1);
  }
  else {
      dp[m][n]=max(helper(s1,s2,m-1,n),helper(s1,s2,m,n-1));
  }
  return dp[m][n];
}

int main()
{
    string s1="Hello";
    string s2="helllows";
    
    memset(dp,-1,sizeof(dp));
    
    int m=s1.length();
    int n=s2.length();
    cout<<helper(s1,s2,m,n);
}