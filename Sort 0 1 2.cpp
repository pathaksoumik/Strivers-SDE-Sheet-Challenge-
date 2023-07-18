#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
  int low = 0, mid = 0, high = n-1;
   while(mid <= high)
   {
      if(!arr[mid]) // value is 0
      {
         swap(arr[low], arr[mid]);
         low++;
         mid++;
      }
      else if(arr[mid]==1) // value is 1
                mid++;
            
      else    // value is 2
      {
      swap(arr[mid], arr[high]);
      high--;
      }
   }
}
