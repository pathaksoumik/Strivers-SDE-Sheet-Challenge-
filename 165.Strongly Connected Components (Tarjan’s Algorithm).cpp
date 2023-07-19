#include<bits/stdc++.h>

void dfs(int u,vector<int>&disc,vector<int>&low,stack<int>&st,
        vector<bool>&presentinstack,vector<int>adj[],int &timer,
        vector<vector<int>>&res)
{
    disc[u]=low[u]=timer++;
    st.push(u); presentinstack[u]=true;
    
    for(auto v:adj[u])
    {
        if(disc[v]==-1)
        {
            dfs(v,disc,low,st,presentinstack,adj,timer,res);
            low[u]=min(low[u],low[v]);
        } 
            else if(presentinstack[v])//back-edge
                low[u]=min(low[u],disc[v]);
    }
         if(low[u]==disc[u])//root of SCC
        {
            vector<int>ans;
            while(st.top()!=u)
            {
               ans.push_back(st.top());
                presentinstack[st.top()]=false;
                st.pop();
            }
            ans.push_back(st.top());
                presentinstack[st.top()]=false;
                st.pop();
            
            sort(ans.begin(),ans.end());
            res.push_back(ans);
        }
}


vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int>adj[n];
    vector<int>disc(n,-1),low(n,-1);
    vector<bool>presentinstack(n,false);
    stack<int>st;
    int timer=0;
    vector<vector<int>>res;
    for(auto edge:edges)
    {
        adj[edge[0]].push_back(edge[1]);
        //adj[edge[1]].push_back(edge[0]);
    }
    
    for(int i=0;i<n;i++)
    {
        if(disc[i]==-1)
            dfs(i,disc,low,st,presentinstack,adj,timer,res);
    }
    sort(res.begin(),res.end());
    
    return res;
}
