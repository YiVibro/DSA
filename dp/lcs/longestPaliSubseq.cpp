#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// solve(i, j) -> Returns LCS length for s1[0...i] and s2[0...j]
int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    // Base Case: If either string runs out, LCS is 0
    if (i < 0 || j < 0) return 0;

    // Memoization
    if (dp[i][j] != -1) return dp[i][j];

    // Case 1: Match
    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
    }

    // Case 2: No Match
    // Try shortening s1 OR shortening s2, take the max
    return dp[i][j] = max(solve(i - 1, j, s1, s2, dp), 
                          solve(i, j - 1, s1, s2, dp));
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
    string s2 = s1;
reverse(s1.begin(),s1.end());
    cout<<s1<<" "<<s2<<endl;

    cout << "LCS Length: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}


