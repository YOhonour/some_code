#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

#include <algorithm>
using namespace std;
struct MyHeap
{
    int index_l;
    int index_r;
    unordered_set<int> color;
};
struct ListNode
{
    MyHeap *data = nullptr;
    ListNode *next = nullptr; // 结构体指针
};
int seed = 11111;
void test(){
        int  n = 500; // 石头堆的数量
    //cin >> n;
    vector<int> a(n);              // 每个石头的颜色
    ListNode *root = new ListNode; // 开始点
    ListNode *ptr = root;
    ListNode *end = root; // 结束点
    
	srand(seed++);
    for (int i = 0; i < n; i++)
    {
        //cin >> a[i];
        a[i] = rand() % (int)10e9;
        MyHeap *temp = new MyHeap;
        temp->index_l = i;
        temp->index_r = i;
        temp->color.insert(a[i]);
        ptr->data = temp;
        ptr->next = new ListNode;
        end = ptr;
        ptr = ptr->next;
    }
    int res = 0;
    ptr = root;
    while (n > 1 && ptr != nullptr)
    {
        ptr = root;
        int val = INT_MAX;
        ListNode *tar = ptr;
        while (ptr->data != nullptr && ptr->next->data != nullptr)
        {
            std::unordered_set<int> intersection;
            std::set_intersection(
                ptr->data->color.begin(), ptr->data->color.end(),
                ptr->next->data->color.begin(), ptr->next->data->color.end(),
                std::inserter(intersection, intersection.begin()));
            if (intersection == ptr->data->color && intersection == ptr->next->data->color)//优先考虑
            {
                tar = ptr;
                val = ptr->data->color.size() * ptr->next->data->color.size();
            }
            else
            {
                if (ptr->data->color.size() * ptr->next->data->color.size() < val)
                {
                    tar = ptr;
                    val = ptr->data->color.size() * ptr->next->data->color.size();
                }
            }

            ptr = ptr->next;
        }
        res += val;
        tar->data->color.insert(tar->next->data->color.begin(), tar->next->data->color.end());
        tar->data->index_r = tar->next->data->index_r;
        tar->next = tar->next->next;
        n--;
    }
    cout << res << endl;
}
int main()
{
    
    for (size_t i = 0; i < 100; i++)
    {
        test();
    }
    
    return 0;
}
