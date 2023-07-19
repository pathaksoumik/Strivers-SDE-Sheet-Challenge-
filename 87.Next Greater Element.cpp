#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int>res(arr.size());
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        while(st.top()<=arr[i] && st.top()!=-1)st.pop();
        
        res[i]=st.top();
        st.push(arr[i]);
    }
    return res;
}
