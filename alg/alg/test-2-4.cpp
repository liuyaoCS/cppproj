#include <iostream>
#include <vector>
using namespace std;

// 堆排序

/*
思路：
index从1开始，0处置-1，这样符合child=2*parent(+1);
heapLen这里为a.length-1;
建堆：从堆长一半位置循环向前down
排序：从堆顶和堆最后位置交换，并且维护规模减去1的堆
*/

class Solution {
public:
    void deapSort(vector<int> &a,int heapLen){
        for(int i=heapLen/2;i>=1;i--)down(a,i,heapLen);

        for(int j=heapLen;j>1;j--){
            swap(a[1],a[j]);
            down(a,1,j-1);
        }
    }
    void down(vector<int> &a,int i,int len){
        int tmp=a[i];
        int hole=i;
        int child=i*2;
        while((child<=len && a[child]>tmp) || (child+1<=len && a[child+1]>tmp)){
            if(child+1<=len && a[child+1]>tmp && a[child+1]>a[child])child++;
            
            a[hole]=a[child];
            hole=child;
            child=2*hole;
        }
        a[hole]=tmp;
    }

};