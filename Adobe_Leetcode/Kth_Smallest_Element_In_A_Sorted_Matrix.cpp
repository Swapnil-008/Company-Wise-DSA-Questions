#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int numRows = matrix.size();
        int numCols = matrix[0].size();
        priority_queue<int, vector<int>, greater<int>> pqueue;
        int i = 0, j = 0;
        while(i < numRows)
        {
            pqueue.push(matrix[i][j]);
            j++;
            if(j != 0 && j % numCols == 0)
            {
                i++;
                j = 0;
            }
        }
        k--;
        while(k > 0)
        {
            pqueue.pop();
            k--;
        }
        return pqueue.top();
    }
};
