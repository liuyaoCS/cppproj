#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
求节点最近共同祖先
*/
/*思路1：如代码
  思路2：
    root->left是否包含n1 , n2
    root->right是否包含n1 , n2
    递归下去。。。
*/

struct Node{
    int val;
    Node* left, *right;
};
class Solution {
   
public:
    Node* getCommonParent(Node *root,Node *n1,Node *n2){
        if(root==nullptr || n1==nullptr || n2==nullptr 
                || n1->val==root->val || n2->val==root->val)return nullptr;
        int p1=nodePosition(root,n1);
        int p2=nodePosition(root,n2);
        if(p1==1 && p2==2)return root;
        else if(p1==1 && p2==1)return getCommonParent(root->left,n1,n2);
        else if(p1==2 && p2==2)return getCommonParent(root->right,n1,n2);
        else return nullptr;
    }
/**
     * 子问题！
     * @return 0:根节点匹配；1：左支匹配；2：右支匹配；-1不匹配，无此节点。
     */
    int nodePosition(Node* root,Node* node){
        if(node==nullptr || root==nullptr)return -1;  //错误检测
        if(root->val==node->val)return 0;       //终止条件

        int l=nodePosition(root->left,node);
        int r=nodePosition(root->right,node);
         
        int ret;        
        if(l>=0)ret=1;
        else if(r>=0)ret=2;
        else ret=-1;
        
        return ret;   
    }
};