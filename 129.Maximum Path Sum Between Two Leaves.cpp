#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int solve(TreeNode<int>*root, long long int&maxsum)
{
    if(!root)return 0LL;
    if(!root->left and !root->right)return root->val;

    long long int lh=solve(root->left,maxsum);
    long long int rh=solve(root->right,maxsum);

    if(!root->left)return rh+root->val;
    else if(!root->right)return lh+root->val;

    maxsum=max(maxsum,lh+rh+root->val);

    return root->val+max(lh,rh);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    
    long long int maxsum=-1;
    long long int sum=solve(root,maxsum);
    return maxsum;
}
