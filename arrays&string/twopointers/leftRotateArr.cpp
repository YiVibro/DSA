#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>&arr,int s,int l,int &revCount)
{
    int i=s,j=l;
    while(i<j)
    {
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
        i++;
        j--;
    }
    cout<<revCount<<": ";
    for(auto i:arr)cout<<i<<" ";
    cout<<endl;
    revCount++;
}

int main()
{
    vector<int>arr={1,2,3,4,5};
    int rotate=2;
    
    //using built in function
    //  reverse(arr.begin(),arr.begin()+rotate);
    // reverse(arr.begin()+rotate,arr.end());
    // reverse(arr.begin(),arr.end());
    // for(auto i:arr)
    // {
    //     cout<<i<<" ";
    // }

  //using function
  int revCount=1;
    reverse(arr,0,rotate-1,revCount);
    reverse(arr,rotate,arr.size()-1,revCount);
    reverse(arr,0,arr.size()-1,revCount);
    
}