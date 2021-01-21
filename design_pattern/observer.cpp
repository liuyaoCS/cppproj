#include <iostream>
#include <list>
#include <string>
using namespace std;

/**
 * 观察者模式 (android:listview的adapter;broadcastreceiver)
 * 核心：发布-订阅模式
 * 角色：1 抽象主题    java已经实现Observable
 *      2 抽象观察者 java已经实现Observer
 * 	    3 具体主题 
 *      4 具体观察者
 */
class Observer { // 抽象观察者，为所有具体观察者定义一个接口，在得到主题的通知时更新自己，这个接口叫更新接口
public:
    virtual void Update() = 0;
};

class Subject { // 主题或抽象通知者，一般用一个抽象类或者接口实现
private:
    list<Observer* > observers;
public:
    void Attach(Observer* observer) { observers.push_back(observer); } // 增加观察者
    void Detach(Observer* observer) { observers.remove(observer); } // 移除观察者
    void Notify() { // 通知
        for (auto observer = observers.begin(); observer != observers.end(); observer++) {
            (*observer)->Update();
        }
    }
};

class ConcreteSubject : public Subject { // 具体主题或具体通知者，将有关状态存入具体观察者对象，在具体主题的内部状态改变时，给所有登记过的观察者发送通知
private:
    string subjectState;
public:
    string GetState() { return subjectState; }
    void SetState(string state) { subjectState = state; }
};

class ConcreteObserver : public Observer { // 具体观察者，实现抽象观察者角色所要求的更新接口，以便使本身的状态与主题状态相协调
private:
    string name;
    ConcreteSubject* subject;
    string observerState;
public:
    ConcreteObserver(ConcreteSubject* s, string n) {
        subject = s;
        name = n;
    }
    void Update() {
        observerState = subject->GetState();
        cout << "observer: " << name << ", its new state is: " << observerState << endl;
    }
    string GetState() { return observerState; }
    void SetState(string state) { observerState = state; }
};

int main() {
    ConcreteSubject* s = new ConcreteSubject();
    s->SetState("ABC");
    ConcreteObserver* ox = new ConcreteObserver(s, "X");
    ConcreteObserver* oy = new ConcreteObserver(s, "Y");
    ConcreteObserver* oz = new ConcreteObserver(s, "Z");
    s->Attach(ox);
    s->Attach(oy);
    s->Attach(oz);
    s->Notify();
    // observer: X, its new state is: ABC
    // observer: Y, its new state is: ABC
    // observer: Z, its new state is: ABC
    s->SetState("XYZ");
    s->Notify();
    // observer: X, its new state is: XYZ
    // observer: Y, its new state is: XYZ
    // observer: Z, its new state is: XYZ
    delete ox;
    delete oy;
    delete oz;
    delete s;
    return 0;
}