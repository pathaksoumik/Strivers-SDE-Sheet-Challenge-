#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> nums, int n) {
    // Write your code here.
    deque<int>dq;
    vector<int>ans;
           
        for(int i=0;i<n;i++) //For the first window
        {
            while(!dq.empty()&&nums[i]>=nums[dq.back()])
            dq.pop_back();
            dq.push_back(i);
        }
        //store the maximum element in a first window
        ans.push_back(nums[dq.front()]);

        for(int i=n;i<nums.size();i++)
        {
            if(!dq.empty()&&i-n>=dq.front())
                dq.pop_front();
            
           while(!dq.empty()&&nums[i]>=nums[dq.back()])
            dq.pop_back();
            
            dq.push_back(i);

        ans.push_back(nums[dq.front()]);
        }

         return ans;
}
