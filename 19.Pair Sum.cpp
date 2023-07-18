#include<bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write code here
    vector<vector<int>> ans;

    map<int, int> mp;
    vector<int> keyArray;
    for (int num : arr) 
    {
        if(!mp.count(num))
            keyArray.push_back(num);

        // Store frequency of each unique element.
        mp[num] += 1;
    }
    
    sort(keyArray.begin(), keyArray.end());
    
    for (int key : keyArray) 
    {
        if (key + key == s) 
        {
            int freq = mp[key];

            // Total number of such pairs will be 'FREQ*(FREQ-1)/2'.
            for (int j = 0; j < freq * (freq - 1) / 2; j++) 
                ans.push_back({ key, key }); 
        }
    }

  
    int low = 0, high = keyArray.size() - 1;

    while (low < high) 
    {
        int currSum = keyArray[low] + keyArray[high];

        // If the current sum is equal to the target sum.
        if (currSum == s) 
        {
            int freq = mp[keyArray[low]] * mp[keyArray[high]];

            // Total number of such pairs will be 'FREQ'.
            for (int j = 0; j < freq; j++) 
                ans.push_back({ keyArray[low], keyArray[high] });
            
            low++;
            high--;
        }
        else if (currSum < s) low++;
        
        else high--;
    }

    for (int i = 0; i < ans.size(); i++) 
    {
        int a = ans[i][0], b = ans[i][1];
        ans[i][0] = min(a, b);
        ans[i][1] = max(a, b);
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
