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

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* slow=head, *fast=head;
    Node* entry=NULL;
    bool flag=0;
    while(fast->next and fast->next->next)
    {
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast)
        {
         flag=1;
         break;
        }
    }
    if(flag)
    {
        entry=head;
        if(entry==slow)return entry;
        while(slow)
        {
            entry=entry->next;
            slow=slow->next;
            if(entry==slow)return entry;
        }
    }
    return entry;
}
