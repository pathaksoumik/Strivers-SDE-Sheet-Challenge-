#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* solve(vector<int>&preorder, int start, int end)
{
 if(start>end)return nullptr;

 int mid=start+(end-start)/2;
 TreeNode<int>* root= new TreeNode<int>(preorder[mid]);

 root->left=solve(preorder,start,mid-1);
 root->right=solve(preorder,mid+1,end);

 return root;
}

TreeNode<int>* preOrderTree(vector<int> &preorder){
    // Write your code here.
    sort(preorder.begin(),preorder.end());

    TreeNode<int>*root=solve(preorder,0,preorder.size()-1);

    return root;
}
