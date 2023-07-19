#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

#include<bits/stdc++.h>
bool isLeaf(TreeNode<int>* root)
{
    if(!root->left and !root->right)return true;
    return false;
}
void lefttraversal(TreeNode<int>*root,vector<int>&res)
{
    TreeNode<int>* curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr))res.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}

void leafTraversal(TreeNode<int>*root,vector<int>&res)
{
    if(isLeaf(root))res.push_back(root->data);

    if(root->left)leafTraversal(root->left,res);
    
    if(root->right) leafTraversal(root->right,res);
}

void righttraversal(TreeNode<int>*root,vector<int>&res)
{
    TreeNode<int>* curr=root->right;
    stack<TreeNode<int>*>st;
    while(curr)
    {
        if(!isLeaf(curr))st.push(curr);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    while(!st.empty())
    {
        res.push_back(st.top()->data);
        st.pop();
    }
}


vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>res;
    if(!root)return res;
    
    if(!isLeaf(root))res.push_back(root->data);
    lefttraversal(root,res);
    leafTraversal(root,res);
    righttraversal(root,res);
    return res;
}
