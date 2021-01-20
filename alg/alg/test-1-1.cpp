#include <iostream>
#include <vector>
using namespace std;

// 二分查找

class Solution {
public:
    int binarySearch(vector<int>& a,int left,int right,int target){
        if(left>right)return -1;
        int mid=(left+right)/2;
        if(target==a[mid])return mid;
        else if(target>a[mid])return binarySearch(a,mid+1,right,target);
        else return binarySearch(a,left,mid-1,target);
    }
    int binarySearch(vector<int>& a,int target){
        int ret=-1;
        int left=0;
        int right=a.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            //如果有重复元素，需要加入左边或者右边在没越界的情况下是否和target相同（解决：1target个数 2target的最大最小下界）
            if(target==a[mid]){   
                ret=mid;
                break;
            }
            else if(target<a[mid]){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ret;
    }
};