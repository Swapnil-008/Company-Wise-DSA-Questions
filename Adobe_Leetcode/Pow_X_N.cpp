#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if(n < 0)
        {
            x = 1/x;
            N = -N;
        }
        double temp;
        if(N == 0)
        {
            return 1;
        }
        else{
            if(N % 2 != 0)
            {
                temp = myPow(x, N / 2);
                return temp * temp * x;
            }
            else{
                temp = myPow(x, N / 2);
                return temp * temp;
            }
        }
    }
};