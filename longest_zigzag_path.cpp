#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): value(0),left(nullptr),right(nullptr){}
    TreeNode(int value): value(value), left(nullptr), right(nullptr){}
    TreeNode(int value, TreeNode *left, TreeNode *right): value(value), left(left), right(right){}
};


int longestZigZagPath(TreeNode *root);

void calculateLongestZigZagPath(TreeNode *root, int l, int r, int &maxLength);



int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(1);
    TreeNode *c = new TreeNode(1);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(1);
    TreeNode *f = new TreeNode(1);
    TreeNode *g = new TreeNode(1);

    root->right = a;

    a->left = b;
    a->right = c;

    c->left = d;
    c->right=e;

    d->right = f;

    f->right = g;

    cout<<longestZigZagPath(root)<<endl;

}


int longestZigZagPath(TreeNode *root)
{

    int maxLength = 0;

    calculateLongestZigZagPath(root,0,0,maxLength);

    return maxLength;
}

void calculateLongestZigZagPath(TreeNode *root,int l, int r, int &maxLength)
{
    if(root == nullptr)
    {
        return;
    }

    maxLength = max(max(l,r),maxLength);

    calculateLongestZigZagPath(root->left, r+1, 0, maxLength);
    calculateLongestZigZagPath(root->right, 0, l+1, maxLength);
}
