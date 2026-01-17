//sub array with given sum
//the elements must be in comtinous order
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>arr={3,2,0,4,7};
    int csum=0;
    int sum=6;
    for(int i=0;i<arr.size()-1;i++)
    {
      csum=0;
      for(int j=i;j<arr.size();j++)
      {
          csum+=arr[j];
          if(sum==csum)return true;
      }
    }
    cout<<"False";
    return 0;
}

//suing two pointer
