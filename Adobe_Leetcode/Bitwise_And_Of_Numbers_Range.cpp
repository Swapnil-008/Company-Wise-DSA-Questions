#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right)
    {
        long long int temp = left;
        for(long long int i = left; i <= right; i++)
        {
            temp = temp & i;
            if(temp == 0)
            {
                return 0;
            }
        }
        return temp;
    }
};