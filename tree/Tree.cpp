#include "Tree.h"

Node::Node(int v){
    val=v;
    left=nullptr;
    right=nullptr;
};

void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);       // Left
    cout << root->val << " ";  // Root
    inorder(root->right);      // Right
}

void  preorder(Node * root)
{
    if(root==nullptr)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void  postorder(Node * root)
{
    if(root==nullptr)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}