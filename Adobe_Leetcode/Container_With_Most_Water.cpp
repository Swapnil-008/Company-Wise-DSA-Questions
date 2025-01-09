#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int water, maxWater = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right)
        {
            water = min(height[left], height[right]) * (right - left);
            maxWater = max(maxWater, water);
            if(height[left] < height[right])
            {
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};