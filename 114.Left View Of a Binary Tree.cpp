#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(TreeNode<int> *root,int level,vector<int>&res)
{
    if(!root)return ;
    if(level==res.size())res.push_back(root->data);

    solve(root->left,level+1,res);
    solve(root->right,level+1,res);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>res;
    solve(root,0,res);
    return res;
}
