/*
Input: Two strings, S1 ("horse") and S2 ("ros").

Goal: Find the minimum number of operations required to convert S1 into S2.

Allowed Operations:

Insert a character.
Delete a character.
Replace a character. */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// solve(i, j) -> Min ops to convert S1[0...i] to S2[0...j]
int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    // Base Case 1: S1 is exhausted (i < 0)
    // If S1 is empty, we must INSERT all remaining characters of S2.
    // Remaining S2 characters = j + 1
    if (i < 0) return j + 1;

    // Base Case 2: S2 is exhausted (j < 0)
    // If S2 is empty, we must DELETE all remaining characters of S1.
    // Remaining S1 characters = i + 1
    if (j < 0) return i + 1;

    // Memoization
    if (dp[i][j] != -1) return dp[i][j];

    // Case 1: Match
    if (s1[i] == s2[j]) {
        return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
    }

    // Case 2: No Match (Try all 3 ops)
    int insertOp = 1 + solve(i, j - 1, s1, s2, dp);
    int deleteOp = 1 + solve(i - 1, j, s1, s2, dp);
    int replaceOp = 1 + solve(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = min({insertOp, deleteOp, replaceOp});
}

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, word1, word2, dp);
}

int main() {
    string s1 = "horse";
    string s2 = "ros";
    // horse -> rorse (Replace 'h' with 'r')
    // rorse -> rose (Delete 'r')
    // rose -> ros (Delete 'e')
    // Result: 3
    cout << "Min Operations: " << minDistance(s1, s2) << endl;
    return 0;
}