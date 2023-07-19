#include <bits/stdc++.h> 
struct Node 
{
    Node *bits[2];
    void put(int bit, Node* node)
    {   
        bits[bit] = node;
    } 

    bool contains(int bit)
    {
        return bits[bit] != NULL;
    }   

    Node* next(int bit)
    {
        return bits[bit];
    }
};

class Trie {
private:
    Node *root;
public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node* temp = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num & (1 << i)) != 0 ? 1 : 0;
            if(!temp -> contains(bit))
            {   
                temp -> put(bit, new Node());
            }
            temp = temp -> next(bit);
        }
    }
    int maxXOR(int num)
    {
        int res = 0;
        Node *temp = root;
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num & (1 << i)) != 0 ? 1 : 0;
            int a = (bit == 1) ? 0 : 1;
            if(temp -> contains(a))
            {
                res = (res | (1 << i));
                temp = temp -> next(a);
            }
            else
            {
                temp = temp -> next(bit);
            }
        }
        return res;
    }
};


int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie trie;
        for(auto a : A)
            trie.insert(a);
        
        int res = 0;
        for(auto a : A)
        {
            int val = trie.maxXOR(a);
            res = max(res, val);
        }
        return res;
}
