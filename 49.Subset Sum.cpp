vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int n=num.size();
    vector<int>res;
    for(int i=0;i<(1<<n);i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if((1<<j)&i)sum+=num[j];
        }
        res.push_back(sum);
    }
    sort(res.begin(),res.end());
    
    return res;
}
