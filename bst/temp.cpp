// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
struct Node{
  int val;
  Node*left;
  Node*right;
  
  Node(int val):val(val),left(nullptr),right(nullptr){}
};

void inorder(Node * root)
{
    if(root==nullptr)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void leftview(Node * root)
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
       
        
        for(int i=0;i<size;i++)
        {
             Node* curr=q.front();
        q.pop();
            if(i==0)cout<<curr->val<<" ";
            if(curr->left)
             q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    cout<<endl;
}

void rightview(Node * root)
{
    if(root==nullptr)return ;
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        int size=q.size();
        
        for(int i=1;i<=size;i++)
        {
            Node * curr=q.front();
            q.pop();
            if(i==size)cout<<curr->val<<" ";
            
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
    }
    cout<<endl;
}

void topView(Node* root) {
    if (!root) return;

    map<int, int> mp; // HD → node value
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();

        if (mp.find(hd) == mp.end())
            mp[hd] = node->val;

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto x : mp)
        cout << x.second << " ";
}

void insert(Node * &root,int val)
{
    if(root==nullptr)
    {
        root=new Node(val);
        return;
    }
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        Node * cur=q.front();
        q.pop();
        if(!cur->left){
            cur->left=new Node(val);
            return;
        }
        if(!cur->right){
            cur->right=new Node(val);
            return;
        }
        q.push(cur->left);
        q.push(cur->right);
    }
    
}

Node* insertByreturningRoot(Node* root, int val)
{
    if (root == nullptr)
        return new Node(val);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (!cur->left) {
            cur->left = new Node(val);
            return root;
        }
        if (!cur->right) {
            cur->right = new Node(val);
            return root;
        }

        q.push(cur->left);
        q.push(cur->right);
    }
    return root;
}

int main() {
//   Node * root=new Node(1);
//   root->left=new Node(2);
//   root->right=new Node(3);
//   root->left->right=new Node(4);
//   root->right->right=new Node(5);
//   root->right->right->left=new Node(6);
   
   //inorder(root);
   
   //leftview(root);
   //rightview(root);
   //topView(root);
   Node*root=nullptr;
   insert(root,2);
   insert(root,3);
   insert(root,4);
   insert(root,5);
   inorder(root);
}