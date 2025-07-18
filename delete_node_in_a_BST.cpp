#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* deleteNode(TreeNode *root, int key);
TreeNode* findMin(TreeNode *root);

int main()
{
    return 0;
}

TreeNode* deleteNode(TreeNode *root, int key)
{
    if(root==nullptr)
    {
        return root;
    }

    if(root->val > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(root->val < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        //leaf node
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
        }
        //one subtree
        else if(root->left == nullptr)
        {
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == nullptr)
        {
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }
        //two subtree
        else
        {
            TreeNode *rightMin = findMin(root->right);
            root->val = rightMin->val;
            root->right = deleteNode(root->right, rightMin->val);
        }

    }
    return root;

}

TreeNode* findMin(TreeNode *root)
{

    if(root == nullptr)
    {
        return nullptr;
    }

    TreeNode *currentNode = root;

    while(currentNode->left != nullptr)
    {
        currentNode = currentNode->left;
    }
    return currentNode;

}
