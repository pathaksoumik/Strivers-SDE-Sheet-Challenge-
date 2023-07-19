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
TreeNode<int>* LCA(TreeNode<int>*root, int x, int y)
{
    if(!root or root->data==x or root->data==y)return root;
    
     TreeNode<int>*lh=LCA(root->left,x,y);
     TreeNode<int>*rh=LCA(root->right,x,y);
    
    if(!lh)return rh;
    else if(!rh)return lh;
    
    return root;
}


int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    auto node=LCA(root,x,y);
    return node->data;
}
