#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
树的遍历（递归/非递归）
对于非递归算法：
1 每次循环（循环采用while，起始从根结点开始，结尾栈为空（保证出栈）且节点为空（保证入栈）），
    节点非空，
        入栈 [业务：前序，输出]
        p=p->left
    节点空，
        出栈 [业务：中序|后序，输出] //后序要处理完右节点的才能出栈
        p=top->right //后序没处理完右节点；已经处理完右节点则null：因为top->right已经出栈,所以也要保存上一个出栈节点
2 要么入栈时输出，要么出栈时输出
*/

struct Node{
    int val;
    Node* left, *right;
    Node(int v,Node* l,Node* r):val(v),left(l),right(r){}
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
    //入栈输出，保持和中序后序一样逻辑（万能逻辑：设置p=p->left 或 p=p->right遍历二叉树）
    void preOrder3(Node* root){
        if(root==nullptr)return;
        stack<Node*> stack;
        Node *p=root;
        while(p!=nullptr || !stack.empty()){
            if(p!=nullptr){
                stack.push(p);
                cout << p->val << endl;
                p = p->left;
            }else{
                Node *top = stack.top();stack.pop();
                p = top->right;
            }
        } 
    }
    void inOrder(Node* root){
        if(root==nullptr)return;
        preOrder(root->left);
        cout << root->val << endl;
        preOrder(root->right);
    }
    //出栈输出
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
int main(){
    Solution s;
    Node n4(4,nullptr,nullptr),n5(5,nullptr,nullptr),n2(2,&n4,&n5),n3(3,nullptr,nullptr),n1(1,&n2,&n3);
    s.preOrder3(&n1);
    // s.inOrder2(&n1);
    return 0;
}