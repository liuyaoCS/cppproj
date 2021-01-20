#include <iostream>
#include <vector>
using namespace std;

// 给定一个直方图(也称柱状图)，假设有人从上面源源不断地倒水，最后直方图能存多少水量?直方图的宽度为 1。
// 示例:

// 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出: 6

/*
思路1：如下代码
思路2：如何能存水？两边高，中间低-> 循环遍历，找到一个这样特征的求一个存水值
*/

class Solution {
public:
    int trap(vector<int>& a) {
        if(a.size()==0 || a.size()==0)return 0;
        int max=0,m=0;
        for(int i=0;i<a.size();i++){
            if(a[i]>max){
                max=a[i];
                m=i;
            }
        }

        int maxWater=0;
        int topL=0;
        for(int i=0;i<m;i++){
            if(a[i]>=topL)topL=a[i];
            else maxWater+=topL-a[i];
        }

        int topR=0;
        for(int i=a.size()-1;i>m;i--){
            if(a[i]>topR)topR=a[i];
            else maxWater+=topR-a[i];
        }
        return maxWater;
    }
};