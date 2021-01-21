#include<iostream>
using namespace std;

/**
 * 静态代理
 * 角色：1 具体类 2 代理类
 * 		不一定有抽象类或接口 
 * 说明：静态代理不依赖接口
 */

class Subject{
public:
    virtual ~Subject(){}
    virtual void request()=0;
};
class RealSubject: public Subject{
public:
    void request(){
        cout << "real subject handle request..." << endl;
    }
};
class ProxySubject: public Subject{
    RealSubject* real=NULL;
public:
    void request(){
        cout << " before request...." << endl;
        if(real==NULL)real=new RealSubject();
        real->request();
        cout << " after request..." << endl;
    }
    ~ProxySubject(){
        if(real){
            delete real;
            real = NULL;
        }
    }
};


int main(){
    ProxySubject proxy;
    proxy.request();
    return 0;
}