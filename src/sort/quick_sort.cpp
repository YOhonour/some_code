#include <iostream>
#include <vector>

using namespace std;
void inline swap(vector<int>& nums, int a, int b);
void inline swap(int nums[],int a, int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}
//将数组划分为：左侧全部小于分割点 右侧全部大于分割点 返回的pair是等于分割点的开始地址与结束地址
pair<int,int> partation(int nums[],int l, int r){
    if(l >= r ) return {l,r};
    int target =  nums[l + (r-l)/2];
    //取中间位置的元素作为分割点 最优的情况应该是取随机一个值，这样快排的理论复杂度为 nlogn ,因为随机取的话 复杂度的数学期望是nlogn
    // https://www.bilibili.com/video/BV13g41157hK/?p=4 的2:24:52 
    
}



int main(){

}

int fastSort(vector<int>& nums,int l, int r){
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
}
void inline swap(vector<int>& nums, int a, int b){
    int t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}