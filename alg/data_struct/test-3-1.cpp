#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
单链表倒序
*/

struct Node{
    int val;
    Node* next;
};
class Solution {
   
public:
    //和java不同，c++有指针的概念，不用单独建一个fake head
    Node* reverse(Node* head){
        if(head==nullptr || head->next==nullptr)return head;

        Node* pre=head->next;
        Node* cur=head->next->next;
        while(cur!=nullptr){
            //摘指针
            pre->next=cur->next;
            //头插
            cur->next=head->next;
            head->next=cur;
            //移动
            cur=pre->next;
        }
        return head;
    }
};