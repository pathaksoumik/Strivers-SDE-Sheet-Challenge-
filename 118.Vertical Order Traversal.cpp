#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int>res;
    if(!root)return res;

    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    map<int,vector<int>>mp;
    while(!q.empty())
    {
        auto node=q.front();
        int line=node.second;
        mp[line].push_back(node.first->data);
        q.pop();

        if(node.first->left)q.push({node.first->left,line-1});
        if(node.first->right)q.push({node.first->right,line+1});
    }


    for(auto x:mp)
    {
        for(auto it:x.second)res.push_back(it);
    }

    return res;
}
