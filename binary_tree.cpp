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

vector<int> depthFirstValues(TreeNode *root);
vector<int> depthFirstValuesRecursive(TreeNode *root);
vector<int>breadthFirstValues(TreeNode *root);


int calculateHeight(TreeNode *root);
vector<int> getLeaves(TreeNode *root);
int goodNodes(TreeNode *root, int threshold);


int main()
{
    TreeNode *root = new TreeNode(119);
    TreeNode *a = new TreeNode(113);
    TreeNode *b = new TreeNode(11);
    TreeNode *c = new TreeNode(30);
    TreeNode *d = new TreeNode(43);
    TreeNode *e = new TreeNode(76);
    TreeNode *f = new TreeNode(15);
    TreeNode *g = new TreeNode(60);
    TreeNode *h = new TreeNode(67);
    TreeNode *i = new TreeNode(74);

    root->left = a;

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    d->left = h;
    d->right= i;


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


    vector<int>dfsValues = depthFirstValues(root);
    vector<int>dfsValuesRecursive = depthFirstValuesRecursive(root);
    vector<int>bfsValues = breadthFirstValues(root);
    for(auto i = dfsValues.begin();i!=dfsValues.end();i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;

    for(auto i = dfsValuesRecursive.begin();i!=dfsValuesRecursive.end();i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;

    for(auto i = bfsValues.begin();i!=bfsValues.end();i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;

    cout<<"Height of the tree: "<<calculateHeight(root)<<endl;

    vector<int>leafNodes = getLeaves(root);

    cout<<"Leaf Nodes: \n";
    for(auto i=leafNodes.begin();i!=leafNodes.end();i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;

    vector<int>leafNodes2 = getLeaves(root1);

    cout<<"Leaf Nodes for root1: \n";
    for(auto i=leafNodes2.begin();i!=leafNodes2.end();i++)
    {
        cout<<*i<<' ';
    }
    cout<<endl;

    cout<<"Good Nodes for tree with root1: "<<goodNodes(root1, INT_MIN)<<endl;


    return 0;
}

vector<int> depthFirstValues(TreeNode *root)
{
    stack<TreeNode*>fringe;
    vector<int>visitedNode;

    if(root!=nullptr)
    {
        fringe.push(root);
    }

    while(!fringe.empty())
    {
        TreeNode *currentNode = fringe.top();
        fringe.pop();

        visitedNode.push_back(currentNode->value);

        if(currentNode->right != nullptr) fringe.push(currentNode->right);
        if(currentNode->left != nullptr) fringe.push(currentNode->left);
    }

    return visitedNode;
}


vector<int> depthFirstValuesRecursive(TreeNode *root)
{
    if(root==nullptr)
    {
        return vector<int>();
    }

    vector<int>leftSubTreeValues = depthFirstValuesRecursive(root->left);
    vector<int>rightSubTreeValues = depthFirstValuesRecursive(root->right);

    vector<int>allValues;
    allValues.push_back(root->value);

    for(auto i=leftSubTreeValues.begin();i!=leftSubTreeValues.end();i++)
    {
        allValues.push_back(*i);
    }
    for(auto i=rightSubTreeValues.begin();i!=rightSubTreeValues.end();i++)
    {
        allValues.push_back(*i);
    }

    return allValues;
}


vector<int>breadthFirstValues(TreeNode *root)
{
    queue<TreeNode*>fringe;
    vector<int>visitedNodes;

    if(root != nullptr)
    {
        fringe.push(root);
    }

    while(!fringe.empty())
    {
        TreeNode* node = fringe.front();
        fringe.pop();

        visitedNodes.push_back(node->value);


        if(node->left != nullptr)
        {
            fringe.push(node->left);
        }
        if(node->right != nullptr)
        {
            fringe.push(node->right);
        }
    }

    return visitedNodes;
}



int calculateHeight(TreeNode *root)
{
    if(root==nullptr)
    {
        return 0;
    }
    int lh = calculateHeight(root->left);
    int rh = calculateHeight(root->right);

    int maxHeight = (lh > rh) ? lh : rh;

    return 1 + maxHeight;
}

vector<int> getLeaves(TreeNode *root)
{
    if(root == nullptr)
    {
        return vector<int>();
    }

    if(root->left == nullptr && root->right == nullptr)
    {
        vector<int>leafNode;
        leafNode.push_back(root->value);
        return leafNode;
    }

    vector<int>leftLeaves = getLeaves(root->left);
    vector<int>rightLeaves = getLeaves(root->right);

    vector<int>allLeaves;

    for(auto i=leftLeaves.begin();i!=leftLeaves.end();i++)
    {
        allLeaves.push_back(*i);
    }

    for(auto i=rightLeaves.begin();i!=rightLeaves.end();i++)
    {
        allLeaves.push_back(*i);
    }

    return allLeaves;
}

int goodNodes(TreeNode *root, int threshold)
{
    int goodNode = 0;
    if(root==nullptr)
    {
        return 0;
    }

    if(root->value >= threshold)
    {
        threshold = root->value;
        goodNode = 1;
    }

    int leftGoodNodes = goodNodes(root->left, threshold);
    int rightGoodNodes = goodNodes(root->right, threshold);

    return goodNode + leftGoodNodes + rightGoodNodes;

}

