/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool check(BinaryTreeNode<int>*left,BinaryTreeNode<int>*right)
{
    if(!left or !right)return left==right;
    return (left->data == right->data) and check(left->left, right->right) and check(left->right, right->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.
    return !root or check(root->left,root->right);   
}
