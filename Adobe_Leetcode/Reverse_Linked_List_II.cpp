#include<iostream>
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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (head == NULL || head->next == NULL || left == right)
        {
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *start = dummy;
        for (int i = 1; i < left; i++)
        {
            start = start->next;
        }
        ListNode *prev = NULL;
        ListNode *curr = start->next;
        ListNode *nxt;
        for (int i = 0; i <= right - left; i++)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        start->next->next = curr;
        start->next = prev;

        return dummy->next;
    }
};
