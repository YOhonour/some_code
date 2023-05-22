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

ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *newH = new ListNode(0);
    newH->next = head;
    ListNode *pre = newH;
    ListNode *cur = newH->next;
    while (pre != nullptr || cur != nullptr)
    {
        pre->next = cur->next;
        cur->next = pre->next->next;
        pre->next->next = cur;
        pre = cur;
        cur = cur->next;
    }
    return newH->next;
}
int main()
{

    return 0;
}