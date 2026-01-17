#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    
    Node(int v) { // Renamed parameter to 'v' to avoid shadowing
        val = v;
        left = nullptr;
        right = nullptr;
    }
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
    postrder(root->left);
    postrder(root->right);
    cout<<root->val<<" ";
}

int main() {
    Node *root = new Node(20);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(50);
    root->left->right = new Node(60);

    cout << "In-order Traversal: ";
    inorder(root); 
    return 0;
}
