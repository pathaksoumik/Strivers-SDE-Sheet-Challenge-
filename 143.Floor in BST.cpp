#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    
    int floor=-1; 
    
    if(!root)return floor;

    TreeNode<int> *curr=root;
    while(curr)
    {
      if (curr->val > X) 
        curr=curr->left;
      else
      {
          //if(floor==curr->val)return floor;

          floor=curr->val;
          curr=curr->right;
      }
    }
    return floor;
}
