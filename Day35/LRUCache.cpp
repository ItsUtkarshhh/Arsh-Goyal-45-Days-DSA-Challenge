// Leetcode question number 146 :
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<int> lruList;  // stores keys in order of usage
    unordered_map<int, pair<int, list<int>::iterator>> cache;  // key -> {value, iterator to key in lruList}

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;  // key not found
        }
        
        // Move the accessed key to the front of the list (most recently used)
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();
        
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key exists, update the value and move it to the front
            lruList.erase(cache[key].second);
            lruList.push_front(key);
            cache[key] = {value, lruList.begin()};
        } else {
            // Key doesn't exist, insert it
            if (lruList.size() == capacity) {
                // Cache is full, remove the least recently used item
                int lruKey = lruList.back();
                lruList.pop_back();
                cache.erase(lruKey);
            }
            lruList.push_front(key);
            cache[key] = {value, lruList.begin()};
        }
    }
};

int main() {
    LRUCache lruCache(2);  // Cache with capacity 2
    
    lruCache.put(1, 1);
    lruCache.put(2, 2);
    cout << lruCache.get(1) << endl;  // returns 1
    lruCache.put(3, 3);  // evicts key 2
    cout << lruCache.get(2) << endl;  // returns -1 (not found)
    lruCache.put(4, 4);  // evicts key 1
    cout << lruCache.get(1) << endl;  // returns -1 (not found)
    cout << lruCache.get(3) << endl;  // returns 3
    cout << lruCache.get(4) << endl;  // returns 4

    return 0;
}
