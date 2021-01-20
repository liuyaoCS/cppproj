#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 数组所有子集

/*
思路：
*/

class Solution {

public:
    vector<vector<int>> subsets(vector<int>& S) {
        vector<vector<int>> ret;
        vector<int> path;
        sort(S.begin(),S.end());
        dg(0,S,path,ret);
        return ret;
    }
    void dg(int step,vector<int>& S, vector<int>& path,vector<vector<int>>&ret){
        if(step==S.size()){
            ret.push_back(path);
            return;
        }
        //深搜，每种有两种情况，对应是二叉树
        dg(step+1,S,path,ret); 

        path.push_back(S[step]);
        dg(step+1,S,path,ret);
        path.pop_back();
    }

};