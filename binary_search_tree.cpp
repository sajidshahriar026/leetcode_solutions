#include<bits/stdc++.h>
using namespace std;



struct BSTNode
{
    int value;
    BSTNode *leftSubTree;
    BSTNode *rightSubTree;
};

BSTNode* createNewBSTNode(int value);
BSTNode* add(BSTNode* root, int value);
BSTNode* addWithoutRecursion(BSTNode *root, int value);
BSTNode* searchWithoutRecursion(BSTNode *root, int value);
BSTNode* seek(BSTNode* root, int x);
BSTNode* findMin(BSTNode *root);
BSTNode* findMax(BSTNode *root);
vector<int> levelOrderTraversal(BSTNode *root);
BSTNode* inOrderSuccessor(BSTNode *root, int data);

BSTNode* expunge(BSTNode *root, int value);

void inOrderTraversal(BSTNode *root);
void preOrderTraversal(BSTNode *root);
void postOrderTraversal(BSTNode *root);



int main()
{
    BSTNode *root = nullptr;

    root = add(root, 10);
    root = add(root, 12);
    root = add(root, 15);
    root = add(root, 8);
    root = add(root, 9);
    root = add(root, 7);

    inOrderTraversal(root);

    cout<<endl;

    BSTNode *sNode = seek(root, 8);

    inOrderTraversal(sNode);
    cout<<endl;

    BSTNode *root2 = nullptr;

    root2 = addWithoutRecursion(root2, 10);
    root2 = addWithoutRecursion(root2, 12);
    root2 = addWithoutRecursion(root2, 15);
    root2 = addWithoutRecursion(root2, 8);
    root2 = addWithoutRecursion(root2, 9);
    root2 = addWithoutRecursion(root2, 7);

    inOrderTraversal(root2);
    cout<<endl;

    BSTNode *sNode2 = seek(root2, 8);

    inOrderTraversal(sNode2);
    cout<<endl;

    BSTNode *minNode = findMin(root2);
    cout<<minNode->value<<endl;

    BSTNode *maxNode = findMax(root2);
    cout<<maxNode->value<<endl;


    vector<int>v = levelOrderTraversal(root2);

    for(auto it = v.begin(); it!= v.end(); it++)
    {
        cout<<*it<<' ';
    }
    cout<<endl;

    inOrderTraversal(root2);
    cout<<endl;
    preOrderTraversal(root2);
    cout<<endl;
    postOrderTraversal(root2);
    cout<<endl;


    root2 = expunge(root, 12);

    inOrderTraversal(root2);
    cout<<endl;


    BSTNode *successor = inOrderSuccessor(root2, 8);
    cout<<successor->value<<endl;


    return 0;


}

BSTNode* createNewBSTNode(int value)
{
    BSTNode *newNode = new BSTNode();
    newNode->value = value;
    newNode->leftSubTree = nullptr;
    newNode->rightSubTree = nullptr;

    return newNode;
}


BSTNode* add(BSTNode* root, int value)
{
    if(root == nullptr)
    {
        root = createNewBSTNode(value);
    }
    else if(root->value >= value)
    {
        root->leftSubTree = add(root->leftSubTree, value);
    }
    else
    {
        root->rightSubTree = add(root->rightSubTree, value);
    }

    return root;


}

BSTNode* addWithoutRecursion(BSTNode *root, int value)
{
    if(root == nullptr)
    {
        root = createNewBSTNode(value);
    }
    else
    {
        BSTNode *parentNode = nullptr;
        BSTNode *currentNode = root;

        while(currentNode!=nullptr)
        {
            parentNode = currentNode;
            if(currentNode->value >= value)
            {
                currentNode = currentNode->leftSubTree;
            }
            else
            {
                currentNode = currentNode->rightSubTree;
            }
        }

        if(parentNode->value >= value)
        {
            parentNode->leftSubTree = createNewBSTNode(value);
        }
        else
        {
            parentNode->rightSubTree = createNewBSTNode(value);
        }
    }

    return root;
}


