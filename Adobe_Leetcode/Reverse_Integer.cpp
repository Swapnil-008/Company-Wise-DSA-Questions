#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        int sign;
        sign = x < 0 ? -1 : 1;
        if(x <= INT_MIN)
        {
            return 0;
        }
        x = abs(x);
        int rem, res = 0;
        while (x > 0)
        {
            rem = x % 10;
            if(res > INT_MAX / 10 || res == INT_MAX && rem > 7)
            {
                return 0;
            }
            res = res * 10 + rem;
            x = x / 10;
        }
        return res * sign;
    }
};