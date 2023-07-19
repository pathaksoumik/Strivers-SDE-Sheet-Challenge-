#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int>res;
    if(!root)return res;

    map<int,TreeNode<int>*>mp;
    queue<pair<int, TreeNode<int>*>> q;
    q.push({0,root});

    while(!q.empty())
    {
        auto it=q.front();
        int level=q.front().first;
        auto node=q.front().second;
        q.pop();
        if(mp.find(level)==mp.end())mp[level]=node;

        if(node->left)q.push({level-1,node->left});
        if(node->right)q.push({level+1,node->right});
    }
    for(auto x:mp)
        res.push_back(x.second->val);

    return res;
}
