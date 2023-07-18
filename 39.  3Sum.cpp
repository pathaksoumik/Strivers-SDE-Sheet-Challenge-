#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	for(int i=0;i<n;i++)
	{
		if(i>0 and arr[i]==arr[i-1])continue;
		int j=i+1;
		int k=n-1;

        while (j < k) 
		{
        int sum=arr[i]+arr[j]+arr[k];
		if(sum==K)
		{
         vector<int>temp={arr[i],arr[j],arr[k]};
		 ans.push_back(temp);
		 j++; k--;
		 while(j<k and arr[j]==arr[j-1])j++;
		 while(j<k and arr[k]==arr[k+1])k--;
		}

		else if(sum<K)
		{
         j++;
		 while(j<k and arr[j]==arr[j-1])j++;
		}
		else if(sum>K)
		{
		k--; 	
		 while(j<k and arr[k]==arr[k+1])k--; 
		}

        }
    }
		return ans;
}
