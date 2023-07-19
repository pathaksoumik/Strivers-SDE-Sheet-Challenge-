#include <bits/stdc++.h>
int findlps(string s)
{
        
    int n = s.length(),i = 1,j = 0;
	
    vector<int> lps(n);
    while(i<n)
    {
       if(s[i] == s[j])
        {
            lps[i] =  j+1;
            i++;
            j++;
        }
            
         else
        {
            if(j>0)j = lps[j-1];
                
            else if(!j)i++;
        }
    }
        
    return lps[n-1];
}
	
int minCharsforPalindrome(string str) {
  // Write your code here.
  int n = str.size();
  string rev = str;
  reverse(rev.begin(), rev.end());

  str += '$';
  str += rev;

  int lps = findlps(str);

  int ans = n - lps;

  return ans;
}
