#include<bits/stdc++.h>

int findMajorityElement(int arr[], int n) {	
	
    int count=0,ele=0;
    for(int i=0;i<n;i++)
    {
        if(!count)
            ele=arr[i];
        
        if(ele==arr[i]) count++;
        
        else count--;
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(ele==arr[i]) count++;
    }
    if(count>(n/2)) return ele;
    
    return -1;
}
