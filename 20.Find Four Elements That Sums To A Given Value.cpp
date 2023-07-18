#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++)
    {
        if(i>0 and arr[i]==arr[i-1])continue;

        for(int j=i+1;j<n;j++ )
        {
            if(j>i+1 and arr[j]==arr[j-1])continue;
            int k=j+1,l=n-1;

            while(k<l)
            {
                int sum=arr[i]+arr[j];
                sum+=arr[k]; sum+=arr[l];
                if(sum==target)return "Yes";

                else if(sum<target)
                {
                    k++;
                    while(k<l and arr[k]==arr[k-1])k++;
                }
                else
                {
                    l--;
                    while(k<l and arr[l]==arr[l+1])l--;
                }
                
            }
        }
    }
    return "No";
}
