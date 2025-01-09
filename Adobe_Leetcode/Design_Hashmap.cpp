#include<iostream>
#include<vector>
using namespace std;

class MyHashMap {
    vector<pair<int, int>> vect;
    int n;
public:
    MyHashMap() {
        n = 0;
    }
    void put(int key, int value)
    {
        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(vect[i].first == key)
            {
                break;
            }
        }
        if(i == n)
        {
            vect.push_back({key, value});
            n++;
        }
        else{
            vect[i].second = value;
        }
    }
    int get(int key)
    {
        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(vect[i].first == key)
            {
                return vect[i].second;
            }
        }
        return -1;
    }
    void remove(int key)
    {
        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(vect[i].first == key)
            {
                vect.erase(vect.begin() + i);
                n--;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */