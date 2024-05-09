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

ListNode* reverseList(ListNode* head);

int main()
{

//    ListNode *root = nullptr;
    ListNode *root = new ListNode(1);
    root->add(2);
    root->add(3);
    root->add(4);
    root->add(5);
    root->add(6);
    root->add(7);


    root->printNodes();

    root = reverseList(root);

    root->printNodes();


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

ListNode* reverseList(ListNode* head)
{
    if(head==nullptr)
    {
        return head;
    }
    else if(head->next == nullptr)
    {
        return head;
    }
    else
    {
        ListNode *currentNode = head;
        ListNode *previousNode = nullptr;
        ListNode *nextNode = nullptr;

        while(currentNode->next != nullptr)
        {
            nextNode = currentNode->next;
            currentNode->next = previousNode;

            previousNode = currentNode;
            currentNode = nextNode;

        }
        currentNode->next = previousNode;
        head = currentNode;


        return head;
    }
}


