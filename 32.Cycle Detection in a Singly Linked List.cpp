/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/
#include<bits/stdc++.h>
/*  
    Time Complexity : O(N)
    Space Complexity : O(1)
    
    Where N is number of Nodes in Linked-List.
*/

bool detectCycle(Node *head)
{
    if (!head or !head->next)
        return false;
   
    Node *slow = head, *fast = head->next;
    
    while (slow != fast)
    { 
        if (!fast or !fast->next)
            return false;
        
        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}
