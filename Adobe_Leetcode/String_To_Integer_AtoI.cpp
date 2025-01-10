#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int myAtoi(string s)
    {
        int n = s.length();
        int first = -1;
        int last = n;
        int sign = 1;
        int i = 0;
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i < n && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < n && s[i] == '0')
        {
            i++;
        }
        if (i < n && isdigit(s[i]))
        {
            first = i;
        }
        while(i < n)
        {
            if (!isdigit(s[i]))
            {
                last = i;
                break;
            }
            i++;
        }
        if (first == -1)
        {
            return 0;
        }
        long long res = 0;
        for (i = first; i < last; i++)
        {
            res = res * 10 + (s[i] - '0');
            if (res * sign >= INT_MAX)
            {
                return INT_MAX;
            }
            if (res * sign <= INT_MIN)
            {
                return INT_MIN;
            }
        }
        return res * sign;
    }
};
