#include <iostream>
#include <vector>
using namespace std;

/**
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
*/


class Solution {
public:
    char firstUniqChar(string str) {
        if(str.length()==0)return ' '; 
        vector<char> hash(256); 
        for(int i =0;i<str.length();i++)hash[str[i]]++; 
        for(int i=0;i<str.length();i++){  
            if(hash[str[i]] == 1)  
                return str[i];  
        }  
        return ' ';  
    }
};
int main(){
    Solution s;
    string str = "abaccdeff";
    cout << s.firstUniqChar(str) << endl;
    return 0;
}