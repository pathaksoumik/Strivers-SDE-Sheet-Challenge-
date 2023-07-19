#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void Inorder(BinaryTreeNode<int>*root, vector<int>&inorder)
{
    if(!root)return ;

    Inorder(root->left,inorder);
    inorder.push_back(root->data);
    Inorder(root->right,inorder);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int>inorder;
    Inorder(root,inorder);
    
    int start=0,end=inorder.size()-1;

    while(start<end)
    {
        int sum=inorder[start]+inorder[end];

        if(sum==k)return true;

        if(sum<k)start++;
        else end--;
    }
    return false;
}
