#include <iostream>
#include <vector>
using namespace std;

// 归并排序（数组/链表:时间复杂度还是nlgn）

/*

*/

struct ListNode{
    int val;
    ListNode* next;
};
class Solution {
public:
    //数组
    void mergeSort(vector<int> &a,int left,int right){
        vector<int> b(a.size());
        if(left<right){
            int middle=(left+right)/2;
            mergeSort(a,left,middle);
            mergeSort(a,middle+1,right);
            merge(a,left,middle,right,b);
        }
    }
    void merge(vector<int> &a,int left,int middle,int right,vector<int> &b){
        int i=left;
        int j=middle+1;
        int k=i;
        while(i<=middle && j<=right){
            if(a[i]<a[j])b[k++]=a[i++];
            else b[k++]=a[j++];
        }
        while(i<=middle)b[k++]=a[i++];
        while(j<=right)b[k++]=a[j++];
        
        for(int t=left;t<=right;t++)a[t]=b[t];    
    }
    //链表
    ListNode* mergeSort(ListNode* head) {
        
        if (head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* s = head;
        ListNode* f = head->next;
        while ( f->next !=NULL && f->next->next !=NULL ){
            s = s->next;
            f = f->next->next;
        }
        
        ListNode* h2 = mergeSort(s->next);
        
        s->next = NULL;
        ListNode* h1=mergeSort(head);
        
        return merge(h1 , h2);       
    }
    ListNode* merge(ListNode* h1,ListNode* h2){
          
        if(h1==nullptr)return h2;
        if(h2==nullptr)return h1;
        ListNode* head;
        if(h1->val<h2->val){
            head=h1;
            head->next=merge(h1->next,h2);
        }else{
            head=h2;
            head->next=merge(h1,h2->next);
        }
        return head;
    }

};