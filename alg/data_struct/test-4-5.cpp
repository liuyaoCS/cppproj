#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
二叉树转换成双向链表
*/
/*思路
*/

struct Node{
    int val;
    Node* left, *right;
};
class Solution {
   
public:
    Node* inOrder2LinkedList(Node* root){
        if(root==nullptr)return nullptr;
        if(root->left!=nullptr){
            Node* lroot=inOrder2LinkedList(root->left);
            Node* lp=lroot;
            while(lp->right!=nullptr){
                lp=lp->right;
            }
            lp->right=root;
            root->left=lp;
        }
        if(root->right!=nullptr){
            Node* rroot=inOrder2LinkedList(root->right);
            Node* rp=rroot;
            while(rp->left!=nullptr){
                rp=rp->left;
            }
            rp->left=root;
            root->right=rp;
        }
        Node *p=root;
        while(p->left!=nullptr){
            p=p->left;
        }
        return p;
    }
};