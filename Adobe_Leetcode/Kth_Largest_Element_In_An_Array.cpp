#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> pqueue;
        for(int num : nums)
        {
            pqueue.push(num);
        }
        while(!pqueue.empty())
        {
            k--;
            if(k == 0)
            {
                return pqueue.top();
            }
            pqueue.pop();
        }
        return pqueue.top();
    }
};