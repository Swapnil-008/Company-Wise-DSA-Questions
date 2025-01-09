#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
        {
            return false;
        }
        long long int temp = 0;
        int num = x;
        while(num > 0)
        {
            int rem = num % 10;
            temp = temp*10 + rem;
            num /= 10;
        }
        return temp == x;
    }
};