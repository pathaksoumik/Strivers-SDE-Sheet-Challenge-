#include<bits/stdc++.h>
class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;  // key -> {value, iterator}
    list<int> lruList;  // Keeps track of the most recently used keys (from front to back)

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) 
    {
        if (!cache.count(key)) 
            return -1;  // Key doesn't exist in the cache
        

        // Move the key to the front of the lruList
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();

        return cache[key].first;
    }

    void put(int key, int value) 
    {
        if (cache.count(key) > 0) 
        {
            // Key already exists, update its value and move it to the front of the lruList
            cache[key].first = value;
            lruList.erase(cache[key].second);
            lruList.push_front(key);
            cache[key].second = lruList.begin();
        } 
        else 
        {
            // Key doesn't exist, check if cache is full
            if (cache.size() >= capacity) 
            {
                // Remove the least recently used key
                int lruKey = lruList.back();
                lruList.pop_back();
                cache.erase(lruKey);
            }

            // Add the new key-value pair to the cache and lruList
            lruList.push_front(key);
            cache[key] = {value, lruList.begin()};
        }
    }
};
