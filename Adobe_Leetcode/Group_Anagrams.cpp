#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>>umap;
        for(string &str : strs)
        {
            string temp = str;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(str);
        }
        for(auto temp : umap)
        {
            result.push_back(temp.second);
        }
        return result;
    }
};