#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(nums.size() < 4)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        set<vector<int>> set;
        int i = 0, j;
        int left, right;
        while(i < n - 3)
        {
            j = i + 1;
            while(j < n - 2)
            {
                left = j + 1;
                right = n - 1;
                while(left < right)
                {
                    vector<int> vect;
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target)
                    {
                        vect.push_back(nums[i]);
                        vect.push_back(nums[j]);
                        vect.push_back(nums[left]);
                        vect.push_back(nums[right]);
                        if(set.find(vect) == set.end())
                        {
                            set.insert(vect);
                            result.push_back(vect);
                        }
                        left++;
                        right--;
                    }
                    else if(sum < target)
                    {
                        left++;
                    }
                    else{
                        right--;
                    }
                }
                j++;
            }
            i++;
        }
        return result;
    }
};