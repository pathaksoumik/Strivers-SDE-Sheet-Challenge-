#include <bits/stdc++.h> 
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());

	int l=0,r=positions.back(),res; 
	while(l<=r)
	{
		int mid=l+((r-l)>>1);

       int cnt=1,prev=positions[0];

		for(int i=1;i<n;i++)
		{
          if(positions[i]-prev >=mid)
		  {
			  cnt++;
			  prev=positions[i];
		  }
		}
		if(cnt>=c)res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}
