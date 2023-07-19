#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
   int successor=-1,predecessor=-1;
    BinaryTreeNode<int>*curr1=root,*curr2=root;
    while(curr1)
    {
        if(key>=curr1->data)
            curr1=curr1->right;
        
        else
        {
            successor=curr1->data;
            curr1=curr1->left;
        }
    }
    
    while(curr2)
    {
        if(key> curr2->data)
        {
            predecessor=curr2->data;
            curr2=curr2->right;
        }
        
        else
         curr2=curr2->left;
    }
    return {predecessor,successor};
}
