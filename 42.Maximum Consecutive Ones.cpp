#include<bits/stdc++.h>
int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int count=0,maxx=INT_MIN,l=0;
    
    for(int i=0;i<n;i++)
    {
        if(!arr[i])count++;
        
        while(count>k)
        {
            if(!arr[l])count--;
            
            l++;
        }
            maxx=max(maxx,i-l+1);
    }
    return maxx;
}
