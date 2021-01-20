#include <iostream>
#include <vector>
using namespace std;

// pow

class Solution {
public:
    int judge(int x,int n){
        
        return n>0?pow(x,n):1/pow(x,-n);
    }
    /*典型的分治思路*/
    int pow(int x,int n){
        
        if(n==0)return 1;
    
        int v=pow(x,n/2);    
        return n%2==0? v*v:v*v*x;
    }
};