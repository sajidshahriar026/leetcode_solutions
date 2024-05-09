#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}

    //add x to the end of the linked list
    void add(int x);
    void printNodes();

};

int pairSum(ListNode *head);

int main()
{

//    ListNode *root = nullptr;
    ListNode *root = new ListNode(4);
    root->add(2);
    root->add(2);
    root->add(3);
//    root->add(5);
//    root->add(6);
//    root->add(7);
//    root->add(8);


    root->printNodes();

    int maxSum = pairSum(root);

    cout<<maxSum<<endl;

    return 0;
}




void ListNode::add(int x)
{

    if(this==nullptr)
    {
        this->val = x;
        this->next = nullptr;
    }

    else
    {
        ListNode *current = this;
        while(current->next != nullptr)
        {
            current = current->next;
        }

        ListNode *newListNode = new ListNode(x);
        current->next = newListNode;
    }
}

void ListNode::printNodes()
{
    ListNode *current = this;

    while(current!=nullptr)
    {
        cout<<current->val<<' ';
        current = current->next;
    }
    cout<<endl;
}


int pairSum(ListNode *head)
{
    int length;
    ListNode *currentNode = head;

    vector<int>vi;

    while(currentNode!=nullptr)
    {
        vi.push_back(currentNode->val);
        currentNode = currentNode->next;
    }

    length = vi.size();
    int maxSum = INT_MIN;

    for(int i=0;i<(length/2);i++)
    {
        int sum = vi[i] + vi[length-1-i];

        maxSum = (maxSum > sum) ? maxSum : sum;

    }


    return maxSum;
}



