#include<iostream>
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
    bool isValidBST(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root->left != NULL)
        {
            int leftMax = maxElement(root->left);
            if(leftMax >= root->val)
            {
                return false;
            }
        }
        if(root->right != NULL)
        {
            int rightMin = minElement(root->right);
            if(rightMin <= root->val)
            {
                return false;
            }
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
    int maxElement(TreeNode* temp)
    {
        if(temp == NULL)
        {
            return INT_MIN;
        }
        int leftVal = maxElement(temp->left);
        int rightVal = maxElement(temp->right);
        return max(temp->val, max(leftVal, rightVal));
    }
    int minElement(TreeNode* temp)
    {
        if(temp == NULL)
        {
            return INT_MAX;
        }
        int leftVal = minElement(temp->left);
        int rightVal = minElement(temp->right);
        return min(temp->val, min(leftVal, rightVal));
    }
};