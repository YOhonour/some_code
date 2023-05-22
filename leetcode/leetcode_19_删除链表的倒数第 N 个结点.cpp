#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *ptr = head;
    ListNode *myNewHead = new ListNode;
    myNewHead->next = head;
    int len = 0;
    while (ptr != nullptr)
    {
        len ++;
        ptr = ptr->next;
    }
    ptr = myNewHead;
    for (int i = 0; i < len-n; i++)
    {
        ptr = ptr->next;
    }
    ptr->next = ptr->next->next;
    return myNewHead->next;
}
int main()
{
    ListNode h(1);
    removeNthFromEnd(&h,1);
    return 0;
}