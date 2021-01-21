#include <iostream>

using namespace std;

/**
 * 工厂模式 （线程池 国搜客户端FragmentHome）
 * 核心：工厂类统一管理对象的创建
 * 角色：1 抽象工厂 2 具体工厂 3 抽象产品 4 具体产品。
 * 	    工厂类或者产品类都不一定要先创建抽象类或者接口再实现，
 *    因为工厂类就是一个管理类，统一管理产品的创建，只要是这个含义，无论实现形式什么样，都是工厂类。
 */
//工厂模式：将对象的创建通过一个类（简单工厂）或多个类（抽象工厂）封装起来
class Product{
public:
    /*作为通常的原则，如果一个类定义了虚函数，那么它的析构函数就应当是virtual的。
    因为定义了虚函数则隐含着：这个类会被继承，并且会通过基类的指针指向子类对象，从而得到多态性。因此基类的析构函数是否为虚将决定子类的对象是否被析构
    */
    virtual ~Product(){
        cout << "~Product!" << endl;
    }
    //非静态成员函数后面加const:常常有一些成员函数不改变类的数据成员，也就是说，这些函数是"只读"函数
    virtual void show()const=0;
};

class ConcreteProduct:public Product{
public:
    ~ConcreteProduct(){
        cout << "~ConcreteProduct!" << endl;
    }
    void show()const{
        cout << "concreteProduct info!" << endl;
    }
};

class Factory{
public:
    virtual ~Factory(){
            cout << "~Factory!" << endl;
    }
    virtual Product* make()const=0;
};

class ConcreteFactory:public Factory{
public:
    ~ConcreteFactory(){
        cout << "~ConcreteFactory!" << endl;
    }
    Product* make()const{
        return new ConcreteProduct();
    }
};

int main(){

    ConcreteFactory factory;
    Product *product=factory.make();
    product->show();
    delete product;
    return 0;
}