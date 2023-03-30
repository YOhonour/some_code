#include <iostream>
#include <vector>



using namespace std;

void quick_sort(vector<int>& nums,int l, int r);
int fastSort(vector<int>& nums,int l, int r);
int getRandInt(int min,int max);
void swap(vector<int>& nums, int a, int b);
pair<int,int> partation(vector<int>& nums,int l, int r, int target);

int main(){
    vector<int> nums = {1,8,2,7,3,6,4,5,5,5};
    quick_sort(nums,0,nums.size() -1);
    
    return 0;
}
void quick_sort(vector<int>& nums,int l, int r){
    if (l >= r)
    {
        return;
    }
    
    int target =  nums[getRandInt(l,r)];
    auto a = partation(nums,l,r,target);
    quick_sort(nums,l,a.first-1);
    quick_sort(nums,a.second+1,r);
}


// 输入：l->左指针，r为右指针地址 将数组划分为：左侧全部小于分割点 右侧全部大于分割点 返回的pair是等于分割点的开始地址与结束地址
pair<int,int> partation(vector<int>& nums,int l, int r, int target){
    if(l >= r ) return {l,r};
    //取中间位置的元素作为分割点 最优的情况应该是取随机一个值，这样快排的理论复杂度为 nlogn ,因为随机取的话 复杂度的数学期望是nlogn
    // https://www.bilibili.com/video/BV13g41157hK/?p=4 的2:24:52 
    int smaller_index = l-1;
    int bigger_index = r+1;//大于区的
    int equal_end = l-1;
    int i = l;
    while (i < bigger_index)
    {
        if(nums[i] > target){
            //将待定元素交换到 大于区的
            swap(nums,i,--bigger_index);
        } else if(nums[i] < target){
            swap(nums,i,++smaller_index);
            equal_end++;
            i++;
        } else{
            swap(nums,i,++equal_end);
            i++;
        }
    }
    return {smaller_index+1,bigger_index-1};
}





int fastSort(vector<int>& nums,int l, int r){//没有区分等于区域
    if (l >= r || l < 0 || r >= nums.size()) return 0;//边界条件
    int target = nums[l + (r-l)/2];//取中间位置的元素作为分割点
    int lower_p = l-1,bigger_p = r + 1;
    int i = lower_p + 1;
    while (i < bigger_p)
    {
        if (nums[i] < target)
        {
            //比目标小的交换到小于区边界的前一个（添加完成后
            swap(nums,i,lower_p+1);
            lower_p++;
            i++;
        }else if (nums[i] > target){
            swap(nums,i,bigger_p-1);
            bigger_p--;
        }else{
            i ++;
        }
    }
    // printArr(nums);
    fastSort(nums,l,lower_p);//小于区域
    fastSort(nums,bigger_p,r);//大于区域
    return 0;
}

int getRandInt(int min,int max){
    //srand(time()) // include<ctime>
    // return ( rand() % (max - min + 1) ) + min ;// include<cstdlib>
    return min + (max - min) / 2;
}
void swap(vector<int>& nums, int a, int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}