#include <bits/stdc++.h> 

class TrieNode 
{
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() 
    {
        isEndOfWord = false;
    }
};

void insert(TrieNode* root, const string& word)
 {
    TrieNode* curr = root;

    for (char ch : word) 
    {
        if (curr->children.find(ch) == curr->children.end()) 
            curr->children[ch] = new TrieNode();
        curr = curr->children[ch];
    }
    curr->isEndOfWord = true;
}

bool isCompleteString(TrieNode* root, const string& word)
 {
    TrieNode* curr = root;

    for (char ch : word)
     {
        if (curr->children.find(ch) == curr->children.end()) 
            return false;
        
        curr = curr->children[ch];
        if (!curr->isEndOfWord) 
            return false;
    }

    return true;
}

string completeString(int n, vector<string>& a) 
{
    TrieNode* root = new TrieNode();

    // Build the Trie
    for (const string& str : a) 
        insert(root, str);
    
    string longestString = "";
    for (const string& str : a) 
    {
        if (isCompleteString(root, str)) 
        {
            if (str.length() > longestString.length() || (str.length() == longestString.length() && str < longestString)) 
                longestString = str;
        }
    }

    if (longestString.empty()) 
        return "None";
     
     return longestString;
}
