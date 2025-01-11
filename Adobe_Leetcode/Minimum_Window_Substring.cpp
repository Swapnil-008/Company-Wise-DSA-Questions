#include<iostream>
#include<vector>
#include<string>
using namespace std;

// class Solution {
// public:
//     string minWindow(string s, string t)
//     {
//         int n1 = s.length();
//         int n2 = t.length();
//         vector<int> targetFreq;
//         vector<int> sourceFreq;
//         for(char ch : t)
//         {
//             targetFreq[ch-'A']++;
//         }
//         int count1 = 0;
//         for(int i = 0; i < 26; i++)
//         {
//             if(targetFreq[i] != 0)
//             {
//                 count1++;
//             }
//         }
//         int i, j, len, minLen;
//         i = j = 0;
//         len = minLen = n2;
//         int count2 = 0;
//         string str = "";
//         while(j < n2)
//         {
//             sourceFreq[s[j] - 'A']++;
//             if(sourceFreq[s[j]-'A'] >= targetFreq[s[j]-'A'])
//             {
//                 count2++;
//             }
//             if(count2 >= count1)
//             {
//                 while(i <= j)
//                 {
//                     if(sourceFreq[s[i]-'A']-- >= targetFreq[s[i]-'A'])
//                     {
//                         i++;
//                     }
//                     else{
//                         break;
//                     }
//                 }
//             }
//             len = j - i + 1;
//             minLen = min(minLen, len);
//             str = s.substr(j - minLen + 1, j);
//         }
//         return str;
//     }
// };

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
