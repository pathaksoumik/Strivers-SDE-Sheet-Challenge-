#include<bits/stdc++.h>
void dfs(int src,vector<bool>&vis,unordered_map<int,vector<int>>&adj,vector<int>&ans)
{
    vis[src]=true;
    ans.push_back(src);
    
    for(auto x:adj[src])
    {
        if(!vis[x])
            dfs(x,vis,adj,ans);
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,vector<int>>adj;
    vector<bool>vis(V,false);
    vector<vector<int>>res;
    for(auto x:edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            vector<int>ans;
            dfs(i,vis,adj,ans);
            res.push_back(ans);
        }
    }
    return res;
}
