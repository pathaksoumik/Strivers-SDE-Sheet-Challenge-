 #include<bits/stdc++.h>
 void solve(int idx,vector<vector<int>>&ans,vector<int>store,vector<int>& candidates,int target)
    {
        //if(idx==candidates.size())return;
        if(target==0)
        {
            ans.push_back(store);
            return;
        }
          
        
            for(int i=idx;i<candidates.size();i++)
            {
                if(i>idx and candidates[i]==candidates[i-1])continue;
                if(candidates[i]>target)break;
                
                    store.push_back(candidates[i]);
                    solve(i+1,ans,store,candidates,target-candidates[i]);
                    store.pop_back();
                
            }
    }
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<vector<int>>ans;
        vector<int>store;
        
        sort(arr.begin(),arr.end());
        solve(0,ans,store,arr,target);
        
        
        return ans;
}
