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

TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
bool pathToNode(TreeNode *root, TreeNode* p, vector<TreeNode*>&path);


TreeNode* lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q);


int main()
{
//    TreeNode *root = new TreeNode(1e9);
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(5);
    TreeNode *c = new TreeNode(1);
    TreeNode *d = new TreeNode(6);
    TreeNode *e = new TreeNode(2);
    TreeNode *f = new TreeNode(0);
    TreeNode *g = new TreeNode(8);
    TreeNode *h = new TreeNode(7);
    TreeNode *i = new TreeNode(4);

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    e->left = h;
    e->right = i;

    TreeNode *lca = lowestCommonAncestor(a,b,i);
    cout<<lca->value<<endl;


    TreeNode *lca2 = lowestCommonAncestor2(a,b,i);
    cout<<lca2->value<<endl;

    return 0;

}


TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode*>path1;
    vector<TreeNode*>path2;

    bool isPathForPFound = pathToNode(root,p,path1);
    bool isPathForQFound = pathToNode(root,q,path2);

    if(!isPathForPFound || !isPathForQFound)
    {
        return nullptr;
    }
    else
    {
        int pathLength1 = path1.size();
        int pathLength2 = path2.size();

//        cout<<"Path 1: "<<endl;
//        for(auto j=0;j<pathLength1;j++)
//        {
//            cout<<path1[j]->value<<' ';
//        }
//        cout<<endl;
//
//        cout<<"Path 2: "<<endl;
//        for(auto j = 0;j<pathLength2;j++)
//        {
//            cout<<path2[j]->value<<' ';
//        }
//        cout<<endl;

        int i;
        for(i = 0; i < pathLength1 && i < pathLength2; i++)
        {
            if(path1[i]!=path2[i])
            {
                break;
            }
        }

        return path1[i-1];


    }
}

bool pathToNode(TreeNode *root, TreeNode *t, vector<TreeNode*> &path)
{
    if(root == nullptr)
    {
        return false;
    }

    path.push_back(root);

    if(root == t)
    {
        return true;
    }

    bool isNodeFoundInTheLeftSubtree = pathToNode(root->left,t,path);
    bool isNodeFoundInTheRightSubtree = pathToNode(root->right,t,path);

    if(isNodeFoundInTheLeftSubtree || isNodeFoundInTheRightSubtree)
    {
        return true;
    }

    path.pop_back();

    return false;


}


TreeNode* lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    if(root->value == p->value || root->value == q->value)
    {
        return root;
    }

    TreeNode* leftLCA = lowestCommonAncestor2(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor2(root->right, p, q);

    if(leftLCA != nullptr && rightLCA != nullptr)
    {
        return root;
    }

    return (leftLCA != nullptr) ? leftLCA : rightLCA;
}
