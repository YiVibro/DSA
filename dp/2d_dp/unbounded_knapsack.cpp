#include<bits/stdc++.h>
using namespace std;

int solve(int n, int weight, vector<int>& wt, vector<int>& val,
          vector<vector<int>>& dp)
{
    if (n == 0) {
        return (weight / wt[0]) * val[0];
    }

    if (dp[n][weight] != -1)
        return dp[n][weight];

    int not_select = solve(n - 1, weight, wt, val, dp);

    int select = 0;
    if (wt[n] <= weight) {
        select = val[n] + solve(n, weight - wt[n], wt, val, dp);
    }

    return dp[n][weight] = max(select, not_select);
}

int knapsack(vector<int>& wt, vector<int>& val, int maxWeight)
{
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(n - 1, maxWeight, wt, val, dp);
}

int main() {
    vector<int> wt = {3, 2, 5};
    vector<int> val = {30, 40, 60};
    int W = 4;

    cout << "Max Value: " << knapsack(wt, val, W) << endl;
}
