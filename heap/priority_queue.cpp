//priority_queue<T>
//It always keeps the highest priority element at the top.
//By default → MAX HEAP

#include <queue>
#include <iostream>
using namespace std;

int main() {
    // priority_queue<int> pq;

    // pq.push(10);
    // pq.push(30);
    // pq.push(20);

    // cout <<"Max heap "<< pq.top()<<endl; 
    //min heap

    // priority_queue<int,vector<int>,greater<int>>pq;
    //   pq.push(10);
    // pq.push(30);
    // pq.push(20);
    //  cout <<"Min heap "<< pq.top()<<endl; 

     //max heap by first element 
    //  priority_queue<pair<int,int>>pq;
    //  pq.push({10,20});
    //  pq.push({20,30});
    //  pq.push({1,20});

    //  cout<<"Max heap: "<<pq.top().first<<endl;

    //min heap by first
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    //   pq.push({10,20});
    //  pq.push({20,30});
    //  pq.push({1,20});

    //  cout<<"Max heap: "<<pq.top().first<<endl;

    //custom comparator
    //min heap based on second value
    struct cmp{
        bool operator()(pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    
        pq.push({10,2});
     pq.push({20,30});
     pq.push({1,20});

     cout<<"Max heap: "<<pq.top().second<<endl;


}
