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

int maxLevelSum(TreeNode *root);

int main()
{
    TreeNode *root = new TreeNode(-100);
    TreeNode *a = new TreeNode(-200);
    TreeNode *b = new TreeNode(-300);
    TreeNode *c = new TreeNode(-20);
    TreeNode *d = new TreeNode(-5);
    TreeNode *e = new TreeNode(-10);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;

    cout<<maxLevelSum(root)<<endl;


    return 0;
}


int maxLevelSum(TreeNode *root)
{
    pair<long long int,int>maxSumAndLevel = {INT_MIN, 0};
    queue<pair<TreeNode*,int> >q;
    int currentLevel = 0;
    long long int currentLevelSum = numeric_limits<long long int>::min();


    if(root != nullptr)
    {
        q.push({root,1});
    }

    while(!q.empty())
    {
        pair<TreeNode*, int> p = q.front();
        q.pop();

        if(currentLevel == p.second)
        {
            currentLevelSum += (long long int)p.first->value;

        }
        else if(p.second > currentLevel)
        {
            if(currentLevelSum > maxSumAndLevel.first)
            {
                maxSumAndLevel.first = currentLevelSum;
                maxSumAndLevel.second = currentLevel;
            }
            currentLevel = p.second;
            currentLevelSum = (long long int)p.first->value;

        }

        if(p.first->left != nullptr)
        {
            q.push({p.first->left, p.second + 1});
        }
        if(p.first->right != nullptr)
        {
            q.push({p.first->right, p.second + 1});
        }

    }

    if(currentLevelSum > maxSumAndLevel.first)
    {
        maxSumAndLevel.first = currentLevelSum;
        maxSumAndLevel.second = currentLevel;
    }

    return maxSumAndLevel.second;

}
