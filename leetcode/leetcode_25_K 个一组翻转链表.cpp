#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 翻转链表
// ListNode *reverseCurr(ListNode *head, int k)
// {
//     if (head == nullptr || head->next == nullptr)
//     {
//         return head;
//     }
// }

//翻转链表
ListNode *reverse(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *t = nullptr;
    while (cur != nullptr)
    {
        t = cur->next;
        cur->next = pre;
        pre = cur;
        cur = t;
    }
    return pre;
}
//搜索k个节点 end为本组k个节点中的末尾元素，last为下一组的开头元素
bool tryK(ListNode *head, int k, ListNode **end, ListNode **last)
{
    ListNode *ptr = head;
    int off = 1;
    while (ptr != nullptr && off < k)
    {
        ptr = ptr->next;
        off++;
    }
    if (off < k || ptr == nullptr)
    {
        *end = ptr;
        *last = nullptr;
        return false;
    }
    *end = ptr;
    *last = ptr->next;
    return true;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (k == 1)
    {
        return head;
    }
    ListNode *newH = new ListNode(0), *ptr, *end = nullptr, *last = nullptr;
    newH->next = head;
    ListNode *pre = newH;
    ListNode *cur = head;
    while (tryK(cur, k, &end, &last) == true)
    {
        end->next = nullptr;
        pre->next = reverse(cur);
        cur->next = last;
        
        pre = cur;
        cur = cur->next;
    }
    return newH->next;
}

int main()
{
    ListNode *head = new ListNode(0), *ptr, *end, *last;
    ptr = head;
    for (size_t i = 1; i < 5; i++)
    {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }

    auto a = reverseKGroup(head, 2);
    return 0;
}