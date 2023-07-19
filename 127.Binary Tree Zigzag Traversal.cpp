#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>res;
    if(!root)return res;
    
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    
    bool shift=0;

    while(!q.empty())
    {
     int sz=q.size();
     vector<int>sol(sz);
     for(int i=0;i<sz;i++)
     {
      
      int idx= (!shift)?i:sz-1-i;
      auto node=q.front();
      sol[idx]=node->data;
      q.pop();

      if(node->left)q.push(node->left);
      if(node->right)q.push(node->right);
     }
     for(auto x:sol)res.push_back(x);

     shift^=1;
    }

    return res;
}
