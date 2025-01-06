#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        permutations(nums, result, 0);
        return result;
    }
    void permutations(vector<int> &nums, vector<vector<int>> &result, int ind)
    {
        if(ind == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int j = ind; j < nums.size(); j++)
        {
            swap(nums[ind], nums[j]);
            permutations(nums, result, ind+1);
            swap(nums[ind], nums[j]);     //for undo the swap to create other permutations
        }
    }
};