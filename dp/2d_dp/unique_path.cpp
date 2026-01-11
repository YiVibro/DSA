#include <iostream>
#include <vector>
using namespace std;

// Recursive function with Memoization
int solve(int i, int j, vector<vector<int>>& dp) {
    if(i==0||j==0)return 1;

    if(dp[i][j]!=-1)return dp[i][j];

    if(i<0||j<0)return 0;

    int up=solve(i-1,j,dp);

    int left=solve(i,j-1,dp);

    return dp[i][j]=up+left;
}

int uniquePaths(int m, int n) {
    // Initialize 2D DP array with -1
    vector<vector<int>> dp(m, vector<int>(n, -1));
    
    // Start from the destination (m-1, n-1)
    return solve(m - 1, n - 1, dp);
}

int main() {
    int m =3, n = 3;
    cout << "Total Unique Paths: " << uniquePaths(m, n) << endl;
    return 0;
}