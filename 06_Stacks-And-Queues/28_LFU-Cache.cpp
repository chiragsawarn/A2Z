// Question: Make a Least Frequntly Used (LFU) Cache with Capacity K
//           When 2 items have same frequncy, remove the one which is least recently used (LRU)
//           Both get() and put() operations must be O(1)
// https://leetcode.com/problems/lfu-cache/

// Learnings : -
// 1) In LRU, we have : u_map<key, list<Node>::iterator> and list<Node>
//    In LFU, we have : u_map<key, list<Node>::iterator> and  u_map<freq, list<Node>> 
//            map<freq, list<Node>> because we need to maintain LRU eviction policy for same frequency elements.
// 2) The Node will contain {key, value, freq}. 
//      With key we can trace it back to map1 : u_map<key, Node *>
//      With freq we can trace it in map2 : u_map<freq, list<Node>>
// 3) IMPORTANT: How I have maintained leastFreq to keep things O(1).
#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    struct Node{
        int key, value, freq;
    };
    unordered_map<int, list<Node>::iterator> mp;
    unordered_map<int, list<Node>> freqDLL;
    int k, leastFreq;

    LFUCache(int capacity) {
        k = capacity;
        leastFreq = 1;
    }
    
    int get(int key) {
        auto itr = mp.find(key);
        if(itr == mp.end()) return -1;

        int freq = itr->second->freq;
        int value = itr->second->value;
        freqDLL[freq].erase(itr->second);
        freqDLL[freq+1].push_back({key, value, freq+1});
        mp[key] = prev(freqDLL[freq+1].end());

        if(freq == leastFreq && freqDLL[freq].empty()){
            leastFreq = leastFreq + 1;
        }

        return value;
    }
    
    void put(int key, int value) {
        auto itr = mp.find(key);
        if(itr == mp.end()){
            if(mp.size() == k){
                int lruKey = freqDLL[leastFreq].begin()->key;
                mp.erase(mp.find(lruKey));
                freqDLL[leastFreq].erase(freqDLL[leastFreq].begin());
            }
            freqDLL[1].push_back({key, value, 1});
            mp[key] = prev(freqDLL[1].end());
            leastFreq = 1;
        } else {
            int freq = itr->second->freq;
            freqDLL[freq].erase(itr->second);
            freqDLL[freq+1].push_back({key, value, freq+1});
            mp[key] = prev(freqDLL[freq+1].end());

            if(freq == leastFreq && freqDLL[freq].empty()){
                leastFreq = leastFreq + 1;
            }
        }
    }
};

int main(){
    
    return 0;
}