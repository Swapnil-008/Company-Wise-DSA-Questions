#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<string, int> umap;
        umap["I"] = 1;
        umap["IV"] = 4;
        umap["V"] = 5;
        umap["IX"] = 9;
        umap["X"] = 10;
        umap["XL"] = 40;
        umap["L"] = 50;
        umap["XC"] = 90;
        umap["C"] = 100;
        umap["CD"] = 400;
        umap["D"] = 500;
        umap["CM"] = 900;
        umap["M"] = 1000;
        int sum = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(i < s.length() - 1 && umap.find(s.substr(i, 2)) != umap.end())
            {
                sum += umap[s.substr(i, 2)];
                i++;
            }
            else{
                sum += umap[s.substr(i, 1)];
            }
        }
        return sum;
    }
};