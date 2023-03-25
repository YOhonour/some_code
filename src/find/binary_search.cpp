#include <iostream>

using namespace std;

int binary_search_big_or_even(int nums[], int left_index, int right_index, int target);
int binary_search_curr(int nums[], int left_index, int right_index, int target);
int bi_min(int nums[], int N);
int rurr(int nums[],int l,int r);
int maxInArr(int nums[],int L, int R);
int main() {
    int nums[] = {15,17,423,19,27,33,35,42,44,221};
    int nums1[] = {1,1,2,2,2,3,3,4,4,4,4,4,4,5,5};
    //int index =  binary_search_curr(nums,0,sizeof(nums) / sizeof(int)-1,27);
    //int index =  binary_search_big_or_even(nums1,0,sizeof(nums1) / sizeof(int),4);
    //int index = maxInArr(nums,0,sizeof(nums) / sizeof(int)-1);
    // if (index == -1)
    // {
    //     cout << "no result" <<endl;
    // }else
    //     cout << "nums[" << index << "]=" <<nums1[index] <<endl;
    
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    mergeSort(nums,0,sizeof(nums) / sizeof(int)-1);
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
    {
        cout << nums[i] << " ";
    }
    
    
    return 0;
}


///////////////////////////////////////////////////////////////
int binary_search_curr(int nums[], int left_index, int right_index, int target){
    int avg = (left_index + right_index) / 2;
    if (nums[avg] == target) return avg;
    if (left_index == right_index){
        return -1;
    }
    if ( target > nums[avg]){
        return binary_search_curr(nums,avg,right_index,target);
    }else {
        return binary_search_curr(nums,left_index,avg,target);
    }
}
///////////////////////////////////////////////////////////////
//大于等于num最左侧的位置
int binary_search_big_or_even(int nums[], int left_index, int right_index, int target){
    // int avg = (left_index + right_index) / 2;
    int avg = left_index + (right_index - left_index) / 2;//防止数组过长而越界
    if (left_index == right_index ){//为避免 (6+7)/2 == 6 由于int类型省略小数导致的不收敛
        return avg;
    }
    if ( target <= nums[avg]){
        return binary_search_big_or_even(nums,left_index,avg,target);//中心点的值大于等于target时说明，所求的大于等于target的值最左边的数的位置在左半区
    }else {
        return binary_search_big_or_even(nums,avg+1,right_index,target);//小于则说明在右半区
    }
}
///////////////////////////////////////////////////////////////
//在无序列表中搜索最大的数值的下标
int maxInArr(int nums[],int L, int R){
    if(L==R) return L;
    int mid = L + (R - L) / 2;
    int lm = maxInArr(nums,L,mid);
    int rm = maxInArr(nums,mid+1,R);
    return nums[lm] > nums[rm] ? lm : rm;
}

///////////////////////////////////////////////////////////////
//不相等的序列中局部最小 
// 局部最小的定义：假设nums[i] < nums[i-1] 且 nums[i] < nums[i+1], 称nums[i]为局部最小。端点时只用考虑一侧即可
int bi_min(int nums[], int N)//N为数组长度
{
    if (nums[0] < nums[1])// 0 时只用考虑两个 
    {
        return 0;
    }
    if (nums[N-1] < nums[N-2]) // 右边端点同理
    {
        return N-1;
    }
    // nums[]
    
    int avg = (N-1) / 2;
    if (nums[avg] < nums[avg+1] && nums[avg] < nums[avg-1])
    {
        return avg;// 首次尝试中点
    }
    if (nums[avg] < nums[avg+1] && nums[avg] > nums[avg-1])
    // 到这里时，已经确定两端点的数值状态为： \ /
    // 又因为序列中数值都不同，说明一定存在局部最小
    // 就可以根据 中点两侧的数值判断往哪一侧寻找，
    // 中点有两种形态  \  \(中点三个数)  / ；  \  /(中点三个数)  /
    //说明分别在右侧、左侧寻找
    {
        return rurr(nums,0,avg);
    }else
        return rurr(nums,avg,N-1);
}
///////////////////////////////////////////////////////////////
//求局部最小的递归体
//数组 左端下标 右边下标
int rurr(int nums[],int l,int r){
    int avg = l + (r-l) / 2;//求中点下标
    if (nums[avg] < nums[avg+1] && nums[avg] < nums[avg-1])//如果此时中点位置的值满足局部最优的定义直接返回
    {
        return avg;
    }
    if (nums[avg] < nums[avg+1] && nums[avg] > nums[avg-1])
    {
        return rurr(nums,l,avg);
    }else
        return rurr(nums,avg+1,r);
}
