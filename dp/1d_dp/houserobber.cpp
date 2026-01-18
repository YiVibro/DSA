#include<bits/stdc++.h>
using namespace std;

int houserobber(vector<int>&arr,int n,vector<int>&memo)
{
    if(n==0)return arr[0];
    if (n<=0)return 0;
    if(memo[n]!=-1)return memo[n];
    return memo[n]=max(arr[n]+houserobber(arr,n-2),houserobber(arr,n-1));
}
int main()
{
   vector<int>arr={30,70,30};
   vector<int>memo(arr.size(),-1);
   cout<<houserobber(arr,2,memo);
}