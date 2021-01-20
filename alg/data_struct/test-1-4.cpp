#include <iostream>
#include <vector>
using namespace std;

// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

// 进阶：
// 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

// 示例 1:
// 输入: nums = [1,2,3,4,5,6,7], k = 3
// 输出: [5,6,7,1,2,3,4]
// 解释:
// 向右旋转 1 步: [7,1,2,3,4,5,6]
// 向右旋转 2 步: [6,7,1,2,3,4,5]
// 向右旋转 3 步: [5,6,7,1,2,3,4]

// 示例 2:
// 输入：nums = [-1,-100,3,99], k = 2
// 输出：[3,99,-1,-100]
// 解释: 
// 向右旋转 1 步: [99,-1,-100,3]
// 向右旋转 2 步: [3,99,-1,-100]


/*
思路：源索引i，目标索引j,源值savedi，交换len次
*/

class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int i=0,j=0;
        int savedi=a[i];
        int len=a.size();
        k=k%len;
        while(len>0){
            j=i+k;
            if(j>=a.size())j-=a.size();
            int tmp=a[j];
            a[j]=savedi;
            savedi=tmp;
            
            i=j;
            len--;
        }
    }
};