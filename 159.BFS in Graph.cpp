#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int>res;
    
    unordered_map<int,vector<int>>adj;
    vector<bool>vis(vertex);
    
    for(auto edge:edges)
    {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    
    for(int j=0;j<vertex;j++)
        sort(adj[j].begin(),adj[j].end());
        
    for(int i=0;i<vertex;i++)
    {
       if(!vis[i])
       {
           queue<int>q;
           vis[i]=true;
           q.push(i);
           while(!q.empty())
           {
               int node=q.front();
               q.pop();
               res.push_back(node);
               
               for(auto x:adj[node])
               {
                   if(!vis[x])
                   {
                       q.push(x);
                       vis[x]=true;
                   }
               }
           }
       }
    }
    return res;
}