BSTNode* seek(BSTNode *root, int x)
{
    if(root==nullptr)
    {
        return nullptr;
    }

    if(root->value == x)
    {
        return root;
    }
    else if(root->value >= x)
    {
        return seek(root->leftSubTree, x);
    }
    else
    {
        return seek(root->rightSubTree,x);
    }


}

BSTNode* searchWithoutRecursion(BSTNode *root, int value)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    BSTNode *currentNode = root;

    while(currentNode != nullptr)
    {
        if(currentNode->value == value)
        {
            return currentNode;
        }
        else if(currentNode->value >= value)
        {
            currentNode = currentNode->leftSubTree;
        }
        else
        {
            currentNode = currentNode->rightSubTree;
        }
    }
    return nullptr;
}

BSTNode* findMin(BSTNode *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    BSTNode *currentNode = root;
    while(currentNode->leftSubTree != nullptr)
    {
        currentNode = currentNode->leftSubTree;
    }

    return currentNode;
}


BSTNode* findMax(BSTNode* root)
{
    if(root == nullptr)
    {
        return nullptr;
    }

    BSTNode *currentNode = root;

    while(currentNode ->rightSubTree != nullptr)
    {
        currentNode = currentNode->rightSubTree;
    }

    return currentNode;
}


vector<int>levelOrderTraversal(BSTNode* root)
{
    if(root == nullptr)
    {
        return vector<int>();
    }

    queue<BSTNode*> qNode;
    qNode.push(root);

    vector<int>nodeValues;

    while(!qNode.empty())
    {
        BSTNode *visitedNode = qNode.front();
        nodeValues.push_back(visitedNode->value);

        if(visitedNode->leftSubTree != nullptr)
        {
            qNode.push(visitedNode->leftSubTree);
        }
        if(visitedNode->rightSubTree != nullptr)
        {
            qNode.push(visitedNode->rightSubTree);
        }

        qNode.pop();
    }

    return nodeValues;

}



void inOrderTraversal(BSTNode* root)
{

    //in-order traversal
    if(root==nullptr)
    {
        return;
    }
    inOrderTraversal(root->leftSubTree);
    cout<<root->value<<' ';
    inOrderTraversal(root->rightSubTree);
}


void preOrderTraversal(BSTNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    cout<<root->value<<' ';
    preOrderTraversal(root->leftSubTree);
    preOrderTraversal(root->rightSubTree);
}


void postOrderTraversal(BSTNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    postOrderTraversal(root->leftSubTree);
    postOrderTraversal(root->rightSubTree);
    cout<<root->value<<' ';
}


BSTNode* expunge(BSTNode *root, int value)
{
    if(root == nullptr)
    {
        return root;
    }
    else if(root->value > value)
    {
        root->leftSubTree = expunge(root->leftSubTree, value);
    }
    else if(root->value < value)
    {
        root->rightSubTree = expunge(root->rightSubTree, value);
    }
    else
    {
        //leaf node
        if(root->leftSubTree == nullptr && root->rightSubTree == nullptr)
        {
            delete root;
            root = nullptr;
        }
        //one child case
        else if(root->leftSubTree == nullptr)
        {
            BSTNode *temp = root;
            root = root->rightSubTree;
            delete temp;
        }
        else if(root->rightSubTree == nullptr)
        {
            BSTNode *temp = root;
            root = root->leftSubTree;
            delete temp;
        }
        //2 children case
        else
        {
            BSTNode *minNode = findMin(root->rightSubTree);
            root->value = minNode->value;
            root->rightSubTree = expunge(root->rightSubTree, minNode->value);

        }
    }
    return root;
}


BSTNode* inOrderSuccessor(BSTNode *root, int data)
{
    BSTNode *searchedNode = seek(root, data);

    if(searchedNode == nullptr)
    {
        return nullptr;
    }
    else if(searchedNode->rightSubTree != nullptr)
    {
        return findMin(searchedNode->rightSubTree);
    }
    else
    {
        BSTNode *ancestor = root;
        BSTNode *successor = nullptr;

        while(ancestor != searchedNode)
        {
            if(ancestor->value > searchedNode->value)
            {
                successor = ancestor;
                ancestor = ancestor->leftSubTree;
            }
            else
            {
                ancestor = ancestor->rightSubTree;

            }
        }
        return successor;
    }



}


