#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<bool>vis(n+1,false);
    unordered_map<int,vector<int>>adj;
    queue<pair<int,int>>q;
    for(auto x:edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            q.push({i,-1});
            vis[i]=true;
        }
            while(!q.empty())
            {
                auto node=q.front();
                int val= node.first;
                int parent=node.second;
                q.pop();
                for(auto x:adj[val])
                {
                    if(!vis[x])
                    {
                        q.push({x,val});
                        vis[x]=true;
                    }
                    else if(parent !=x)return "Yes";
                }
            }
    }
    return "No";
}
