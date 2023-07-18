#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size(),ans = 0,currXor = 0;
    unordered_map<int, int> prefXor;

    prefXor[0]=1;

    for (int i = 0; i < n; i++)
    {
        currXor = currXor ^ arr[i];
        int req = x ^ currXor;
        ans += prefXor[req];
        prefXor[currXor]++;
    }

    return ans;
}
