//this uses fixed size window

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum=0;
        for(int i=0;i<k;i++)sum+=nums[i];
        
        long long maxSum=sum;
        for(int i=k;i<nums.size();i++)
        {  
             sum=sum-nums[i-k]+nums[i];
            maxSum=max(maxSum,sum);
        }
        return (double)maxSum/k;
    }
};

int main()
{
  Solution s;
  vector<int>arr={1,2,5,3,4,6};
  int k=4;
  double res=s.findMaxAverage(arr,k);
  return res;
}