/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
  Node* curr=head;
  int sz=0;
  while(curr)
  {
   curr=curr->next;
   sz++;
  }

  if(sz<=K)return head->next;
  //if(sz<K) return head;

 Node* temp=NULL;
 curr=head;

 for(int i=1;i<(sz-K+1);i++)
 {
     temp=curr;
     curr=curr->next;
 }
temp->next=curr->next;
delete(curr);

  return head;
}
