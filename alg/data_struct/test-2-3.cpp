#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
表达式求值是指给定一个表达式字符串，求得表达式最后的值。
例如给定表达式： 3 + 2 * (4 + 1) ，通过表达式求值后得到的值为13。

*/

/**思路：
    开辟俩个栈，
        一个存数字，
        一个符号：
            压入新元素必须保证比栈顶符号优先级高，如果低的话，需要循环出栈计算，压入结果数字，直到比栈顶符号优先级高
            或者栈顶元素是 （ 
            当遇到 ），循环出栈，直到（
    定义符号优先级，+ - 优先级1  * / 优先级2  （优先级3
*/


class Solution {
public:
    int compute(string str){ 
        if(str.size()==0)return 0;
        
        stack<int> numStack;
        stack<char> operStack;
        int i=0;
        while(i<str.size() || numStack.size()>1){
            if(i<str.size()){
                if(str[i]>='0' && str[i]<='9')numStack.push(str[i]-'0');
                else{
                    if(operStack.empty())operStack.push(str[i]);
                    else{
                        if(str[i]!=')'){
                            if(getPrior(str[i])>getPrior(operStack.top())
                                    || operStack.top()=='(')operStack.push(str[i]);
                            else{
                                while(getPrior(str[i])<getPrior(operStack.top())){
                                    int num1=numStack.top();numStack.pop();
                                    int num2=numStack.top();numStack.pop();
                                    char oper=operStack.top();operStack.pop();
                                    int res=operate(num1,num2,oper);
                                    numStack.push(res);
                                }
                                
                                operStack.push(str[i]);
                            }
                        }else{
                            while(operStack.top()!='('){
                                int num1=numStack.top();numStack.pop();
                                int num2=numStack.top();numStack.pop();
                                char oper=operStack.top();operStack.pop();
                                int res=operate(num1,num2,oper);
                                numStack.push(res);        
                            }
                            operStack.pop();
                        }
                        
                    }
                }
                i++;
            }else{
                int num1=numStack.top();numStack.pop();
                int num2=numStack.top();numStack.pop();
                char oper=operStack.top();operStack.pop();
                int res=operate(num1,num2,oper);
                numStack.push(res);
            }
            
        }
        return numStack.top();
    }
    int operate(int num1,int num2,char oper){
        int ret=0;
        switch(oper){
            case '+':
                ret=num2+num1;
                break;
            case '-':
                ret=num2-num1;
                break;
            case '*':
                ret=num1*num2;
                break;
            case '/':
                ret=num2/num1;
                break;
            default:
                break;
        }
        return ret;
    }
    int getPrior(char c){
        if(c=='+' || c=='-')return 1;
        else if(c=='*' || c=='/')return 2;
        else if(c=='(' || c==')')return 3;
        else return 0;
    }
};
int main(){
    Solution s;
    cout << s.compute("3+2*(4+1)") << endl;
}