#include<bits/stdc++.h>
  vector<int>nextSmallertoRight(vector<int>& heights)
    {
        int n=heights.size();
        vector<int>res(n);
        stack<int>st; st.push(-1);
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!=-1 and heights[st.top()]>=heights[i])
                st.pop();
            
            res[i]=st.top(); st.push(i);
        }
        return res;
    }
    
    
    vector<int>nextSmallertoLeft(vector<int>& heights)
    {
        int n=heights.size();
        vector<int>res(n);
        stack<int>st; st.push(-1);
        
        for(int i=0;i<n;i++)
        {
            while(st.top()!=-1 and heights[st.top()]>=heights[i])
                st.pop();
            
            res[i]=st.top(); st.push(i);
        }
        return res;
    }
 
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int n=heights.size();
        vector<int>ngl(n); ngl= nextSmallertoRight(heights);
        vector<int>nsl(n); nsl=nextSmallertoLeft(heights);
        
        
        int maxx=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            if(ngl[i]==-1)ngl[i]=n;
            
            int width=ngl[i]-nsl[i]-1;
            
            maxx=max(maxx,l*width);
        }
        return maxx;
 }
