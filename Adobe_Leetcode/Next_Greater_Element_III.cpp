#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n)
    {
        vector<int> nums;
        string str = to_string(n);
        //Extract the digits from given number
        for(int i = 0; i < str.length(); i++)
        {
            nums.push_back(str[i] - '0');
        }
        nextPermutation(nums);
        long long int temp = 0;
        //Convert the vector to a number
        for(int i = 0; i < nums.size(); i++)
        {
            temp = temp * 10 + nums[i];
        }
        //Check if the number is valid, if the number is lesser than or equal to n or next greater elements is beyond INT_MAX then it will be invalid
        if(temp <= n || temp > INT_MAX )
        {
            return -1;
        }
        return temp;
    }
    //find Next permutation of given number
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int ind = -1;
        //finding the digit which is lesser than other digits of right side
        //that digit is the break point
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                ind = i;
                break;
            }
        }
        //if no any digit is found it means nums contains the highes possible digit from given digits
        if(ind == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else{
            //find the smallest digit which is greater than nums[ind] / break point
            for(int i = n-1; i > ind; i--)
            {
                if(nums[i] > nums[ind])
                {
                    swap(nums[i], nums[ind]);
                    break;
                }
            }
            //sort the right side of break point in ascending order so that right side digits will generate maximum number
            reverse(nums.begin() + ind + 1, nums.end());
        }
    }
};