#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int>*head=root,*pre=NULL, *cur=root;
    while (cur)
	{
	 if(cur->left)
	  {
		TreeNode<int>* pre = cur->left;
		while(pre->right)
			pre = pre->right;
				
		pre->right = cur->right;
		cur->right = cur->left;
		cur->left = NULL;
	 }
     
		cur = cur->right;
	}
        return head;
}
