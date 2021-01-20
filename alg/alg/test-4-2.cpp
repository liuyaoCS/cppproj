#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 最长公共子串/最长连续公共子串
// 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

/*
最长公共子串思路：
    f(i,j)表示以i，j结尾(不一定包含)最长公共子序列长度
    f(i,j)=
        f(i-1,j-1)+1              text1[i]==text2[j]
        max{f(i-1,j),f(i,j-1)}    text1[i]!=text2[j]
    边界条件
        text1[i]==text2[j]        i==0 || j==0

最长连续公共子串思路：   
    f(i,j)表示以i，j结尾(包含)最长连续公共子序列长度
    f(i,j)=
        f(i-1,j-1)+1              text1[i]==text2[j]
        0                         text1[i]!=text2[j]
    边界条件
        text1[i]==text2[j]        i==0 || j==0
*/

class Solution {

public:
    //最长公共子串
    int lcs(string a,string b){
        int m=a.size();
        int n=b.size();
        vector<vector<int>> array(m,vector<int>(n));
        for(int i=0;i<m;i++)
            array[i][0]=a[i]==b[0];
        for(int j=0;j<n;j++)
            array[0][j]=a[0]==b[j];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(a[i]==b[j])array[i][j]=array[i-1][j-1]+1;
                else array[i][j]=array[i-1][j]>array[i][j-1]?array[i-1][j]:array[i][j-1];
            }
        }
        return array[m][n];        
    }
    //最长连续公共子串
    int lcs2(string a,string b){
        int m=a.size();
        int n=b.size();
        vector<vector<int>> array(m,vector<int>(n));
        for(int i=0;i<m;i++)
            array[i][0]=a[i]==b[0];
        for(int j=0;j<n;j++)
            array[0][j]=a[0]==b[j];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(a[i]==b[j])array[i][j]=array[i-1][j-1]+1;
                else array[i][j]=0;
            }
        }
        int max=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)if(array[i][j]>max)max=array[i][j];
        }
        return array[m][n];        
    }
};