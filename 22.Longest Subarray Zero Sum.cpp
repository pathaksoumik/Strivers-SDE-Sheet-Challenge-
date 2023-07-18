#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  unordered_map<int,int>mp;
    int sum=0;
    mp[0]=-1;
    int maxx=0;
   for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        if(mp.find(sum)!=mp.end())
            maxx=max(maxx,i-mp[sum]);
        else  mp[sum]=i;
    }
    return maxx;

}
