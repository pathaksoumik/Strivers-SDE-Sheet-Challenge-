#include<bits/stdc++.h>
int cutLogs(int k, int n)
{
    // Write your code here.
    vector<vector<int>> dp(k + 1,vector<int>(n + 1, INT_MAX));

    // Base case: if n = 0, no cuts are needed
    for (int i = 1; i <= k; i++)
        dp[i][0] = 0;

    // Base case: if k = 0, no axes are available
    for (int i = 1; i <= n; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
                // If there is only one axe, number of cuts = log length
                dp[i][j] = j;
    
            else
            {
                // Using binary search to find optimal cut position
                int low = 1;
                int high = j;
                while (low <= high)
                {
                    int mid = low + (high - low) / 2;

                    int left = dp[i - 1][mid - 1];
                    int right = dp[i][j - mid];

                    dp[i][j] = std::min(dp[i][j], std::max(left, right) + 1);

                    if (left < right)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
            }
        }
    }

    return dp[k][n];
}
