#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void solve(BinaryTreeNode<int>*root, vector<int>&pre,vector<int>&in, vector<int>&post)
{
    //if(!root)return;
    stack<pair<BinaryTreeNode<int>*,int>>st;
    st.push({root,0});

    while(!st.empty())
    {
        int level=st.top().second;
        if(!level)
        {
            pre.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->left)st.push({st.top().first->left,0});
        }
        
        else if(level==1)
        {
            in.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->right)st.push({st.top().first->right,0});
        }
        else
        {
            post.push_back(st.top().first->data);
            st.pop();
        }

    }
}


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int>inorder,preorder,postorder;
    vector<vector<int>>ans;

     if(!root)return ans;
     solve(root,preorder,inorder,postorder);

     ans.push_back(inorder);
     ans.push_back(preorder);
     ans.push_back(postorder);

     return ans;
}
