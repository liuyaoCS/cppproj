#include <iostream>
#include <vector>
using namespace std;

/**
实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须 原地 修改，只允许使用额外常数空间。
 
示例 1：
输入：nums = [1,2,3]
输出：[1,3,2]
示例 2：
输入：nums = [3,2,1]
输出：[1,2,3]
示例 3：
输入：nums = [1,1,5]
输出：[1,5,1]
示例 4：
输入：nums = [1]
输出：[1]
*/

//思路：找到尾部降序段i，在这个段落里，找到比nums[i-1]大的最小值，两者交换，并对这个降序段按升序排列

class Solution {
public:
    void nextPermutation(vector<int>& num) {
         if(num.size()==0)return;
        
        int last=num.size()-1;
        int i;
        for(i=last-1;i>=0;i--){
            if(num[i]<num[i+1])break;
        }
        if(i==-1){
            for(int l=0;l<=last/2;l++){
                int tmp=num[l];
                num[l]=num[last-l];
                num[last-l]=tmp;
            }
            return;
        }
        
        int j;
        for(j=last;j>=0;j--){
            if(num[j]>num[i])break;
        }
        int tmp=num[i];
        num[i]=num[j];
        num[j]=tmp;
        //这里逆转就可以，不必重排（因为是逆序）
        int p=i+1,q=last;
        while(p<q){
            int tmp=num[p];
            num[p]=num[q];
            num[q]=tmp;
            p++;
            q--;
        }
        
    }
};