#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
kmp
*/

/*思路：求模式串p前缀和后缀的公共子序列长度   
*/
class Solution {
    vector<int> next;
public:
    void fixNext(string p){
        int i=0,j=-1;
        next[0]=-1;
        while(i<p.size()){
            if(j==-1 || p[i]==p[j]){
                i++;
                j++;
                if(i<p.size())next[i]=j;
            }else j=next[j];
        }
    }
    int kmp(string s,string p){
        fixNext(p);
        int i=0,j=0;
        while(i<s.size() && j<p.size()){
            if(j==-1 || s[i]==p[j]){
                i++;
                j++;
            }else j=next[j];
        }
        if(j==p.size())return i-j;
        else return -1;
    }
};