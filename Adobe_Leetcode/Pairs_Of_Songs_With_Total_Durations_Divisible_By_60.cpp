#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        int n = time.size();
        vector<int> vect(60, 0);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            int temp = time[i] % 60;
            if(temp == 0)
            {
                count += vect[0];
            }
            else{
                count += vect[60-temp];
            }
            vect[temp]++;
        }
        return count;
    }
};