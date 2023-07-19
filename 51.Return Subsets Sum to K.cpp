vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    //sort(arr.begin(),arr.end());
    
    vector<vector<int>>res;
    //map<vector<int>,int>s;
    for(int i=0;i<(1<<n);i++)
    {
        vector<int>ans;
        int sum=0;
        for(int j=0;j<n;j++)
            if((1<<j)&i)
            {
                ans.push_back(arr[j]);
                sum+=arr[j];
            }
        
        if(sum==k)
         res.push_back(ans);
          
     }

    //sort(res.begin(),res.end());
    return res;
}
