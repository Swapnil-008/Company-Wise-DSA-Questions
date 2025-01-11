#include<iostream>
#include<vector>
using namespace std;


//using DP
class Solution {
public:
    int fib(int n)
    {
        vector<int> dp(n+1);
        for(int i = 0; i <= n; i++)
        {
            if(i <= 1)
            {
                dp[i] = i;
            }
            else{
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }
};

//using recursion
class Solution {
public:
    int fib(int n)
    {
        if(n <= 1)
        {
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};

//Iterative
class Solution {
public:
    int fib(int n)
    {
        if(n <= 1)
        {
            return n;
        }
        int f1, f2;
        int num = 0;
        f1 = 0;
        f2 = 1;
        int i= 2;
        while(i <= n)
        {
            num = f1 + f2;
            f1 = f2;
            f2 = num;
            i++;
        }
        return num;
    }
};