#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        int n1 = s.length();
        int n2 = t.length();

        if (n1 < n2)
        {
            return "";
        }

        vector<int> targetFreq(128, 0);
        vector<int> sourceFreq(128, 0);
        for (char ch : t)
        {
            targetFreq[ch]++;
        }

        int targetCount = 0;
        for (int freq : targetFreq)
        {
            if (freq > 0)
            {
                targetCount++;
            }
        }
        int i = 0, j = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = 0;
        while (j < n1)
        {
            sourceFreq[s[j]]++;
            if (sourceFreq[s[j]] == targetFreq[s[j]])
            {
                count++;
            }
            while (count == targetCount)
            {
                int len = j - i + 1;
                if (len < minLen)
                {
                    minLen = len;
                    start = i;
                }
                sourceFreq[s[i]]--;
                if (sourceFreq[s[i]] < targetFreq[s[i]])
                {
                    count--;
                }
                i++;
            }
            j++;
        }
        if(minLen == INT_MAX)
        {
            return "";
        }
        return s.substr(start, minLen);
    }
};
