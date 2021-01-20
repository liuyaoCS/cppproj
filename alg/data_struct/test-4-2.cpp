#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
求二叉树的深度
*/

struct Node{
    int val;
    Node* left, *right;
};
class Solution {
   
public:
    int getDepth(Node* root){
        if(root==nullptr)return 0;
        
        int ld=getDepth(root->left);
        int rd=getDepth(root->right);
        
        return ld>rd?(ld+1):(rd+1);
        
    }
};