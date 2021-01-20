#include <iostream>
#include <vector>
using namespace std;

/**
杨氏矩阵查找:已知一个2维矩阵，其中的元素每一行从左至右依次增加，每一列从上到下依次增加。
即对于矩阵Table有Table[i][j] ≤Table[i][j + 1],    Table[i][j] ≤ Table[i + 1][j]
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
遍历螺旋矩阵:是指一个呈螺旋状的矩阵，它的数字由第一行开始到右边不断变大，向下变大，向左变大，向上变大，如此循环
*/


class Solution {
public:
    //线性搜索解法: 选取左下角或者右上角：位于折线递增的中心 
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       int m = matrix.size();
       int n = matrix[0].size();
       
       int i = 0, j = n - 1;
       while(i < m && j >= 0)
       {
           if(matrix[i][j] == target)
                return true;
           else if(matrix[i][j] < target)
                i++;
           else j--;
       }
       return false;
        
    }
    //遍历螺旋矩阵
    void print(vector<vector<int> > &matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<bool> > visited(m,vector<bool>(n));
        int i=0,j=0;
        for(int k=0;k<m*n;k++){
            cout << matrix[i][j];
            visited[i][j]=true;
            
            if(j+1<n && !visited[i][j+1])j++;
            else if(i+1<m && !visited[i+1][j])i++;
            else if(j-1>=0 && !visited[i][j-1])j--;
            else if(i-1>=0 && !visited[i-1][j])i--;
        }
    }
   
};