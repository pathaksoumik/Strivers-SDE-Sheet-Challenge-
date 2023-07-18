#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int res=0,miss,rep;

    for(auto x:arr)res^=x;

    for(int i=1;i<=n;i++)res^=i;
	
    int rsb=res&(-res);
    
    int x=0,y=0;
    for(auto ele:arr)
    {
        if((ele&rsb))x^=ele;
        else y^=ele;
    }
    for(int i=1;i<=n;i++)
    {
        if((i&rsb))x^=i;
        else y^=i;
    }
    
    for(auto ele:arr)
    {
        if(x==ele)rep=x,miss=y;
        else if(y==ele) rep=y,miss=x;
    }
    
    return {miss,rep};
}
