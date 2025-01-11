#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Using stack
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        stack<int> stack;
        while(slow != NULL)
        {
            stack.push(slow->val);
            slow = slow->next;
        }
        ListNode *temp = head;
        while(!stack.empty())
        {
            if(temp->val != stack.top())
            {
                return false;
            }
            stack.pop();
            temp = temp->next;
        }
        return true;
    }
};

//Using reverse to Half Linked List
class Solution {
public:
    bool isPalindrome(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        stack<int> stack;
        while(slow != NULL)
        {
            stack.push(slow->val);
            slow = slow->next;
        }
        ListNode *temp = head;
        while(!stack.empty())
        {
            if(temp->val != stack.top())
            {
                return false;
            }
            stack.pop();
            temp = temp->next;
        }
        return true;
    }
};

