#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
bool  solve(TreeNode<int>*root, int x, vector<int>&res)
{
	if(!root)return false;
    if(root->data== x)
	{
		res.push_back(root->data);
		return true;
	}
	if(solve(root->left,x,res))
	{
     res.push_back(root->data);
	 return true;
	}
	if(solve(root->right,x,res))
	{
		res.push_back(root->data);
		return true;
	}
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>res;
	bool check=solve(root,x,res);
	reverse(res.begin(),res.end());
	return res;
}
