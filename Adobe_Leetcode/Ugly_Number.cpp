#include<iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n)
    {
        if(n == 0)
        {
            return false;
        }
        int i = 2;
        while(true)
        {
            if(n % i == 0)
            {
                n /= i;
            }
            else{
                i++;
            }
            if(i > 5)
            {
                return false;
            }
            if(n == 1)
            {
                break;
            }
        }
        return true;
    }
};