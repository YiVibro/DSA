#ifndef TREE_H
#define TREE_H

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v);
};

void inorder(Node* root);
void preorder(Node * root);
void postorder(Node * root);

#endif