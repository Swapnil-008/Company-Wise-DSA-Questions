#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address)
    {
        int n = address.length();
        string str = "";
        int i = 0;
        while(i < n)
        {
            if(address[i] == '.')
            {
                str += "[.]";
            }
            else{
                str += address[i];
            }
            i++;
        }
        return str;
    }
};