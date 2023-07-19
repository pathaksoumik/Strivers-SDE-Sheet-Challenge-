#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(!root) return;
       
       queue<BinaryTreeNode< int > *> q;
       q.push(root);
       q.push(NULL);
       
       BinaryTreeNode< int > *curr,*next;
       
       while(!q.empty() && q.front() != NULL)
       {
           curr = q.front();
           q.pop();
           
           while(curr)
           {
               if(curr->left) q.push(curr->left);
               if(curr->right) q.push(curr->right);
               
               next = q.front();
               q.pop();
               
               curr->next = next;
               curr = next;
               
           }
           q.push(NULL);
       }
}
