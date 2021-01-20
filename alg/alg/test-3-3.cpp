#include <iostream>
#include <vector>
using namespace std;

// n对括号匹配

/*
思路：
*/

class Solution {
    int count=0;
public:
    int getCount(int n){
        vector<string> res(2*n);
        dfs(0,n,n,res);
        return count;    
    }
    void dfs(int index,int a,int b,vector<string>& res){
        if(a==0){    
            count++;
            for(int i=b;i>0;i--)res[index++]=")";
            for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
            cout<<endl;
            return;
        }
        
        res[index]="(";
        dfs(index+1,a-1,b,res);
        
        if(b>a){
            res[index]=")";
            dfs(index+1,a,b-1,res);
        }
    }

};