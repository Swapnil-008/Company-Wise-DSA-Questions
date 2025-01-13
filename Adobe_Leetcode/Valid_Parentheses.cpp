#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        int n = s.length();
        if(n % 2 != 0)
        {
            return false;
        }
        stack<char>stack;
        int i = 0;
        while(i < n)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stack.push(s[i]);
            }
            else{
                if(stack.empty())
                {
                    return false;
                }
                if((s[i] == ')' && stack.top() != '(') || (s[i] == '}' && stack.top() != '{') || (s[i] == ']' && stack.top() != '['))
                {
                    return false;
                }
                stack.pop();
            }
            i++;
        }
        if(!stack.empty())
        {
            return false;
        }
        return true;
    }
};