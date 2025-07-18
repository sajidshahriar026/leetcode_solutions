#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int main(){

}


ListNode* deleteMiddle(ListNode* head)
{
    ListNode *current = head;

    int length = 0;
    while(current  != nullptr)
    {
        length++;
        current=current->next;
    }

    int indexToBeDeleted = length/2;

    int index = 0;
    ListNode *previousNode = nullptr;
    current = head;
    while(current!= nullptr)
    {

        if(indexToBeDeleted == 0)
        {
            return nullptr;
        }


        if(index != indexToBeDeleted)
        {
            previousNode = current;
            current = current->next;
            index++;
        }
        else
        {
            previousNode->next = current->next;
            delete current;
            break;
        }
    }

    return head;
}
