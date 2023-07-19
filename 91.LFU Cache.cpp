#include <bits/stdc++.h> 

class LFUCache {
private:
    int capacity;
    int size;
    int minFreq;
    
    unordered_map<int, pair<int, int>> cache;  // key -> {value, frequency}
    unordered_map<int, list<int>::iterator> keyFreq;  // key -> iterator pointing to the key's position in freqList
    unordered_map<int, list<int>> freqList;  // frequency -> list of keys
    
public:
    LFUCache(int capacity) 
    {
        this->capacity = capacity;
        this->size = 0;
        this->minFreq = 0;
    }
    
    int get(int key) 
    {
        if (cache.count(key) == 0) 
            return -1;  // Key doesn't exist in the cache
        
        int value = cache[key].first;
        int freq = cache[key].second;
        
        // Update frequency
        freqList[freq].erase(keyFreq[key]);
        if (freqList[freq].empty()) 
        {
            freqList.erase(freq);
            if (freq == minFreq) 
                minFreq++;
        }
        // Increase frequency
        freqList[freq + 1].push_back(key);
        keyFreq[key] = --freqList[freq + 1].end();
        
        // Update cache
        cache[key].second = freq + 1;
        
        return value;
    }
    
    void put(int key, int value) 
    {
        if (capacity <= 0) 
            return;
        
        // Check if the key already exists
        if (cache.count(key) > 0) 
        {
            cache[key].first = value;  // Update the value
            get(key);  // Increase frequency
            return;
        }
        
        // Check if the cache is full
        if (size >= capacity) 
        {
            int evictKey = freqList[minFreq].front();
            freqList[minFreq].pop_front();
            cache.erase(evictKey);
            keyFreq.erase(evictKey);
            size--;
            
            if (freqList[minFreq].empty()) 
                freqList.erase(minFreq);
        }
        
        // Add the new key-value pair
        cache[key] = {value, 1};
        freqList[1].push_back(key);
        keyFreq[key] = --freqList[1].end();
        minFreq = 1;
        size++;
    }
};
