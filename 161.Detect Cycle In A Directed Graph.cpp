#include<bits/stdc++.h>

bool dfs(int src,vector<bool>&vis,vector<bool>&dfsvis,unordered_map<int,vector<int>>&adj)
{
    vis[src]=true; dfsvis[src]=true;
    
    for(auto x:adj[src])
    {
        if(!vis[x])
        {
            if(dfs(x,vis,dfsvis,adj))return true;
        }
        else if(dfsvis[x])return true;
    }
    dfsvis[src]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
   unordered_map<int,vector<int>>adj;
    
    for(auto x:edges)
    {
        adj[x.first].push_back(x.second);
    }
    vector<bool>vis(n+1,false),dfsvis(n+1,false);
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,dfsvis,adj))return true;
        }
    }
    return false;
}
