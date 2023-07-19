#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
   int res=0, neg=1;
   for(auto x:str)
   {
       if(x>='0' and x<='9')
       {
           res=(res*10)+(x-'0');
       }
   }
   if(str[0]=='-')neg=-1;
   return neg*res;
}
