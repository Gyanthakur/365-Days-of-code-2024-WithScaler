
// https://interviewbit.com/problems/lru-cache/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n; // n is the maximum capacity of the Cache

vector<pair<int, int>> v; // Cache memory

map<int, int> m; // using map to store the values of every key
// this map will help us to find the values of a particular key when we want to search a particular pair in our cache vector.

int LRUCache(int capacity)
{
    n = capacity;
    v.clear();
    m.clear();
}

int get(int key)
{
    if (m.find(key) == m.end())
        return -1;

    pair<int, int> p = {key, m[key]};

    vector<pair<int, int>>::iterator it;

    it = find(v.begin(), v.end(), p);

    if (it == v.end())
        return -1;

    else
    {
        v.erase(it); // if we use get function of a value then we have to put it in the most recently used position after removing from that position where it was present.
        v.push_back(p);
        return m[key];
    }
}

void set(int key, int value)
{
    if (m.find(key) == m.end())
    {
        if (v.size() == n)
        {
            v.erase(v.begin()); // if value is not present in vector and vector size is already equal to the capacity than we have to remove the least recently used element which is at the begin of the vector.
        }
        v.push_back({key, value}); // push the pair to the most recently used position
        m[key] = value;
    }
    else
    {
        vector<pair<int, int>>::iterator it;

        pair<int, int> p = {key, m[key]};

        it = find(v.begin(), v.end(), p); // when key and value is present in map then we will search it in our cache vector

        if (it != v.end())
        {
            v.erase(it); // if it is present in the Cache we will remove it from that position and will add it to the most recently used position.
        }
        else
        {
            if (v.size() == n)
                v.erase(v.begin()); // if that is not present in vector than we will just remove the least recently used element from our cache and add the given key and value
        }
        v.push_back({key, value});

        m[key] = value;
    }
}
