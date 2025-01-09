#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        int i = a.length()-1;
        int j = b.length()-1;
        int num1, num2, res;
        string ans = "";
        int carry = 0;
        while(i >= 0 || j >= 0 || carry)
        {
            num1 = (i >= 0) ? a[i--] - '0' : 0;
            num2 = (j >= 0) ? b[j--] - '0' : 0;
            res = num1 + num2 + carry;
            carry = res / 2;
            res = res % 2;
            ans += to_string(res);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};