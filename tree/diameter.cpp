

int diameter(Node*root,int &maxDia)
{
    if(root==nullptr)return 0;

    int leftH=diameter(root->left,maxDia);
    int rightH=diameter(root->right,maxDia);

    maxDia=max(maxDia,leftH+rightH);

    return 1+max(leftH,rightH);
}