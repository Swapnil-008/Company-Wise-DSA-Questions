#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> vect(n+1, 0);
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0 && nums[i] <= n)
            {
                vect[nums[i]] = 1;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(vect[i] == 0)
            {
                return i;
            }
        }
        return n+1;
    }
};