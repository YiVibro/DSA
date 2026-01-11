#include<bits/stdc++.h>
using namespace std;

int solve(int day,int last_task,vector<vector<int>>&points,vector<vector<int>>&dp)
{
    //for day 0 choose maximum task
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=last_task)
            {
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last_task]!=-1)return dp[day][last_task];

    int maxi=0;
    //try all the tasks
    for(int task=0;task<3;task++)
    {
        if(task!=last_task)
        {
            int activity=points[day][task]+solve(day-1,task,points,dp);
            maxi=max(maxi,activity);
        }
    }
    return dp[day][last_task]=maxi;
}

int ninjaTraining(int days,vector<vector<int>>&points)
{
    vector<vector<int>>dp(days,vector<int>(4,-1));

    return solve(days-1,3,points,dp);
}

int main() {
    // Points for [Day 0, Day 1, Day 2]
    // Each row has points for [Task 0, Task 1, Task 2]
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    
    int n = points.size();
    cout << "Max Points: " << ninjaTraining(n, points) << endl;
    return 0;
}