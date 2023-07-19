#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    return is_permutation(str1.begin(),str1.end(),str2.begin());
}
