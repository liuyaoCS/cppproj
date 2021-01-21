#include <iostream>
using namespace std;

/**
 * 访问者模式 （语法分析）
 * 核心：被访问对象对不同的访问类有不同的处理方式。（避免了instance of 和强制类型转化）
 * 角色：1 抽象visitor 2 具体visitor 3 抽象被访问对象 4 具体被访问对象
 */
class Visitor;
class Object{
public:
    virtual ~Object(){}
    virtual void accept(Visitor* v)=0;
    virtual void show()=0;
};
class Visitor{
public:
    virtual ~Visitor(){}
    virtual void visit(Object* o)=0;
};

class ConcreteObject: public Object{
public:
    void accept(Visitor* visitor){
        visitor->visit(this);
    }
    void show(){
        cout << "this is ConcreteObject" << endl;
    }
};

class ConcreteVisitor: public Visitor{
public:
    void visit(Object* object){
        object->show();
    }
};

int main(){
    Visitor *v = new ConcreteVisitor();
    Object *o = new ConcreteObject();
    o->accept(v);
    delete v,o;
    return 0;
}