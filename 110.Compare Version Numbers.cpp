#include <bits/stdc++.h> 
vector<string> split(string& str, char delimiter) 
{
    vector<string> segments;
    int start = 0,end = 0;
    
    while ((end = str.find(delimiter, start)) != string::npos) 
    {
        segments.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    
    segments.push_back(str.substr(start));
    return segments;
}

int compareVersions(string a, string b) 
{
    // Write your code here
    vector<string> segmentsA = split(a, '.');
    vector<string> segmentsB = split(b, '.');

    int n = segmentsA.size(),m = segmentsB.size(), maxLength = max(n, m);

    for (size_t i = 0; i < maxLength; i++) 
    {
        double numA = i < n ? stod(segmentsA[i]) : 0.0;
        double numB = i < m ? stod(segmentsB[i]) : 0.0;

        if (numA > numB) 
            return 1; // Version a is greater
        
        else if (numA < numB) 
            return -1; // Version a is smaller
    }

    return 0; // Versions are equal

}
