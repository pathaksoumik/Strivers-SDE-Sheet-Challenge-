#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int>res;
    if(!root)return res;

    map<int,BinaryTreeNode<int>*>mp;
    queue<pair<int,BinaryTreeNode<int>*>>q;
    q.push({0,root});

    while(!q.empty())
    {
        auto it=q.front();
        int level=it.first;
        auto node=it.second;
        mp[level]=node;
        q.pop();

        if(node->left)q.push({level-1,node->left});
        if(node->right)q.push({level+1,node->right});
    }
    
    for(auto x:mp)
    res.push_back(x.second->data);

    return res;
}
