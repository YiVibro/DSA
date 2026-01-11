#include <iostream>
#include <vector>
#include <algorithm> // for max function

using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    
    // Base Case: If no items are left or capacity is 0
    if (n == 0 || W == 0) {
        return 0;
    }

    // If weight of the nth item is more than Knapsack capacity W,
    // it cannot be included in the optimal solution.
    if (wt[n - 1] > W) {
        return knapsack(W, wt, val, n - 1);
    }

    // Return the maximum of two cases:
    // 1. (Include) val[nth item] + max value from remaining capacity
    // 2. (Exclude) max value from remaining items with same capacity
    else {
        return max(
            val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), // Include
            knapsack(W, wt, val, n - 1)                           // Exclude
        );
    }
}

int main() {
    vector<int> val = {60, 100, 120}; // Values of items
    vector<int> wt = {10, 20, 30};    // Weights of items
    int W = 50;                       // Max capacity of knapsack
    int n = val.size();               // Number of items

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;

    return 0;
}