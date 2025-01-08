#include<iostream>
#include<queue>
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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *front;
        queue<ListNode*> queue;
        while (temp != NULL && temp->next != NULL)
        {
            queue.push(temp->next);
            temp = temp->next->next;
        }

        temp = head;
        head = queue.front();

        while (!queue.empty())
        {
            front = queue.front();
            queue.pop();
            temp->next = front->next;
            front->next = temp;

            if (prev != NULL)
            {
                prev->next = front;
            }
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};
