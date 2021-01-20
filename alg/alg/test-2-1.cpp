#include <iostream>
#include <vector>
using namespace std;

// 冒泡排序

class Solution {
public:
    vector<int> bubbleSort(vector<int> a, int n) {
        for (int i = 0;i < n; i++){
            int flag = 0;
            for (int j = n - 1; j > i; j--) {// i or i-1 ?
                if (a[j] < a[j - 1]) {
                    int x = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = x;
                    flag = 1;
                }
            }
            if (flag == 0)
                break;
        }
        return a;
    }
};