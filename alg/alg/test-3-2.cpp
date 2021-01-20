#include <iostream>
#include <vector>
using namespace std;

// 打印1-n位数的整数/不包含相同元素

/*
思路：
*/

class Solution {
public:
    void print(int n){
    /*用数组保存中间结果，不用压栈出栈，也不用StringBuilder的append和setCharAt（）的区分;但是只能每次结果都是固定大小*/
        vector<string> strs(n);                                         
        dfs(0,n,strs);
    }
    void dfs(int index,int n,vector<string>& strs){
        if(index==n){
            for(int i=0;i<n;i++)cout<<strs[i]<<" ";
            cout<<endl;
            return;
        }
        for(int i=0;i<10;i++){
            strs[index]=""+i;
            dfs(index+1,n,strs);
        }
    }
    //不包含相同元素
    void print(int n){
        vector<string> strs(n); 
        vector<bool> visited(10);
        dfs(0,n,strs,visited);
    }
    void dfs(int index,int n,vector<string>& strs,vector<bool>& visited){
        if(index==n){
            for(int i=0;i<n;i++)cout<<strs[i]<<" ";
            cout<<endl;
            return;
        }
        for(int i=0;i<10;i++){
            if(!visited[i]){
                visited[i]=true;
                strs[index]=""+i;
                dfs(index+1,n,strs,visited);
                visited[i]=false;
            }
            
        }
    }

};