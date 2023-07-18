#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end()); // removing repeating elements
    
    int count=0,maxx=INT_MIN;
    for(int i=0;i<n-1;i++)
    {
        if((arr[i+1]-arr[i])==1)
        {
            count++;
            maxx=max(maxx,count);
        }
        else count=0;
    }
    return max(maxx,count)+1;
}
