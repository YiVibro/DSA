#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX
using namespace std;

int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // Base Case 1: Reached the start (0,0)
    // We must return the value of this cell so it gets added to the total sum.
    if (i == 0 && j == 0) return grid[0][0];

    // Base Case 2: Out of bounds
    // Return a huge value so this path is ignored by min().
    if (i < 0 || j < 0) return 1e9; // Using 1e9 to avoid overflow when adding grid[i][j]

    // Memoization Check
    if (dp[i][j] != -1) return dp[i][j];

    // Transitions
    int up = solve(i - 1, j, grid, dp);
    int left = solve(i, j - 1, grid, dp);

    // Store and Return
    // We add current cell's cost to the minimum of the previous options
    return dp[i][j] = grid[i][j] + min(up, left);
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    
    return solve(m - 1, n - 1, grid, dp);
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Minimum Path Cost: " << minPathSum(grid) << endl;
    return 0;
}