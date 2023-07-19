#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
void largestBstSize(TreeNode<int>* root, int &maxVal, int &minVal, int &bstSize, bool &isBst) {
	if (root == NULL) 
    {
		isBst = true;
		return;
	}

	bool isLeftBst = false, isRightBst = false;
	int leftSize = 0, rightSize = 0;
	int leftMaxVal = INT_MIN, leftMinVal = INT_MAX, rightMaxVal = INT_MIN, rightMinVal = INT_MAX;

	largestBstSize(root->left, leftMaxVal, leftMinVal, leftSize, isLeftBst);
	largestBstSize(root->right, rightMaxVal, rightMinVal, rightSize, isRightBst);

	maxVal = max(root->data, max(leftMaxVal, rightMaxVal));
	minVal = min(root->data, min(leftMinVal, rightMinVal));
    
	if (isLeftBst && isRightBst && leftMaxVal < root->data && rightMinVal > root->data) 
    {
		isBst = true;
		bstSize = 1 + leftSize + rightSize;
	} 

    else bstSize = max(leftSize, rightSize);
	
	return;
}


int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int maxVal = INT_MIN;
	int minVal = INT_MAX;
	bool isBst = false;
	int bstSize = 0;
	largestBstSize(root, maxVal, minVal, bstSize, isBst);
	return bstSize;
}
