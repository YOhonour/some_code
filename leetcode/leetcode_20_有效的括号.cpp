#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
bool isValid(string s)
{

    unordered_map<char, char> map;
    map.insert({')', '('});
    map.insert({']', '['});
    map.insert({'}', '{'});
    stack<char> stack;
    for (int i = 0; i < s.size(); i++)
    {
        if (stack.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack.push(s[i]);
        }
        else if (stack.top() == map[s[i]])
        {
            stack.pop();
        }
        else
        {
            return false;
        }
    }
    if (!stack.empty())
    {
        return false;
    }

    return true;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *merge(ListNode *a, ListNode *b)
{
    ListNode *head = nullptr, *ptr = nullptr;
    if (a == nullptr)
    {
        return b;
    }
    if (b == nullptr)
    {
        return a;
    }
    if (a->val >= b->val)
    {
        head = a;
        a = a->next;
    }
    else
    {
        head = b;
        b = b->next;
    }
    ptr = head;
    while (a != nullptr && b != nullptr)
    {
        if (a->val >= b->val)
        {
            ptr->next = a;
            a = a->next;
        }
        else
        {
            ptr->next = b;
            b = b->next;
        }
        ptr = ptr->next;
    }
    while (a != nullptr)
    {
        ptr->next = a;
        a = a->next;
        ptr = ptr->next;
    }
    while (b != nullptr)
    {
        ptr->next = b;
        b = b->next;
        ptr = ptr->next;
    }
    return head;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    queue<ListNode *> queue;
    for(auto it : lists){
        queue.push(it);
    }
    while (queue.size() > 1)
    {
        auto a = queue.front();
        queue.pop();
        auto b = queue.front();
        queue.pop();
        auto t = merge(a,b);
        queue.push(t);
    }
    return queue.front();
}
int main()
{
    isValid("()");
    return 0;
}