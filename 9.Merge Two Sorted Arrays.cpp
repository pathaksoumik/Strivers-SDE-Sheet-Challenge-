#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int i=m-1, j=n-1,lastidx=m+n-1;
    
    while(j>=0)
    {
        if(i>=0 and arr1[i]>arr2[j])
        {
            arr1[lastidx]=arr1[i];
            i--;lastidx--;
         }
        else 
        {
          arr1[lastidx]=arr2[j];
            j--;lastidx--;
        }
    }
  return arr1;
}
