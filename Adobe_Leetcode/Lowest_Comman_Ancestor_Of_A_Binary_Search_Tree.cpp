#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> queue;
        queue.push(root);
        int levelSize = 1;
        TreeNode *ancestor;
        while (!queue.empty())
        {
            TreeNode *temp = queue.front();
            if (search(temp, p->val) && search(temp, q->val))
            {
                ancestor = temp;
            }
            queue.pop();
            levelSize--;
            if (temp->left != NULL)
            {
                queue.push(temp->left);
            }
            if (temp->right != NULL)
            {
                queue.push(temp->right);
            }
            if (levelSize == 0)
            {
                levelSize = queue.size();
            }
        }
        return ancestor;
    }
    bool search(TreeNode *temp, int target)
    {
        if (temp == NULL)
        {
            return false;
        }
        if (target == temp->val)
        {
            return true;
        }
        if (target < temp->val)
        {
            return search(temp->left, target);
        }
        else if (target > temp->val)
        {
            return search(temp->right, target);
        }
        else
        {
            return search(temp->left, target) && search(temp->right, target);
        }
    }
};