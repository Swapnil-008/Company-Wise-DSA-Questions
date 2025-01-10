#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        string ans = "";
        int carry = 0;
        int res, val1, val2;
        while(i >= 0 || j >= 0 || carry)
        {
            val1 = (i >= 0) ? num1[i--] - '0' : 0;
            val2 = (j >= 0) ? num2[j--] - '0' : 0;
            res = val1 + val2 + carry;
            carry = res / 10;
            res = res % 10;
            ans += to_string(res);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};