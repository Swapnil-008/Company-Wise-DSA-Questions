#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words)
    {
        int n = words.size();
        vector<vector<int>> vect(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < words[i].length(); j++)
            {
                vect[i][words[i][j] - 'a']++;
            }
        }
        vector<string> result;
        for(int i = 0; i < 26; i++)
        {
            int count = vect[0][i];
            for(int j = 1; j < n; j++)
            {
                count = min(count, vect[j][i]);
            }
            while(count > 0)
            {
                result.push_back(string(1, 'a' + i));
                count--;
            }
            
        }
        return result;
    }
};