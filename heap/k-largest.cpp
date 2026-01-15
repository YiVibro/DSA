//for max k declare min heap
//and check if size of q does not exceed k

#include<queue>
#include<iostream>

using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>arr={3, 5, 1, 2, 6, 4};
    int k=3;

    for(auto i:arr){
        pq.push(i);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    vector<int>ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}