#include<iostream>
using namespace std;

/**
 * 策略模式 （android属性动画-插值器）
 * 核心：实现一个功能有多种策略
 * 角色：1 抽象策略 2 策略 3 策略调度者
 */

class Strategy{
public:
    virtual ~Strategy(){}
    virtual void exec()=0;
};

class ConcreteStrategy: public Strategy{
public:
    void exec(){
        cout << "ConcreteStrategy!" << endl;
    }
};

class Context{
    Strategy* strategy;
public:
    Context(){}
    void setStrategy(Strategy* s){
        this->strategy = s;
    }
    void execStrategy(){
        strategy->exec();
    }
};

int main(){
    Strategy *strategy = new ConcreteStrategy();
    Context context;
    context.setStrategy(strategy);
    context.execStrategy();
    delete strategy;
    return 0;
}