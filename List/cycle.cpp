#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 判断是否有环
bool hasCycle(ListNode *head)
{
    if (!head || !head->next)
        return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}

// 寻找环的入口
ListNode *detectCycle(ListNode *head)
{
    if (!head || !head->next)
        return nullptr;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if (!fast || !fast->next)
        return nullptr;
    ListNode *cur = head;
    while (cur != slow)
    {
        slow = slow->next;
        cur = cur->next;
    }
    return cur;
}

// 环的长度
int lenOfCycle(ListNode *head)
{
    if (!head || !head->next)
        return 0;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if (!fast || !fast->next)
        return 0;
    ListNode *cur = head;
    while (cur != slow)
    {
        slow = slow->next;
        cur = cur->next;
    }
    int count = 1;
    while (slow->next != cur)
    {
        count++;
        slow = slow->next;
    }
    return count;
}