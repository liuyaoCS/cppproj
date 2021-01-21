#include <iostream>
using namespace std;

class Buyer;
class Seller;
class Mediator{
private:
    Buyer * buyer;
    Seller * seller;
    Mediator(){}
public:
    static Mediator* getInstance(){
        static Mediator mediator;
        return &mediator;
    }
    inline void setBuyer(Buyer * buyer){
        this->buyer  = buyer;
    }
    inline void setSeller(Seller * seller){
        this->seller  = seller;
    }
    void business();
};


class Buyer{
    Mediator* mediator = Mediator::getInstance();
public:
    void buy();
};
class Seller{
    Mediator* mediator = Mediator::getInstance();
public:
    void sell();
};




