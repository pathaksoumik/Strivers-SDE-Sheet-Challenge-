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

class BSTiterator
{
public:
	
    // Create a stack which will store smallest element at the top
    stack<TreeNode<int> *> st;

    BSTiterator(TreeNode<int> *root)
    {
    	
        // Fill the stack with leftmost nodes present in the subtree of root
        leftMostInorder(root);
    }

    int next()
    {
    	
        // Pop the minimum
        TreeNode<int> *top = st.top();
        st.pop();
        
        // Check if it has right child
        if (top->right != NULL)
        {
        
            // Push leftmost nodes present in the subtree of right child
            leftMostInorder(top->right);
        }
        return top->data;
    }

    bool hasNext()
    {
        // If size of stack is greater than zero that means there are still some nodes left for processing
        if (st.size() > 0)
            return true;
        
        else return false;
    }

    // This function will used to push leftmost nodes in the stack present in the subtree of root
    void leftMostInorder(TreeNode<int> *root)
    {
        while (root != NULL)
        {
            st.push(root);
            root = root->left;
        }
    }
};



/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
