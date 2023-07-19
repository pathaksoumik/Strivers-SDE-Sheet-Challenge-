#include <bits/stdc++.h> 
int maximumProduct(vector<int> &nums, int n)
{
	// Write your code here
int maxx=nums[0],minn=nums[0],res=nums[0];
        
  for(int i=1;i<nums.size();i++)
   {
     if(nums[i]<0) swap(maxx,minn);

     maxx=max(nums[i],nums[i]*maxx);
     minn=min(nums[i],nums[i]*minn);//3
            
     res=max(res,maxx);//15
   }

 return res;
}
