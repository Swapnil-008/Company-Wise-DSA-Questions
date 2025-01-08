#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        int n = s.length();
        if(numRows == 1)
        {
            return s;
        }
        int i = 0, row = 0;
        vector<string> vect(numRows);
        bool direction = true;
        while(true)
        {
            if(direction)
            {
                while(row < numRows && i < n)
                {
                    vect[row].push_back(s[i]);
                    i++;
                    row++;
                }
                row -= 2;
            }
            else{
                while(row >= 0 && i < n)
                {
                    vect[row].push_back(s[i]);
                    i++;
                    row--;
                }
                row += 2;
            }
            if(i >= n)
            {
                break;
            }
            direction = !direction;
        }
        string result = "";
        for(string str : vect)
        {
            result += str;
        }
        return result;
    }
};