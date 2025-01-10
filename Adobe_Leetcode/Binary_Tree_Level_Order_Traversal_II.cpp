#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// By just reversing the sequence of arrays
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>>result;
        queue<TreeNode*> queue1, queue2;
        if(root == NULL)
        {
            return {};
        }
        queue1.push(root);
        while(!queue1.empty())
        {
            vector<int> vect;
            while(!queue1.empty())
            {
                TreeNode *temp = queue1.front();
                queue1.pop();
                vect.push_back(temp->val);
                if(temp->left != NULL)
                {
                    queue2.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    queue2.push(temp->right);
                }
            }
            result.push_back(vect);
            swap(queue1, queue2);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//By using deque for arranging arrays in reverse order
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>>result;
        queue<TreeNode*> queue1, queue2;
        deque<vector<int>> deque;
        if(root == NULL)
        {
            return {};
        }
        queue1.push(root);
        while(!queue1.empty())
        {
            vector<int> vect;
            while(!queue1.empty())
            {
                TreeNode *temp = queue1.front();
                queue1.pop();
                vect.push_back(temp->val);
                if(temp->left != NULL)
                {
                    queue2.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    queue2.push(temp->right);
                }
            }
            deque.push_front(vect);
            swap(queue1, queue2);
        }
        while(!deque.empty())
        {
            result.push_back(deque.front());
            deque.pop_front();
        }
        return result;
    }
};