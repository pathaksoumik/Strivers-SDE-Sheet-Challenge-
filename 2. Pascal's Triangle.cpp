#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> sol;
  for(int row=1;row<=n;row++)
  {
    vector<long long int>res; res.push_back(1);
    long long int ans=1;
    for(int col=1;col<row;col++)
    {
      ans*=(row-col);
      ans/=col;
      res.push_back(ans);
    }
   sol.push_back(res);
  }
  return sol;
}
