#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<int>arr={1,2,4,5,6,9,80};
    int target=4;
    int low=0;
    int high=arr.size();
    bool found=false;
    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(arr[mid]==target){
            found=true;
            break;
        }
        else if(arr[mid]<target)
        {
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    if(found){
        cout<<"Found "<<endl;
    }else{
        cout<<"Target Not Found! "<<endl;

    }
}
