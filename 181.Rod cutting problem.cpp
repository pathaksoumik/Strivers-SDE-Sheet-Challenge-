int f(int ind,int length,vector<int> &price,vector<vector<int>>&dp)
  {
      if(ind==0)return length*price[ind];
      
      if(dp[ind][length]!=-1)return dp[ind][length];
      
      int rodlength=ind+1;
      int nottake=0+f(ind-1,length,price,dp);
      int take=INT_MIN;
      if(rodlength<=length)take=price[ind]+f(ind,length-rodlength,price,dp);
      
      return dp[ind][length]=max(nottake,take);
  }

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
}
