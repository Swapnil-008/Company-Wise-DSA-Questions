#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n = strs.size();
        string str = "";
        int minLen = INT_MAX;
        int ind = -1;
        for(int i = 0; i < n; i++)
        {
            if(minLen > strs[i].length())
            {
                minLen = strs[i].length();
                ind = i;
            }
        }
        swap(strs[0], strs[ind]);
        int i = 0;
        while(i < minLen)
        {
            int j;
            for(j = 0; j < n; j++)
            {
                if(strs[j][i] != strs[0][i])
                {
                    break;
                }
            }
            if(j != n)
            {
                break;
            }
            i++;
        }
        return strs[0].substr(0, i);
    }
};