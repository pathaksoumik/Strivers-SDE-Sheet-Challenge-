#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int>freq[n+1];
    unordered_map<int,int>mp;
    
    for(auto x:arr)mp[x]++;

    for(auto x:mp) freq[x.second].push_back(x.first);

    vector<int>res;
    
    for(int i=n;i>=0 and k>0;i--)
    {
       if(!freq[i].size())continue;

       for (auto x : freq[i]) 
       {
         res.push_back(x);
         k--;
         
         if(!k)break;
       }
    }
    sort(res.begin(),res.end());

    return res;
}
