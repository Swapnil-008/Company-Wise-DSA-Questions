#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<int> vect;
        unordered_map<int, int> umap;
        for(int i = 0; i < n; i++)
        {
            int temp = target - nums[i];
            if(umap.find(temp) != umap.end())
            {
                vect.push_back(umap[temp]);
                vect.push_back(i);
                break;
            }
            umap[nums[i]] = i;
        }
        return vect;
    }
};