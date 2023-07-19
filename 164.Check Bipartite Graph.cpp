#include<bits/stdc++.h>

bool dfs(int src,vector<int>adj[],vector<int>&colour)
{
    if(colour[src]==-1)
        colour[src]=1;

    for(auto x:adj[src])
    {
        if(colour[x]==-1)
        {
            colour[x]=1-colour[src];
            if(!dfs(x,adj,colour))return false;
        }
        else if(colour[x]==colour[src])return false;
    }
    return true;
}


bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    
    int V = edges.size();

    vector<int> adj[V];

    for (int i = 0 ; i < V ; i++) 
    {
        for (int j = 0 ; j < V ; j++) 
        {
            if (edges[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int>colour(V,-1);
    
    for(int i=0;i<V;i++)
    {
        if(colour[i]==-1)
        {
            if(!dfs(i,adj,colour))return false;
         }
    }
    return true;
}
