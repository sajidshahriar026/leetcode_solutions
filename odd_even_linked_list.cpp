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


ListNode* oddEvenList(ListNode* head);

int main()
{
    ListNode *root = new ListNode(1);
    root->add(2);
    root->add(3);
    root->add(4);
    root->add(5);
    root->add(6);
    root->add(7);


    root->printNodes();

    root = oddEvenList(root);

    root->printNodes();

    return 0;

}

void ListNode :: add(int x)
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


ListNode* oddEvenList(ListNode* head)
{
    ListNode *currentNode = head;
    ListNode * tailNode;
    int length = 0;

    while(currentNode!=nullptr)
    {
        if(currentNode->next == nullptr)
        {
            tailNode = currentNode;
        }

        length++;
        currentNode = currentNode->next;


    }

//    cout<<length<<endl;
//
//    cout<<tailNode->val<<endl;



    if(length == 2)
    {
        return head;
    }
    else
    {
        currentNode = head;
        ListNode *previousNode = nullptr;
        int i = 1;

        while(i<=length)
        {
            if(i%2)
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            else
            {
                previousNode->next = currentNode->next;
                tailNode->next = currentNode;
                currentNode->next = nullptr;
                tailNode = tailNode->next;

                currentNode = previousNode->next;

            }

            i++;
        }

        return head;
    }
}



