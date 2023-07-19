#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for(int i=0;i<(1<<n);i++)
    {
        int sum=0;
        for(int j=0;j<n;j++){
            if((1<<j)&i)
                sum+=arr[j];
        }
        if(sum==k)return true;   
     }
     return false;
}
