#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/

bool helper(BinaryTreeNode<int>* root, BinaryTreeNode<int>*& prev) {
    if (root) 
    {
        if (!helper(root->left, prev)) // Check left subtree
            return false;
        
        if (prev != NULL && root->data < prev->data)  // Traversal not in ascending order.
            return false;
        

        prev = root;

        return helper(root->right, prev);  // Check right subtree
    }

    return true;
}

bool validateBST(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* prev = NULL;
    return (helper(root, prev));
}
