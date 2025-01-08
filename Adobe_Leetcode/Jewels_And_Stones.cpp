#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int n = stones.size();
        unordered_map<char, int> umap;
        for(int i = 0; i < n; i++)
        {
            umap[stones[i]]++;
        }
        n = jewels.size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(umap.find(jewels[i]) != umap.end())
            {
                count += umap[jewels[i]];
            }
        }
        return count;
    }
};