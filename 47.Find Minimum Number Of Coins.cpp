#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>coins= {1,2,5,10,20,50,100,500,1000};
    int res=0;

    for(int i=coins.size()-1;i>=0;i--)
    {
        res+=amount/coins[i];
        amount%=coins[i];
    }
     return res;
}
