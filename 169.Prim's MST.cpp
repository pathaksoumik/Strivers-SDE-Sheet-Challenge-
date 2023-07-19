#include <bits/stdc++.h> 

bool comp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) 
{
    if (a.second == b.second)
        return a.first.first < b.first.first;
        
    return a.second < b.second;
}

int find(int cur, vector<int> &parent)
{
    if (parent[cur] != cur)
        parent[cur] = find(parent[cur], parent);
        
    return parent[cur];
}

void merge(int u, int v, vector<int> &parent) 
{
    u = find(u, parent);
    v = find(v, parent);
    parent[v] = u;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    vector<pair<pair<int, int>, int>> res;
    sort(g.begin(), g.end(), comp);
    
    vector<int> parent(n+1);
    
    for (int i = 0; i <= n; ++i)
        parent[i] = i;
        
    for (int i = 0; i < m && res.size() < n-1; ++i) 
    {
        int parentU = find(g[i].first.first, parent);
        int parentV = find(g[i].first.second, parent);
        if (parentU != parentV) 
        {
            res.push_back(g[i]);
            merge(parentU, parentV, parent);
        }
    }
    return res;
}
