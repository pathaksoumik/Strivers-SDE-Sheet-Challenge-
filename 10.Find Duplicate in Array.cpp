#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	unordered_map<int,int>mp;
	for(auto x:arr)
	{
		mp[x]++;
	}
	int repeat=0;
	for(auto x:mp)
	{
		if(x.second>1)
		{
			repeat=x.first;
			break;
		}
	}
	return repeat;
}
