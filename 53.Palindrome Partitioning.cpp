#include<bits/stdc++.h> 

bool IsPalindrome(int i,int idx,string s)
    {
        while(idx<=i)
        {
            if(s[idx++]!=s[i--])return false;
        }
        return true;
    }
    
    void solve(string s,int idx,vector<vector<string>>&ans,vector<string> str)
    {
        if(idx==s.size())
        {
            ans.push_back(str);
            return;
        }
        
        for(int i=idx;i<s.size();i++)
        {
            if(IsPalindrome(i,idx,s))
            {
                str.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,ans,str);
                str.pop_back();
            }
        }
    }

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>>ans;
        vector<string> str;
        solve(s,0,ans,str);
        
        return ans;
}
