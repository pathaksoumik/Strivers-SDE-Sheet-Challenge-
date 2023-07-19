//Link for the problem:  https://www.codingninjas.com/studio/problems/maximum-width-in-binary-tree_8230710?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root)return 0;
    int maxx=0;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        int sz=q.size();
        maxx=max(maxx,sz);
        for(int i=0;i<sz;i++)
        {
            auto node=q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return maxx;
}
