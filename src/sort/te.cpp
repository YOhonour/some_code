#include <iostream>
#include <vector>

using namespace std;

int mergeSort(vector<int>& nums,int l,int r);
int mergeRucr(vector<int>& nums,int temp[],int l,int r);
int main() {
    // int nums[] =  {14, 33, 27, 10, 35, 19, 42, 44};

    vector<int> nums = {7,5,6,4};
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        cout << nums[i] << ",";
    }
    cout << endl;
    cout << mergeSort(nums,0,nums.size()-1) << endl;
    
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        cout << nums[i] << ",";
    }
    
    return 0;
}
int mergeSort(vector<int>& nums,int l,int r){
    int len = r-l+1;//数组长度
    int mid = l + (r-l) / 2;//中点下标
    int *temp = new int[len];
    for (int i = 0; i < len; i++)
    {
        temp[i] = nums[i];
    }
    
    return mergeRucr(nums,temp,l,r);
}
int mergeRucr(vector<int>& nums,int temp[],int l,int r){
    if (l == r) 
        return 0;
    int len = r-l + 1;//数组长度
    int mid = l + (r-l) / 2;//中点下标
    int re = mergeRucr(nums,temp,l,mid) + mergeRucr(nums,temp,mid+1,r);
    int pl = l,pr = mid+1,p=l;
    while (pl<=mid && pr <= r)
    {
        if(temp[pl] <= temp[pr]){
            nums[p] = temp[pl];
            pl++;
        }else{
            re += (mid-pl+1);
            nums[p] = temp[pr];
            pr++;
        }
        p++;
    }
    if(pl > mid){
        while(pr <= r){
            nums[p] = temp[pr];
            pr++;
            p++;
        }
    }else{
        while(pl <= mid){
            nums[p] = temp[pl];
            pl++;
            p++;
        }
    }
    for (int i = l; i <= r; i++)
    {
        temp[i] = nums[i];
    }
    return re;
}