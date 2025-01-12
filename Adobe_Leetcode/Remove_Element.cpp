#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int i = 0;
        int j = nums.size()-1;
        int n = 0;
        while(i <= j)
        {
            if(nums[i] == val && nums[j] != val)
            {
                n++;
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            else if(nums[i] == val && nums[j] == val)
            {
                n++;
                j--;
            }
            else{
                i++;
            }
        }
        return nums.size()-n;
    }
};