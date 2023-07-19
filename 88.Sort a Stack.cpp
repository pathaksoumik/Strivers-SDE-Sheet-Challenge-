#include <bits/stdc++.h> 
void sortStack(stack<int> &stack)
{
	// Write your code here
	vector<int>v;
    while(!stack.empty())
    {
        v.push_back(stack.top());
        stack.pop();
    }
    sort(v.begin(),v.end());
    
    for(auto x:v)
        stack.push(x);
}
