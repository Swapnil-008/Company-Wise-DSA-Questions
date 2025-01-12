#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>result;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int i = 1;
        int currStart, currEnd;
        while(i < n)
        {
            currStart = intervals[i][0];
            currEnd = intervals[i][1];
            if (currStart <= end)
            {
                end = max(end, currEnd);
            }
            else{
                result.push_back({start, end});
                start = currStart;
                end = currEnd;
            }
            i++;
        }
        result.push_back({start, end});
        return result;
    }
};