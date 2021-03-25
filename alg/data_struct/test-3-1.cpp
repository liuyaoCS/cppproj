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
    Node(int v, Node * n):val(v),next(n){}
};
class Solution {
   
public:
    //和java不同，c++有指针的概念，不用单独建一个fake head
    Node* reverse(Node* head){
        if(head==nullptr || head->next==nullptr)return head;

        Node* pre=head;
        Node* cur=head->next;
        while(cur!=nullptr){
            //摘指针
            pre->next=cur->next;
            //头插
            cur->next=head;
            head=cur;
            //移动
            cur=pre->next;
        }
        return head;
    }
};
int main(){
    Node n3(3,nullptr),n2(2,&n3),n1(1,&n2);
    Node *head=&n1;
    Solution s;
    
    Node *p = s.reverse(head);
    while(p!=nullptr){
        cout << p->val << endl;
        p=p->next;
    }
}