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

class Solution {
public:
    void reorderList(ListNode* head)
    {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return;
        }
        stack<ListNode*> stack;
        ListNode *middle = middleNode(head);
        ListNode *temp = head;
        ListNode *top;
        ListNode* middleNext = middle->next;
        middle->next = NULL;                        //This is for dividing the list in two halves
        while(middleNext != NULL)
        {
            stack.push(middleNext);
            middleNext = middleNext->next;
        }
        while(!stack.empty())
        {
            top = stack.top();
            stack.pop();
            top->next = temp->next;
            temp->next = top;
            temp = top->next;
        }
    }
    ListNode *middleNode(ListNode *temp)
    {
        ListNode* slow = temp;
        ListNode* fast = temp;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};