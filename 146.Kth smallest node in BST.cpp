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
void inorder(TreeNode<int>* root,vector<int>&ans)
{
    if(!root)return ;

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    if(!root)return -1;
    vector<int>res;
    inorder(root,res);
    if(k>res.size())return -1;

    return res[k-1];
}
