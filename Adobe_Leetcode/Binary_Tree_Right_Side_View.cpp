#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> vect;
        queue<TreeNode*>queue1, queue2;
        if(root == NULL)
        {
            return {};
        }
        TreeNode *view;
        queue1.push(root);
        while(!queue1.empty())
        {
            while(!queue1.empty())
            {
                view = queue1.front();
                queue1.pop();
                if(view->left != NULL)
                {
                    queue2.push(view->left);
                }
                if(view->right != NULL)
                {
                    queue2.push(view->right);
                }
            }
            vect.push_back(view->val);
            swap(queue1, queue2);
        }
        return vect;
    }
};