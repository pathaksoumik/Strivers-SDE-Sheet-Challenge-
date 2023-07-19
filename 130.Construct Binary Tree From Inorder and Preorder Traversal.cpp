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

TreeNode<int> *buildBinaryTreeHelper(vector<int> &inorder, vector<int> &preorder,
                                     int inStart, int inEnd, int preStart, int preEnd,
                                     unordered_map<int, int> &indexMap) {
    if (inStart > inEnd) 
        return NULL;
    

    int rootValue = preorder[preStart];
    TreeNode<int> *root = new TreeNode<int>(rootValue);

    int rootIndex = indexMap[rootValue];
    int leftSubtreeSize = rootIndex - inStart;

    root->left = buildBinaryTreeHelper(inorder, preorder, inStart, rootIndex - 1, preStart + 1, preStart + leftSubtreeSize, indexMap);
    root->right = buildBinaryTreeHelper(inorder, preorder, rootIndex + 1, inEnd, preStart + leftSubtreeSize + 1, preEnd, indexMap);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder) {
    int n = inorder.size();

    // Build a map to store the indices of inorder elements
    unordered_map<int, int> indexMap;
    for (int i = 0; i < n; i++) 
        indexMap[inorder[i]] = i;
    

    return buildBinaryTreeHelper(inorder, preorder, 0, n - 1, 0, n - 1, indexMap);
}
