#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st;
    st.push(-1);
    vector<int>res(n);

    for(int i=n-1;i>=0;i--)
    {
        while(st.top()>=arr[i] and st.top()!=-1)st.pop();

        res[i]=st.top();
        st.push(arr[i]);
    }
    return res;
}
