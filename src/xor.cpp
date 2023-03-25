#include <iostream>

using namespace std;


pair<int ,int > find(int nums[], int size){
    int a = nums[0];
    for (int i = 1; i < size; i++) a ^= nums[i];
    int x = a;
    int mask = 1;
    //while ((a & mask) == 0) mask <<= 1;
    mask = a & (~a + 1);
    for (int i = 0; i < size; i++) {
        if ((nums[i] & mask) == 0) x = a ^ nums[i];
    }
    return {x,x^a};
}
int main() {
    int nums[] = {2,2,2,2,6,5};
    int * arr = (int *)malloc(sizeof(int) * 10);
    cout << "size of arr :" << sizeof(arr) / sizeof(arr[0]) << endl;
    auto p = find(nums,sizeof(nums) / sizeof(nums[0]));
    cout << p.first << " " << p.second << endl;
    return 0;
}