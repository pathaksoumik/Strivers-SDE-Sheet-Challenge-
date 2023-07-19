#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int> *>q;
    vector<int>res;
    if(!root)return res;

    q.push(root);
    while(!q.empty())
    {
      for (int i = 0; i < q.size(); i++)
       {
        auto node = q.front();
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
        q.pop();
        res.push_back(node->val);
      }
    }
    return res;
}
