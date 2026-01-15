#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m,string text1,string text2,vector<vector<int>> &dp)
{
    if(i<0||j<0)return 0;
   if (dp[i][j] != -1) return dp[i][j];
    
   if(string[n]==string[m]){
     return 1+solve(n-1,m-1,text1,text2,dp);
   }
   return max(
    solve(n,m-1,text1,text2,dp),
     solve(n-1,m,text1,text2,dp),
   )

}

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    
    // DP Table size [n][m]
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    return solve(n - 1, m - 1, text1, text2, dp);
}

int main() {
    string s1 = "abcde";
    string s2 = reverse(s1.begin(),s1.end());
    cout << "LCS Length: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}