#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int i = 0;
        int len = 0, maxLength = 0;
        unordered_map<char, int> umap;
        for(int j = 0; j < n; j++)
        {
            if(umap.find(s[j]) != umap.end())
            {
                i = max(i, umap[s[j]] + 1);
            }
            umap[s[j]] = j;
            len = j - i + 1;
            maxLength = max(len, maxLength);
        }
        return maxLength;
    }
};