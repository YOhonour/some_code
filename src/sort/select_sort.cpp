#include <iostream>

using namespace std;

void swap(int *a, int * b);//交换
void selection_sort(int nums[], int begin_index, int len);//选择排序
void bobble_sort(int nums[], int begin_index, int len);//冒泡排序
void insert_sort(int nums[], int begin_index, int len);//插入排序
void mergeSort(int nums[],int l,int r);//归并排序
int mergeRucr(int nums[],int temp[],int l,int r);//归并排序的递归体

int main() {
    int nums[] =  {14, 33, 27, 10, 35, 19, 42, 44};
    mergeSort(nums,0,sizeof(nums) / sizeof(int)-1);
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        cout << nums[i] << ",";
    }
    
    return 0;
}
void selection_sort(int nums[], int begin_index, int len){
    for (int i = begin_index; i < len; i++) {
        int target = i;
        for (int j = i+1; j < len; j++)
        {
            if (nums[j+1] > nums[j]) target = j;
        }
        swap(nums+i, nums+target);
    }
}
void bobble_sort(int nums[], int begin_index, int len){
    for (int i = begin_index; i < len; i++) {
        for (int j = begin_index + 1; j < len - i; j++)
        {
            if (nums[j - 1] > nums[j]) swap(nums+j-1, nums+j);
        }
    }
}
void insert_sort(int nums[], int begin_index, int len){
    for (int i = begin_index + 1; i < len; i++) {
        for (int j = i; j > begin_index && nums[j - 1] > nums[j]; j--){
	        swap(nums+j-1, nums+j);
        }
    }
}


void swap(int *a, int * b){
    int t = *a;
    *a = *b;
    *b = t;
}
///////////////////////////////////////////////////////////////
void mergeSort(int nums[],int l,int r){
    int len = r-l+1;//数组长度
    int mid = l + (r-l) / 2;//中点下标
    int *temp = new int[len];
    for (int i = 0; i < len; i++)
    {
        temp[i] = nums[i];
    }
    
    mergeRucr(nums,temp,l,r);
    delete temp;
}
int mergeRucr(int nums[],int temp[],int l,int r){
    if (l == r) 
        return 0;
    int len = r-l;//数组长度
    int mid = l + len / 2;//中点下标
    mergeRucr(nums,temp,l,mid);//左边有序
    mergeRucr(nums,temp,mid+1,r);//右边有序
    int pl = l,pr = mid+1,p=l;
    while (pl<=mid && pr <= r)//合并过程 三个while
        temp[pl] <= temp[pr] ? nums[p++] = temp[pl++] : nums[p++] = temp[pr++];
    while(pr <= r)
        nums[p++] = temp[pr++];
    while(pl <= mid)
        nums[p++] = temp[pl++];
    
    for (int i = l; i <= r; i++)//再把已经排好序的复制到临时数组以供上一层合并使用
    {
        temp[i] = nums[i];
    }
    return 0;
}