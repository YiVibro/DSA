#include "Tree.h"

int height(Node * root)
{
    if(root==nullptr)return 0;

    int leftH=height(root->left);
    int rightH=height(root->right);

    return 1+max(leftH,rightH);
}
int main()
{
     Node *root=new Node(45);
    root->left=new Node(30);
    root->right=new Node(50);
    root->left->left=new Node(90);
    root->left->right=new Node(20);
    root->right->left=new Node(69);
    root->right->right=new Node(86);
    cout<<height(root);
    
    
}