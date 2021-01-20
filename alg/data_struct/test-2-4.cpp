#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 
示例 1：

输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa" p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab" p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4：

输入：s = "aab" p = "c*a*b"
输出：true
解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5：

输入：s = "mississippi" p = "mis*is*p*."
输出：false
*/

/*思路：
    当前s[i] ,  p[j]
    if s[i+1]!=‘*’
        s[i]==p[j] || p[j]=='.'
        && isMatch(s[i+1], p[j+1])
    else:
        (s[i]==p[j] || p[j]=='.')不成立，则‘*’匹配0次：
        //通过i++‘*’匹配多次
        while(s[i]==p[j] || p[j]=='.'){
            i++
        }
        
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size()==0)return p.size()==0;
        if(p.size()==0)return false;
        
        if(p.size()==1){
            return p[0]=='.' || s[0]==p[0];
        }
        
        int i=0,j=0;
        if(p[j+1]!='*'){
            if(s[i]!=p[j] && p[j]!='.')return false;
            else return isMatch(s.substr(i+1),p.substr(j+1));
        }else{
            if(s[i]!=p[j] && p[j]!='.')return isMatch(s.substr(i),p.substr(j+2));
            //i可以取等号，以及p的可以取到j+2也是因为substring的这点特殊性
            while((i<s.size() && (s[i]==p[j] || p[j]=='.'))){
                if(isMatch(s.substr(i),p.substr(j+2)))return true;
                i++;
            }
            return isMatch(s.substr(i),p.substr(j+2));
        }
        return false;
    }
};