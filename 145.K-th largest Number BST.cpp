#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
vector<int> inorder(TreeNode<int>* root)
{
   vector<int>ans;
   if(ans.size()>0)return ans;
    if (!root) {
        vector<int>empty;
      return empty;
    }
    

    inorder(root->left);
    ans.push_back(root->data);
    inorder(root->right);
     
     if(ans.size()>0)return ans;

     vector<int>nothing;
    return nothing;
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    if(!root)return -1;
    vector<int>res=inorder(root);
    if(k>res.size())return -1;

    return res[res.size()-k];
}
