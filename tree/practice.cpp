#include "Tree.h"


void inorderIterative(Node * root)
{
    Node * cur=root;
    stakc<Node*>st;
    while(cur!=nullptr||!st.empty())
    {
        while(cur!=nullptr)
        {
            st.push(cur);
            cur=cur->left;
        }

        cur=st.top();
        cout<<cur->val<<" ";
        st.pop();

        cur=cur->right;
    }
}

void preorder(Node* root)
{if (root == NULL) return;
    stack<Node*>st;

    st.push(root);
    while(!st.empty())
    {
        Node * cur=st.top();
        st.pop();

        cout<<cur->val<<" ";
       
        if(cur->right)
        st.push(root->right);

        if(cur->left)
        st.push(root->left);
    }
}

void postorderIterative(Node* root) {
    if (root == NULL) return;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left)
            st1.push(curr->left);
        if (curr->right)
            st1.push(curr->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void postorderOneStack(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    Node* lastVisited = NULL;

    while (curr != NULL || !st.empty()) {
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        } else {
            Node* peek = st.top();
            if (peek->right != NULL && lastVisited != peek->right) {
                curr = peek->right;
            } else {
                cout << peek->data << " ";
                lastVisited = peek;
                st.pop();
            }
        }
    }
}

void levelOrder(Node* root)
{
    if(root==nullptr)return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node * cur=q.top();
        q.pop();

        cout<<cur->val<<" ";

        if(root->left)
            q.push(q->left);
        if(root->right)
            q.push(q->right);
    }
}

void levelOrderByLine(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();   // number of nodes in current level

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl; // new level
    }
}

int main()
{
    Node *root=new Node(45);
    root->left=new Node(30);
    root->right=new Node(50);
    root->left->left=new Node(90);
    inorder(root);
}