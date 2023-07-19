#include<bits/stdc++.h>
bool wordBreak(vector < string > & arr, int n, string & target) {
   
    unordered_set<string> s;
   
    for (string str: arr) 
        s.insert(str);
    
    vector<bool> dp(target.size() + 1, false);

    dp[0] = true;

    for (int i = 1; i <= target.size(); ++i) 
    {
        for (int j = i - 1; j >= 0; --j) 
        {
            if (dp[j])
            {
                if (s.find(target.substr(j, i - j)) != s.end()) 
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[target.size()];
}
