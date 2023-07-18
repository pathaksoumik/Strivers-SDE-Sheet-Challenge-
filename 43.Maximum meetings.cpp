int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
     vector<pair<int,int>>v;
    int n=start.size();
    for(int i = 0; i < n; i++)
        v.push_back({end[i], start[i]});
        
        sort(v.begin(), v.end());

        int i = 0, j = 1, ans = 1;
        while(i < n && j < n)
        {
            if(v[j].second > v[i].first)
            {
                ans++;
                i = j;
            }
            j++;
        }
        return ans;
}
