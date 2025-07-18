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


bool isBinarySearchTree(TreeNode *root);
bool isSubTreeGreater(TreeNode *root, int value);
bool isSubTreeLesser(TreeNode *root, int value);


bool isBinarySearchTreeEfficient(TreeNode *root);
bool isBinarySearchTreeUtil(TreeNode *root, int minValue, int maxValue);


TreeNode* createNewBSTNode(int value);
TreeNode* add(TreeNode* root, int value);




int main()
{
    TreeNode *root1 = new TreeNode(11);
    TreeNode *a1 = new TreeNode(69);
    TreeNode *b1= new TreeNode(60);
    TreeNode *c1 = new TreeNode(115);
    TreeNode *d1 = new TreeNode(66);
    TreeNode *e1 = new TreeNode(15);
    TreeNode *f1 = new TreeNode(60);
    TreeNode *g1 = new TreeNode(67);
    TreeNode *h1 = new TreeNode(74);
    TreeNode *i1 = new TreeNode(76);

    root1->left = a1;
    root1->right= b1;

    a1->left = c1;
    a1->right = d1;

    b1->left = e1;
    b1->right =f1;

    c1->left = g1;
    c1->right = h1;

    d1->right = i1;

    bool isBST = isBinarySearchTree(root1);

    cout<<isBST<<endl;


    bool isBST2 = isBinarySearchTreeEfficient(root1);
    cout<<isBST2<<endl;



    TreeNode *root = nullptr;

    root = add(root, 10);
    root = add(root, 12);
    root = add(root, 15);
    root = add(root, 8);
    root = add(root, 9);
    root = add(root, 7);

    bool isBST1 = isBinarySearchTree(root);
    cout<<isBST1<<endl;


    bool isBST3 = isBinarySearchTreeEfficient(root);
    cout<<isBST3<<endl;

    return 0;
}


TreeNode* createNewBSTNode(int value)
{
    TreeNode *newTreeNode = new TreeNode(value);
    return newTreeNode;
}


TreeNode* add(TreeNode *root, int value)
{
    if(root == nullptr)
    {
        root = createNewBSTNode(value);
    }
    else if(root->value >= value)
    {
        root->left = add(root->left, value);
    }
    else
    {
        root->right = add(root->right, value);
    }

    return root;

}

bool isBinarySearchTree(TreeNode *root)
{
    if(root == nullptr)
    {
        return true;
    }

    if(isSubTreeGreater(root->right, root->value) &&
            isSubTreeLesser(root->left, root->value) &&
            isBinarySearchTree(root->left) &&
            isBinarySearchTree(root->right)
      )
    {
        return true;
    }
    else
    {
        return false;
    }

}



bool isSubTreeGreater(TreeNode *root, int value)
{
    if(root == nullptr)
    {
        return true;
    }

    if(root->value > value && isSubTreeGreater(root->left, value) && isSubTreeGreater(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }

}


bool isSubTreeLesser(TreeNode *root, int value)
{
    if(root == nullptr)
    {
        return true;
    }

    if(root->value <= value && isSubTreeLesser(root->left, value) && isSubTreeLesser(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}



// is it binary search tree -efficient

bool isBinarySearchTreeEfficient(TreeNode *root)
{
    int minValue = numeric_limits<int>::min();
    int maxValue = numeric_limits<int>::max();

    return isBinarySearchTreeUtil(root, minValue, maxValue);

}


bool isBinarySearchTreeUtil(TreeNode *root, int minValue, int maxValue)
{
    if(root == nullptr)
    {
        return true;
    }

    if(root->value >= minValue && root->value < maxValue &&
            isBinarySearchTreeUtil(root->left,minValue,root->value) &&
            isBinarySearchTreeUtil(root->right, root->value, maxValue))
    {
        return true;
    }
    else{
        return false;
    }
}



