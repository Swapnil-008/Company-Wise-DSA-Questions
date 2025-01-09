#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size();
        int i = 0;
        int j;
        while(i < n)
        {
            if(nums[i] == 0)
            {
                j = i;
                while(j < n-1)
                {
                    nums[j] = nums[j+1];
                    j++;
                }
                nums[j] = 0;
                n--;
            }
            else{
                i++;
            }
        }
    }
};