#include<queue>
#include<iostream>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
};

struct cmp{
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};

ListNode* mergeKNodes(vector<ListNode*>&lists)
{
    priority_queue<ListNode*,vector<ListNode*>,cmp>pq;

    for(auto node:lists)
    pq.push(node);

    ListNode dummy(0);
    ListNode * tail= &dummy;
    
    while(!pq.empty())
    {
        auto node=pq.top();
        pq.pop();
        tail->next=node;
        tail=tail->next;

        if(node->next)pq.push(node->next);
    }
    return dummy.next;

}
int main()
{
   
}