#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> vect;
        findingSubsets(nums, vect, result, 0);
        return result;
    }
    // void findingSubsets(vector<int> &nums, vector<int> &vect, vector<vector<int>>&result, int ind)
    // {
    //     if(ind == nums.size())
    //     {
    //         result.push_back(vect);
    //         return;
    //     }
    //     findingSubsets(nums, vect, result, ind+1);
    //     vect.push_back(nums[ind]);
    //     findingSubsets(nums, vect, result, ind+1);
    //     vect.pop_back();
    // }
    void findingSubsets(vector<int> &nums, vector<int> vect, vector<vector<int>> &result, int ind)
    {
        result.push_back(vect);
        for(int i = ind; i < nums.size(); i++)
        {
            vect.push_back(nums[i]);
            findingSubsets(nums, vect, result, i+1);
            vect.pop_back();
        }
    }
};