#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(): value(0),left(nullptr),right(nullptr) {}
    TreeNode(int value): value(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode *left, TreeNode *right): value(value), left(left), right(right) {}
};

vector<int>rightSideView(TreeNode* root);


int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *a = new TreeNode(2);
    TreeNode *b = new TreeNode(3);
    TreeNode *c = new TreeNode(4);
    TreeNode *d = new TreeNode(5);

    root->left = a;
    root->right = b;

//    a->right = d;
    a->left = c;

//
    b->right = c;

    vector<int>rightSideNodes = rightSideView(root);

    for(auto i=rightSideNodes.begin();i!=rightSideNodes.end();i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;

    return 0;


}

vector<int>rightSideView(TreeNode* root)
{
    queue<pair<TreeNode*, int> >fringe;
    vector<int>rightSideNodes;

    if(root!= nullptr)
    {
        fringe.push({root, 0});
    }

    int currentLevel = -1;

    while(!fringe.empty())
    {
        pair<TreeNode*, int> p = fringe.front();
        fringe.pop();


        if(p.second > currentLevel)
        {
            currentLevel = p.second;
            rightSideNodes.push_back(p.first->value);
        }

        if(p.first->right != nullptr)
        {
            fringe.push({p.first->right, p.second + 1});
        }
        if(p.first->left != nullptr)
        {
            fringe.push({p.first->left, p.second + 1});
        }
    }

    return rightSideNodes;
}
