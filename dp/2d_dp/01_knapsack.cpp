#include<bits/stdc++.h>
using namespace std;

int solve(int n,int weight,vector<int>& wt, vector<int>& val,vector<vector<int>>&dp)
{
    if(n==0){
        if(weight<=wt[0])
        {
            return val[0];
        }
        return 0;
    }

    int select=solve(n-1,weight-wt[n],wt,val,dp);

    int not_select=INT_MIN;
    if(wt[n]<=weight){
       not_select=solve(n-1,weight,wt,val,dp);
    }
    return max(select+val[n],not_select);
}
int knapsack(vector<int>& wt, vector<int>& val, int n, int maxWeight) {
    // DP Table: Size [n][maxWeight + 1]
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    
    return solve(n - 1, maxWeight, wt, val, dp);
}

int main() {
    vector<int> wt = {3, 2, 5};
    vector<int> val = {30, 40, 60};
    int W = 6;
    int n = wt.size();
    
    cout << "Max Value: " << knapsack(wt, val, n, W) << endl;
    return 0;
}