#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int minElement = INT_MAX;
    int maxDiff = 0;
        
    for (int i=0; i<prices.size();  ++i)
    {
      if (prices[i] < minElement)minElement = prices[i];
        
      if (prices[i] - minElement > maxDiff)
        maxDiff = prices[i] - minElement;
    }
    return maxDiff;
}
