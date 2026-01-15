#include <iostream>
#include <vector>
using namespace std;

// solve(ind, target) -> Returns the NUMBER OF WAYS to form 'target' using indices 0...ind
int solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Case 1: If target is 0, we found 1 valid way (the empty set)
    // Note: This base case only works if array elements are strictly positive (>0)
    if (target == 0) return 1;

    // Base Case 2: Only one element left
    if (ind == 0) {
        return (arr[0] == target) ? 1 : 0;
    }

    // Memoization
    if (dp[ind][target] != -1) return dp[ind][target];

    // Choice 1: Not Pick
    int notPick = solve(ind - 1, target, arr, dp);

    // Choice 2: Pick
    int pick = 0;
    if (arr[ind] <= target) {
        pick = solve(ind - 1, target - arr[ind], arr, dp);
    }

    // Store and Return the SUM of ways
    return dp[ind][target] = pick + notPick;
}

int findWays(vector<int>& num, int k) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, num, dp);
}

int main() {
    vector<int> arr = {1, 2, 2, 3}; 
    int k = 3;
    // Ways: {1, 2}, {1, 2} (second 2), {3} -> Total 3 ways
    cout << "Total ways: " << findWays(arr, k) << endl;
    return 0;
}