#include <iostream>
#include <vector>
using namespace std;

// 快速排序（数组：基于插入，链表:基于值交换）

/*
链表思路：
立马就会想到指针交换。对于这道题，我们完全可以利用值交换来达到排序的目的。
    链表节点交换需要头尾指针
    如果只有一个头指针，左侧的快拍需要遍历到尾巴节点，用于重构整个大链表
快排需要一个指针指向头，一个指针指向尾，然后两个指针相向运动并按一定规律交换值，对于单链表我们没有前驱指针？我们只能使两个指针都往next方向移动并且能找到支点那就好了。
    我们的目的是两个指针遍历，最终达到pivot----p------q,也就是p之前的都是比pivot小的，p之后的到q都是比pivot大的，最后交换pivot和p的val
    我们只需要两个指针p和q，这两个指针均往next方向移动，移动的过程中保持p之前的key都小于选定的key，p和q之间的key都大于选定的key，那么当q走到末尾的时候便完成了一次支点的寻找。
*/

struct Node{
    int key;
    Node* next;
};
class Solution {
public:
    //数组
    int getPivotIndex(vector<int> &a,int left,int right){
        int pivot=a[left];
        while(left<right){
            while(left<right && a[right]>=pivot)right--;
            a[left]=a[right];
            while(left<right && a[left]<=pivot)left++;
            a[right]=a[left];
        }
        a[left]=pivot;
        return left;
    }
    void quickSort(vector<int> &a,int left,int right){
        if(left<right){
            int index=getPivotIndex(a,left,right);
            quickSort(a,left,index-1);
            quickSort(a,index+1,right);
        }
    }
    
    //链表
    Node* getPivotIndex(Node* pBegin, Node* pEnd){
        int key = pBegin->key;
        Node* p = pBegin;
        Node* q = p->next;
    
        while(q != pEnd){
            if(q->key < key){
                p = p->next;
                swap(p->key,q->key);
            }
            q = q->next;
        }
        swap(p->key,pBegin->key);
        return p;
    }
    //pEnd初始为NULL
    void quickSort(Node* pBeign, Node* pEnd){
        if(pBeign != pEnd){
            Node* index = getPivotIndex(pBeign,pEnd);
            quickSort(pBeign,index);
            quickSort(index->next,pEnd);
        }
    }

};