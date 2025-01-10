#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int temp = prices[0];
        int profit = 0;
        for(int i = 0; i < n; i++)
        {
            temp = min(temp, prices[i]);
            profit = max(profit, prices[i] - temp);
        }
        return profit;
    }
};