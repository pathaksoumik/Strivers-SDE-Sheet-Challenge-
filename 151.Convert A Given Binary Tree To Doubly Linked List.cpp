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

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    if (root == nullptr)
        return nullptr;

    BinaryTreeNode<int>* prev = nullptr;
    BinaryTreeNode<int>* head = nullptr;

    stack<BinaryTreeNode<int>*> stk;
    BinaryTreeNode<int>* curr = root;

    while (curr != nullptr || !stk.empty()) {
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }

        curr = stk.top();
        stk.pop();

        if (prev == nullptr) {
            head = curr;
        } else {
            prev->right = curr;
            curr->left = prev;
        }

        prev = curr;
        curr = curr->right;
    }

    return head;

}
