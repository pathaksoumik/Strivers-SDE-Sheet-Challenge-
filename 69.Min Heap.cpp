#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> results;
   priority_queue<int,vector<int>,greater<int>> heap;

    for (auto &query : q)
    {
        int operation = query[0];

        if (operation == 0) 
        {
            int x = query[1];
            heap.push(x);
        }
        else if (operation == 1) 
        {
            if (!heap.empty())
             {
                int minElement = heap.top();
                heap.pop();
                results.push_back(minElement);
            }
        }
    }

    return results;
    
}
