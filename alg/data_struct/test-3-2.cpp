#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
两个排序单链表归并
*/

struct Node{
    int data;
    Node* next;
};
class Solution {
   
public:
    Node* merge(Node* list1,Node* list2){
        
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        Node* head;
        if(list1->data<list2->data){
            head=list1;
            head->next=merge(list1->next,list2);
        }else{
            head=list2;
            head->next=merge(list1,list2->next);
        }
        return head;
    }
};