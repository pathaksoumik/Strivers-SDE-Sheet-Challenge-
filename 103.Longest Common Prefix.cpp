string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    if (n == 0) 
        return "";
    
    string prefix = arr[0];  // Assume the first string as the initial common prefix
    
    for (int i = 1; i < n; i++) 
    {
        while (arr[i].find(prefix) != 0) 
        {
            prefix = prefix.substr(0, prefix.length() - 1);
            
            // If prefix becomes empty, there is no common prefix
            if (prefix.empty()) 
                return "";   
        }
    }
    
    return prefix;
}


