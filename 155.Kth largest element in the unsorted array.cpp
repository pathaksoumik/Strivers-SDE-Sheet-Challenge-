#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int>pq;
	for(auto x:arr)pq.push(x);

	while((K--) >1)
	pq.pop();

	return pq.top();
}
