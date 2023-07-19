#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> g, s;
   
    for (int i = 0; i < n; i++) 
    {
        s.push(arr[i]);
        int temp = s.top();
        s.pop();
       
        // Negation for treating it as min heap
        g.push(-1 * temp);
        if (g.size() > s.size()) 
        {
            temp = g.top();
            g.pop();
            s.push(-1 * temp);
        }
        
        if (g.size() != s.size())
            cout << s.top() << " ";
        else
            cout << ((s.top() - g.top() ) / 2)<< " ";
    }
}
