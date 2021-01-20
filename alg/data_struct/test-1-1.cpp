#include <iostream>
#include <vector>
using namespace std;

// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:

// 输入: [-2,1,-3,4,-1,2,1,-5,4]
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int max=arr[0];      //考虑到了负数的情况    
        int segMax=arr[0];  
        
        for(int i=0;i<arr.size();i++){            
            if(segMax>=0){
                segMax+=arr[i];
            }else {
                segMax=arr[i]; 
            }
            if(segMax>max)
                max=segMax;      
        }
        
        return max;
    }
};