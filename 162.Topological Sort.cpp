#include <bits/stdc++.h> 
#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int>topo;
    vector<bool>vis(v,false);
    queue<int>q;
    vector<int>indegree(v,0);
    
    vector<vector<int>> adj(v);
    for(int i = 0; i < e; i++) 
        adj[edges[i][0]].push_back(edges[i][1]);
    
    for(int i=0;i<v;i++)
    {
     for(auto x:adj[i])
         indegree[x]++;
    }
    
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)q.push(i);
    }
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto x:adj[node])
        {
            indegree[x]--;
            if(indegree[x]==0)q.push(x);
        }
    }
    return topo;
}
