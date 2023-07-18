#include<bits/stdc++.h>
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(),arr.end());
    int k=0;
    vector<vector<int>>res;
    map<vector<int>,int>s;
    for(int i=0;i<(1<<n);i++)
    {
        vector<int>ans;
        for(int j=0;j<n;j++)
            if((1<<j)&i)ans.push_back(arr[j]);
        
        if(!s.count(ans))
        {
         res.push_back(ans);
          s[ans]=1;
        }
     }

    sort(res.begin(),res.end());
    return res;
}
