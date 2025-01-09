#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        int n = emails.size();
        unordered_map<string, int> umap;
        int plus, atRate;
        for(int i = 0; i < n; i++)
        {
            string str = "";
            plus = -1;
            atRate = -1;
            for(int j = 0; j < emails[i].length(); j++)
            {
                if(emails[i][j] == '+')
                {
                    plus = j;
                }
                else if(emails[i][j] == '@')
                {
                    atRate = j;
                }
                if(plus == -1 && emails[i][j] != '.')
                {
                    str += emails[i][j];
                }
                else if(atRate != -1)
                {
                    str += emails[i][j];
                }
            }
            umap[str]++;
        }
        return umap.size();
    }
};