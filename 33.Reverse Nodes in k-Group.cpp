#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	 if (!head) {
        return NULL;
    }

    
    int idx = 0;

    Node *prev = NULL, *cur = head, *temp = NULL;
    Node *tail = NULL, *join = NULL;
    bool isHeadUpdated = false;

    
    while (cur != NULL && idx < n) {

        // K represents the size of the current block
        int K = b[idx];

        // Just move to the next block if size of the current block is zero
        if (K == 0) {
            idx++;
            continue;
        }

        join = cur;
        prev = NULL;

       
        while (cur != NULL && K--) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        
        if (isHeadUpdated == false) {
            head = prev;
            isHeadUpdated = true;
        }

        
        if (tail != NULL) {
            tail->next = prev;
        }

        
        tail = join;
        idx++;
    }

   
    if (tail != NULL) {
        tail->next = cur;
    }

    return head;

}
