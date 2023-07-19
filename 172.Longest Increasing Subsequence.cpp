#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int>res;
    res.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
     if(arr[i]>res.back())res.push_back(arr[i]);
        else
        {
        int ind=lower_bound(res.begin(),res.end(),arr[i])-res.begin();
        res[ind]=arr[i];
        }
    }
    return res.size();
}
