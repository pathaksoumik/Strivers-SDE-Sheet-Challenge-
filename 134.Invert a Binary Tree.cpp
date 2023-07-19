// Libnk of the problem: https://www.codingninjas.com/studio/problems/invert-a-binary-tree_8230838?challengeSlug=striver-sde-challenge

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
bool path(TreeNode<int>*root,TreeNode<int>*leaf,queue<TreeNode<int>*>&leaftoRoot)
{
    if(!root)return false;
    
    if(root->data==leaf->data)
    {
        leaftoRoot.push(root);
        return true;
    }

    if(path(root->left,leaf,leaftoRoot))
    {
        leaftoRoot.push(root);
        return true;
    }
    if(path(root->right,leaf,leaftoRoot))
    {
        leaftoRoot.push(root);
        return true;
    }
    return false;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    queue<TreeNode<int>*>leaftoRoot;
    path(root,leaf,leaftoRoot);

    TreeNode<int>*newroot=leaftoRoot.front();
    leaftoRoot.pop();

    TreeNode<int>*parent=newroot;

    while(!leaftoRoot.empty())
    {
        TreeNode<int>*x=leaftoRoot.front();
        leaftoRoot.pop();
        
        if(x->left==parent) //left child if already taken
            x->left=NULL;
        
        
        else               // left child if not taken
        {
          x->right=x->left;
          x->left=NULL;  
        }  

        parent->left=x; // parent of x must be left child of x
        
        parent =x; //for running the loop
    }
    return newroot;
}
