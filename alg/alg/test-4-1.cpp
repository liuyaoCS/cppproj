#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 最长递增子序列的元素个数（序列长度）
// 比如a={1,5,8,2,3,4}的最长递增子序列是1,2,3,4。长度为4.

/*
思路：
我们可以得到以下关系：
    list[i]表示以i结尾（包含i）的最长递增子序列个数
    lis[i] = max{lis[j]+1}，其中j<i，a[i] > a[j] 
*/

class Solution {

public:
    int maxLength(vector<int>& a){
        vector<int> lis(a.size());
        for(int i=0;i<lis.size();i++)lis[i]=1;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<i;j++){
                //成立的话更新，否则保持
                if(a[j]<a[i]){
                    if(lis[j]+1>lis[i])
                        lis[i]=lis[j]+1;
                }
            }
        }
        int max=0;
        for(int i=0;i<lis.size();i++){
            if(lis[i]>max){
                max=lis[i];
            }
        }
        return max;
    }
};