#include <iostream>
#include <vector>
using namespace std;

/**
请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0 。

注意：

本题中的空白字符只包括空格字符 ' ' 。
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  231 − 1 或 −231 。

*/

/**思路：
    str 开头可能含有若干个空字符，之后可能会有'+'或'-' 之后是数字，如果中途出现非空字符，则返回已得到的值.
*/


class Solution {
public:
    //如果明确不可能为空值，就使用引用，在函数内部对于引用不需要判断是否为空，代码更简洁
    int myAtoi(string str) {
        if(str.size()==0)return 0;
        
        int i=0;
        int n=str.length();
        while(i<=n && str[i]==' ')i++;
        if(i==n+1)return 0;
        
        int sign=str[i]=='-'?-1:1;
        if(str[i]=='+' || str[i]=='-')i++;
        
        long num=0;
        while(i<=n){
            if(str[i]>'9' || str[i]<'0')break;
            num=str[i]-'0'+num*10;
            if(num>INT32_MAX)return sign==1?INT32_MAX:INT32_MIN;
            i++;
        }
        
        return num*sign;
    }
};
int main(){
    Solution s;
    string ss = "123";
    cout << s.myAtoi(ss) << endl;
    
    return 0;
}