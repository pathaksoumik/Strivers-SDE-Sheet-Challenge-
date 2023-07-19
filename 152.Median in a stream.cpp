#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	
	vector<int> medians; // To store the medians
	
	// max heap
	priority_queue<int> lo;  
	
	//min heap                            
    priority_queue<int, vector<int>, greater<int>> hi;   
    
    for(int i = 0; i < n; i++){
    	
    	int num = arr[i];
    	
    	lo.push(num);                                
		
        hi.push(lo.top());                        
        lo.pop();

        if (lo.size() < hi.size())
		 {                    
            lo.push(hi.top());
            hi.pop();
        }
        
        int median;
        
        // For odd number of elements
        if(lo.size() > hi.size())
        	median = lo.top();
		
		// For even number of elements
		else	
			median = (lo.top() + hi.top())/2;  
			
    	medians.push_back(median);
	}
	
	return medians;
}
