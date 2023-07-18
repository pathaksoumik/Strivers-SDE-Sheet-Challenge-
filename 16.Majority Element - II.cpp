#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int>v;
    int n=arr.size();
    unordered_map<int,int>mp;
    
    for(auto x:arr)mp[x]++;
    
    for(auto x:mp)
    {
        if(x.second > (n/3))
            v.push_back(x.first);
    }
    return v;
}
