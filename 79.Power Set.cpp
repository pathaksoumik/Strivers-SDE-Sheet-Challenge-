#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    sort(v.begin(),v.end());
    int n=v.size();
    vector<vector<int>>res;

    for(int i=0;i<(1<<n);i++)
    {
     vector<int>ans;
     for(int j=0;j<n;j++)
     {
         if((1<<j)&i)ans.push_back(v[j]);
     }
     res.push_back(ans);
    }
    return res;
}
