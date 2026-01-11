#include <iostream>
#include <vector>
using namespace std;

// solve(ind, target) -> Returns true (1) if target can be made using indices 0...ind
int solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Case 1: Target achieved
    if (target == 0) return 1;

    // Base Case 2: Only one element left
    if (ind == 0) return (arr[0] == target);

    // Memoization Check
    if (dp[ind][target] != -1) return dp[ind][target];

    // Choice 1: Not Pick
    // We skip the current element and try to find the target in the remaining array
    bool notTaken = solve(ind - 1, target, arr, dp);

    // Choice 2: Pick
    bool taken = false;
    if (arr[ind] <= target) {
        // We pick the element, reduce the target, and look in the remaining array
        taken = solve(ind - 1, target - arr[ind], arr, dp);
    }

    // Store and Return (using OR because we just need ONE valid path)
    return dp[ind][target] = (notTaken || taken);
}

bool subsetSumToK(int n, int k, vector<int>& arr) {
    // DP Table: Size [n][k+1]
    // Initialize with -1
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    
    return solve(n - 1, k, arr, dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "Subset with sum " << k << " exists." << endl;
    else
        cout << "Subset does not exist." << endl;

    return 0;
}