#include "mediator.h"


/**
 * 中介模式  （android binder；国搜客户端早期卡片机之制CardProxy）
 * 核心：将两个或多个紧耦合的类解除耦合
 * 角色：1 中介者 需要包含各个实体类的引用，一般设计成单例模式，供外部访问。
 *      2 实体类 包含中介的引用
 */

void Mediator::business(){
    buyer->buy();
    seller->sell();
}
void Buyer::buy(){
    cout << " buy some" << endl;
}
void Seller::sell(){
    cout << " sell some" << endl;
}

int main(){
    Buyer buyer;
    Seller seller;
    Mediator *mediator = Mediator::getInstance();
    mediator->setBuyer(&buyer);
    mediator->setSeller(&seller);
    mediator->business();
    return 0;
}