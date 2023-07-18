#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
   long i = 0, j = 0;
        long total = 0;
        while(j < n) {
            j = i+1;
            long sum = 0;
            while(j < n and arr[j] < arr[i]) {
                sum += arr[i]-arr[j];
                j++;
            }
            
            if(j == n) continue;
            total += sum;
            i = j;
        }
        
        long k = i;
        i = j = n-1;
        
        while(j >= k) {
            long sum = 0;
            j = i-1;
            while(j >= k and arr[j] < arr[i]) {
                sum += arr[i]-arr[j];
                j--;
            }
            
            if(j < k) continue;
            i = j;
            total += sum;
        }
        
        return total;
}
