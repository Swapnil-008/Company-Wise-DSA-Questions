#include <iostream>
#include <vector>
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
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        if(root == NULL)
        {
            return root;
        }
        if (root->val < low)
        {
            TreeNode* temp = root->right;
            return trimBST(temp, low, high);
        }
        if (root->val > high)
        {
            TreeNode* temp = root->left;
            return trimBST(temp, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }

    void getRange(TreeNode* root, vector<int>& range, int low, int high)
    {
        if(root != NULL)
        {
            if(root->val < low || root->val > high)
            {
                range.push_back(root->val);
            }
            getRange(root->left, range, low, high);
            getRange(root->right, range, low, high);
        }
    }
    TreeNode* deleteRecursive(TreeNode* temp, int val)
    {
        if(temp == NULL)
        {
            return NULL;
        }
        else if(val < temp->val)
        {
            temp->left = deleteRecursive(temp->left, val);
        }
        else if(val > temp->val)
        {
            temp->right = deleteRecursive(temp->right, val);
        }
        else
        {
            TreeNode* p;
            if(temp->left == NULL && temp->right == NULL)
            {
                return NULL;
            }
            if(temp->right == NULL)
            {
                p = temp->left;
                //delete temp;
                return p;
            }
            else if(temp->left == NULL)
            {
                p = temp->right;
                //delete temp;
                return p;
            }
            else
            {
                p = inorderPredecessor(temp->left);
                if(p == NULL)
                {
                    p = inorderSuccessor(temp->right);
                    temp->val = p->val;
                    temp->right = deleteRecursive(temp->right, p->val);
                }
                else
                {
                    temp->val = p->val;
                    temp->left = deleteRecursive(temp->left, p->val);
                }
                return temp;
            }
        }
        return temp;
    }

    TreeNode* inorderPredecessor(TreeNode* temp)
    {
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }

    TreeNode* inorderSuccessor(TreeNode* temp)
    {
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
};
