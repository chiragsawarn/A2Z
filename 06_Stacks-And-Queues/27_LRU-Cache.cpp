// Question: Build an LRU cache with capacity K. Get and Put operations should be O(1)
// https://leetcode.com/problems/lru-cache/description/

// Tips:
// 1) Use STL's Doubly Linked List => list<T> 
// 2) Use prev(l.end()) as a proxy for tail pointer.
//    Why? Coz rbegin() gives a reverse pointer.

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    list<pair<int,int>> l;
    int k;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    LRUCache(int capacity) {
        k = capacity;
    }
    
    int get(int key) {
        auto itr = mp.find(key);
        int value = -1;
        if(itr != mp.end()){
            value = itr->second->second;
            l.erase(itr->second);
            l.push_back({key, value});
            mp[key] = prev(l.end());
        }
        return value;
    }
    
    void put(int key, int value) {
        auto itr = mp.find(key);
        if(itr == mp.end()){
            if(mp.size() == k){
                auto itrDLL = l.begin();
                int key = itrDLL->first;
                auto itrMP = mp.find(key);
                mp.erase(itrMP);
                l.erase(itrDLL);
            }
            l.push_back({key, value});
            mp[key] = prev(l.end());
        } else {
            l.erase(mp[key]);
            l.push_back({key, value});
            mp[key] = prev(l.end());
        }
    }
};

int main(){
    
    return 0;
}