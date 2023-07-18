#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long s=0,maxx=0;
        for(long long i=0;i<n;i++)
        {
            s+=arr[i];
            maxx=max(s,maxx);
            if(s<0) s=0;
        }
        return maxx;
}
