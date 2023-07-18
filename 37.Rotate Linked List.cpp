/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(!head or !head->next)return head;

     int cnt=1;
     Node* curr=head;
     while(curr->next)
     {
          ++cnt;
          curr=curr->next;
     }
     k%=cnt;
     if(!k)return head;

     int n=cnt-k-1;
     curr->next=head;
     Node* temp=head;
     
     while(n)
     {
          temp=temp->next;
          n--;
     }
     head=temp->next;
     temp->next=NULL;

     return head;
}
