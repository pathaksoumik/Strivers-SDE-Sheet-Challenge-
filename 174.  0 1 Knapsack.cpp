#include<bits/stdc++.h>
int f(int ind,vector<int> &values, vector<int> &weights, 
              int w,vector<vector<int>>&dp)
{
    if(ind==0)
    {
        if(w>=weights[ind])return values[ind];
        return 0;
    }
    if(dp[ind][w]!=-1)return dp[ind][w];
    int nottake=0+f(ind-1,values,weights,w,dp);
    int take=INT_MIN;
    if(w>=weights[ind])take=values[ind]+f(ind-1,values,weights,w-weights[ind],dp);
    
    return dp[ind][w]=max(take,nottake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, 
              int w)
{
	// Write your code here
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return f(n-1,values,weights,w,dp);
}
