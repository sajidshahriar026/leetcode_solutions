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

int pathSum(TreeNode *root, int targetSum);
void calculatePathSum(TreeNode *root, int targetSum, int &ans, long long int currentSum, map<long long int, int> &prefixSum);


int main()
{
    TreeNode *root = new TreeNode(1e9);
    TreeNode *a = new TreeNode(1e9);
    TreeNode *b = new TreeNode(294967296);
    TreeNode *c = new TreeNode(1e9);
    TreeNode *d = new TreeNode(1e9);
    TreeNode *e = new TreeNode(1e9);
//    TreeNode *f = new TreeNode(3);
//    TreeNode *g = new TreeNode(-2);
//    TreeNode *h = new TreeNode(1);

    root->left = a;
//    root->right = b;

    a->left = b;
//    a->right = d;

    b->left = c;

    c->left = d;
//    c->right = g;

    d->left = e;

    int ans = pathSum(root, 0);


    cout<<"\n\n\n\n\n\nFinalAnswer: "<<ans<<endl;

}

int pathSum(TreeNode *root, int targetSum)
{
    int ans = 0;
    map<long long int,int>prefixSum;

    calculatePathSum(root, targetSum, ans, 0, prefixSum);

    return ans;
}


void calculatePathSum(TreeNode *root, int targetSum, int &ans,long long  int currentSum, map<long long int,int> &prefixSum)
{
    if(root == nullptr)
    {
        return;
    }


    currentSum += (long long int)root->value;

    if(currentSum == targetSum)
    {
        ans++;
    }

    if(prefixSum.find(currentSum-targetSum) != prefixSum.end())
    {
        ans += prefixSum[currentSum-targetSum];
    }

    if(prefixSum.find(currentSum)!=prefixSum.end())
    {
        prefixSum[currentSum]++;
    }
    else
    {
        prefixSum[currentSum] = 1;
    }

//    cout<<"current Node: "<< root->value<<endl;
//    cout<<"Current currentSum :"<<currentSum<<endl;
//    cout<<"current answer: "<< ans<< endl;
//
//    cout<<"Prefix Dict: "<<endl;
//    for(auto i=prefixSum.begin();i!=prefixSum.end();i++)
//    {
//        cout<<i->first<<' '<<i->second<<endl;
//    }

    calculatePathSum(root->left, targetSum, ans, currentSum, prefixSum);
    calculatePathSum(root->right, targetSum, ans, currentSum, prefixSum);

    prefixSum[currentSum]--;
    currentSum -= root->value;
}
