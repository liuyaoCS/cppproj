#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
判断B树是不是A树的子结构
*/

struct Node{
    int val;
    Node* left, *right;
};
class Solution {
   
public:
    bool isSubTree(Node* root1,Node* root2){
        //终止/边界条件一定要做足
        if(root1==nullptr)return root2==nullptr;
        if(root2==nullptr)return true;

        bool ret=isIn(root1,root2);   
        if(!ret) ret=isSubTree(root1->left,root2)||isSubTree(root1->right,root2);
        
        return ret;
    }
    bool isIn(Node* root1,Node* root2){
        //终止/边界条件一定要做足
        if(root1==nullptr)return root2==nullptr;
        if(root2==nullptr)return true;
        
        if(root1->val!=root2->val)return false;
        return isIn(root1->left,root2->left) && isIn(root1->right,root2->right);
        
    }
};