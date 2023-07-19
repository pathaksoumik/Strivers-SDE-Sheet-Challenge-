#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>>st;
    vector<int>res;
    st.push({INT_MAX,-1});
    
    for(int i=0;i<price.size();i++)
    {
        while(st.top().first<=price[i])
            st.pop();
        
        int ans=i-st.top().second;
        res.push_back(ans);
        
        st.push({price[i],i});
    }
    return res;
}
