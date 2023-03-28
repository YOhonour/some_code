#include <iostream>
#include <vector>

using namespace std;

void mergeSort(int nums[],int l,int r);//归并排序
int mergeRucr(int nums[],int temp[],int l,int r);//归并排序的递归体

int minplus(int nums[],int l, int r);//数组的小和问题
int merge(int nums[],int l,int m,int r);//小和问题的合并
//求逆序对
int reversePairs(int nums[],int l, int r);//C语言风格
int pairmerge(int nums[],int l,int m,int r);//逆序对的合并操作

int* mid_nums(vector<int>& nums,int ti);
void mid_nums2(vector<int>& nums,int targetIndex);
void mid_nums3(vector<int>& nums,int targetIndex);
void mid_nums4(vector<int>& nums,int targetIndex);
void mid_nums5(vector<int>& nums,int targetIndex);
int fastSort(vector<int>& nums,int l, int r);
void inline swap(vector<int>& nums, int a, int b);
void printArr(vector<int>& nums){
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ",";
    }
    cout << endl;
}
int main() {
    //int nums[] = {7,5,6,4};
    vector<int> nums2 = {14, 33, 27, 10, 35, 19,27,27,27, 42, 44,28};
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << ",";
    }
     cout << endl;
    fastSort(nums2,0,nums2.size()-1);
    // cout << inversePair(nums,0,sizeof(nums) / sizeof(int)-1) << endl;
    
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << ",";
    }
    
    return 0;
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
}
int mergeRucr(int nums[],int temp[],int l,int r){
    if (l == r) 
        return 0;
    int len = r-l;//数组长度
    int mid = l + len / 2;//中点下标
    mergeRucr(nums,temp,l,mid);//左边有序
    mergeRucr(nums,temp,mid+1,r);//右边有序
    int pl = l,pr = mid+1,p=l;
    while (pl<=mid && pr <= r)
    {
        if(temp[pl] <= temp[pr]){
            //左边小就复制左边
            nums[p] = temp[pl];
            pl++;
        }else{
            //右边小
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
    return 0;
}
/*
在一个数组中，每一个数左边比当前数小的数累加起来，叫做这个数组的小和。求一个数组的小和。
例子:  [1,3,4,2,5]
    1左边比1小的数，没有;
    3左边比3小的数，1;
    4左边比4小的数，1、3;
    2左边比2小的数，1;
    5左边比5小的数，1、3、4、2;
    所以小和为1+1+3+1+1+3+4+2=16
*/
int minplus(int nums[],int l, int r){
    if (l == r) 
        return 0;
    int mid = l + ((r-l)>>1);//中点位置
    int re = minplus(nums,l,mid) + minplus(nums,mid+1,r);
    
    return re + merge(nums,l,mid,r);
}
int merge(int nums[],int l,int m,int r){
    const int len = r-l+1;
    int swap_count = 0;
    int *help = new int[len];
    int p = 0,pl=l,pr=m+1;
    while (pl <= m && pr <= r){
        //对每个加入help的数 计算右边比它大的个数
        if(nums[pl] < nums[pr]){
            //左边小就拷贝左边 加上右边剩余的个数
            swap_count += (r-pr+1)*nums[pl];
            help[p++] = nums[pl++];
        }else{
            //拷贝右边 
            help[p++] = nums[pr++];
        }
    }
    while (pl <= m){
        help[p++] = nums[pl++];
    }
    while (pr <= r){
        help[p++] = nums[pr++];
    }
    for (int i = 0; i < len; i++)
    {
        nums[l+i] = help[i];
    }
    return swap_count; 
}
//逆序对问题
/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
*/
int reversePairs(int nums[],int l, int r){
    if (l == r) 
        return 0;
    int mid = l + ((r-l)>>1);//中点位置
    int re = reversePairs(nums,l,mid);
    re +=  + reversePairs(nums,mid+1,r);
    return re + pairmerge(nums,l,mid,r);
}
//使用归并排序的方式  C语言方式 
int pairmerge(int nums[],int l,int m,int r){
    
    const int len = r-l+1;
    int swap_count = 0;
    int *help = (int *)malloc(len * sizeof(int));//这里优化一下不要每次都申请
    int p = 0,pl=l,pr=m+1;
    while (pl <= m && pr <= r){
        //对每个加入help的数 计算右边比它大的个数
        if(nums[pl] > nums[pr]){
            //拷贝右边 
            swap_count += (m-pl+1);
            cout << nums[pl] << ":" << nums[pr] << endl;
            help[p++] = nums[pr++];
        }else{
            help[p++] = nums[pl++];
        }
    }
    while (pl <= m){
        help[p++] = nums[pl++];
    }
    while (pr <= r){
        help[p++] = nums[pr++];
    }
    for (int i = 0; i < len; i++)
    {
        nums[l+i] = help[i];
    }
    return swap_count; 
}

/*
给定一个数组arr，,和一个数num，请把小于等于num的数放在数组的左边，大于num的数放在数组的右边。
要求额外空间复杂度0(1)，时间复杂度O(N)
*/
int* mid_nums(vector<int>& nums,int ti){
    int *l_nums = new int[nums.size()];
    int *r_nums = new int[nums.size()];
    int pl = 0, pr = 0;
    r_nums[pr++] = nums[ti];
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == ti) continue;
        nums[i] <= nums[ti] ? l_nums[pl++] = nums[i] : r_nums[pr++] = nums[i];
    }
    int *re = new int[nums.size()];
    int p = 0;
    while (p < pl) re[p++] = l_nums[p];
    int p2 = 0;
    while (p2 < pr){
        re[p+p2] = r_nums[p2];
        p2++;
    } 
    return re;
}
//上一个不行
// 下面的采用快排的思想，前后边界两个指针，依次向中间
void mid_nums2(vector<int>& nums,int targetIndex){
    int pl = 0,pr = nums.size()-1;
    int p = targetIndex;
    while (pl < pr)
    {
        while (nums[pl] <= nums[p]) pl++;
        int t = nums[pl];
        nums[pl] = nums[p];
        nums[p] = t;
        p = pl;
        pl++;
        while (nums[p] < nums[pr]) pr--;
        t = nums[pr];
        nums[pr] = nums[p];
        nums[p] = t;
        p = pr;
        pr--;
    }
    
}
// 快慢指针 小于等于区域在左边
void mid_nums3(vector<int>& nums,int target){
    int p = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= target)
        {
            //比目标小的交换到小于区边界的前一个（添加完成后
            int t = nums[p+1];
            nums[p+1] = nums[i];
            nums[i] = t;
            p++;
        }
    }
    return;
}
// 双指针 小于区域在左边 等于区域在中间 大于区域在左边
void mid_nums4(vector<int>& nums,int target){
    int lower_p = -1,equal_p = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < target)
        {
            //比目标小的交换到小于区边界的前一个（添加完成后
            int t = nums[lower_p+1];
            nums[lower_p+1] = nums[i];
            nums[i] = t;
            lower_p++;
            equal_p++;
        }else if (nums[i] == target){
            int t = nums[equal_p+1];
            nums[equal_p+1] = nums[i];
            nums[i] = t;
            equal_p++;
        }
    }
    cout << "lower ptr: " << lower_p << "  equal prt : " << equal_p << endl;
    return;
}
//上面的问题换一个方法 不要等于区域 使用大于区域 i指针为待定区域的指针 当i撞到大于区域时就结束了
void mid_nums5(vector<int>& nums,int target){
    int lower_p = -1,bigger_p = nums.size();
    int i = lower_p + 1;
    while (i < bigger_p)
    {
        if (nums[i] < target)
        {
            //比目标小的交换到小于区边界的前一个（添加完成后
            int t = nums[lower_p+1];
            nums[lower_p+1] = nums[i];
            nums[i] = t;
            lower_p++;
            i++;
        }else if (nums[i] > target){
            int t = nums[bigger_p-1];
            nums[bigger_p-1] = nums[i];
            nums[i] = t;
            bigger_p--;
        }else{
            i ++;
        }
    }
    cout << "lower ptr: " << lower_p << "  bigger prt : " << bigger_p << endl;
    return;
}

void inline swap(vector<int>& nums, int a, int b){
    int t = nums[a];
    nums[a] = nums[b];
    nums[b] = t;
}



