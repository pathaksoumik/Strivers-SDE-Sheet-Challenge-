#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int> * reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *curr=head, *prev=NULL, *next=NULL;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(!head or  !head->next)return true;

    LinkedListNode<int> *slow=head,*fast=head->next;
    while(fast and fast->next)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    LinkedListNode<int> *newhead=reverse(slow->next);
    slow->next=NULL;
    
    LinkedListNode<int> *curr=head,*newcurr=newhead;
    while(curr and newcurr)
    {
        if(curr->data !=newcurr->data)return false;
        curr=curr->next; newcurr=newcurr->next;
    }

  return true;
}
