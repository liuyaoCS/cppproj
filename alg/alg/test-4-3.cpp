#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
二叉树最大权值
*/
/*思路
*/

struct Node{
    int val;
    Node* left, *right;
};
class Solution {
    //用来保存访问到此节点的最大路径权值   
    int max;
public:
    int travel(Node* node){
        int v = node->val,v1=0,v2=0;
        int result = v;
        int mlocal = v;
        int i = 0;
        if(node->left!=nullptr){
            v1 = travel(node->left);
            if(v1>0)result = v+v1;
        }
        if(node->right!=nullptr){
            v2 = travel(node->right);
            if(result<v+v2) result = v+v2;
        }
        mlocal=getMax(v,v1,v2);
        if(max<mlocal)max = mlocal;
        return result; 
    }
    int getMax(int v,int v1,int v2){
        int ret=INT32_MIN;
        if(v>ret)ret=v;
        if(v1>ret)ret=v1;
        if(v2>ret)ret=v2;
        if(v+v1>ret)ret=v+v1;
        if(v+v2>ret)ret=v+v2;
        if(v+v1+v2>ret)ret=v+v1+v2;
        return ret;
    }
    int maxPathSum(Node* root) {
        max = INT32_MIN;
        travel(root);
        return max;        
    }
};