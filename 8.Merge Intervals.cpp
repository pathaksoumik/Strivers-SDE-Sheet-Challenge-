#include <bits/stdc++.h> 

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>> res;
    sort(intervals.begin(),intervals.end());
    vector<int>mergeintervals=intervals[0];
    
    for(auto x:intervals)
    {
        if(mergeintervals[1]>=x[0])
            mergeintervals[1]=max(mergeintervals[1],x[1]);
        else
        {
            res.push_back(mergeintervals);
            mergeintervals=x;
        }  
          
    }
    res.push_back(mergeintervals);
    return res;
}
