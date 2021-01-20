#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
树的遍历（递归/非递归）
*/

struct Node{
    int val;
    Node* left, *right;
};
class Solution {
   
public:
    void preOrder(Node* root){
        if(root==nullptr)return;
        cout << root->val << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
    void preOrder2(Node* root){
        if(root==nullptr)return;
        stack<Node*> stack;
        stack.push(root);
        while(!stack.empty()){
            Node* p=stack.top();stack.pop();
            cout << p->val << endl;
            if(p->right!=nullptr)stack.push(p->right);
            if(p->left!=nullptr)stack.push(p->left);
        }
    }
    void inOrder(Node* root){
        if(root==nullptr)return;
        preOrder(root->left);
        cout << root->val << endl;
        preOrder(root->right);
    }
    //通过设置p=p->left 或 p=p->right遍历二叉树
    void inOrder2(Node* root){
        if(root==nullptr)return;
        stack<Node*> stack;
        Node* p=root;
        while(p!=nullptr || !stack.empty()){
            if(p!=nullptr){
                stack.push(p);
                p=p->left;
            }else{
                p=stack.top();stack.pop();
                cout << p->val << endl;
                p=p->right;
            }
        }
    }
    void postOrder(Node* root){
        if(root==nullptr)return;
        preOrder(root->left);
        preOrder(root->right);
        cout << root->val << endl;
    }
    //在inOrder2的基础上改动：根据后序遍历特点，从栈顶弹出的时候，如果有右侧节点，并且右侧节点不是上一次被弹出的节点，则压栈。否则就出栈访问。
    void postOrder2(Node* root){
        stack<Node*> stack; 
        Node *p = root, *prev = root;  
        while (p != nullptr || !stack.empty() ) {  
            if(p != nullptr) {               
                stack.push(p);
                p = p->left;  
            }else{  
                p= stack.top(); 
                if (p->right == nullptr || p->right == prev) {  
                    p = stack.top(); stack.pop();
                    cout << p->val << endl; 
                    prev = p;  
                    p = nullptr;  
                } else {  
                    p = p->right;  
                }                    
            }           
        }  
    }
    void layerOrder(Node* root){
        if(root==nullptr)return;
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()){
            Node* node=queue.front();queue.pop();
            cout << node->val << endl;
            if(node->left!=nullptr)queue.push(node->left);
            if(node->right!=nullptr)queue.push(node->right);
        }
    }
};