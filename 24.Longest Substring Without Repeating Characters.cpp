#include <bits/stdc++.h> 
int uniqueSubstrings(string str)
{
    //Write your code here
    unordered_map<char, int> mp;
    int ans = 0, i = 0, j = 0,n=str.size();

    while (i < n && j < n) 
    {
        if (mp.find(str[j]) == mp.end()) 
        {
            mp[str[j]] = 1;
            ans = max(ans, j - i + 1);
            j++;
        } 
        
        else 
        {
            mp.erase(str[i]);
            i++;
        }
    }
    return ans;
}
