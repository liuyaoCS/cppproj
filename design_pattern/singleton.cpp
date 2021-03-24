#include <iostream>
#include <mutex>

using namespace std;

/* 策略模式 （android属性动画-插值器）
 * 核心：实现一个功能有多种策略
 * 角色：1 抽象策略 2 策略 3 策略调度者
 */

//这里直接设为全局变量，否则放到类里，又要和instance一样了，麻烦
//直接放到函数里
// mutex mtx;

class Singleton{
    
private:
    //类内声明（保证private）,外面定义（不能在这里定义，因为静态变量不属于类，属于全局）
    static Singleton* instance;
    
    //因为是动态分配的，调用析构函数不会释放instance
    // ~Singleton(){
    //     cout << "delete instance..." << endl;
    //     delete instance;
    // }
    class GC{
	public:
		~GC(){
			if (instance != NULL){
                cout << "delete instance..." << endl;
				delete instance;
			}
		}
	};
    //程序在结束时析构全局变量和静态成员变量的特性
	static GC gc;

    Singleton(){}
    //定义私有，保证外部不能访问；只定义不实现，保证内部和友元也不能访问
    Singleton(const Singleton& s);
    Singleton& operator=(const Singleton& s);

public:
    //C++11保证了static局部变量的线程安全
    //c++静态变量和全局变量实现机制一样，只是作用域不一样，静态局部变量也一样：程序main前已经为静态局部变量分配了内存，函数第一次调用时，为其赋值。
    //1 第一次执行到变量声明的地方时才进行初始化。
    //2 在当前线程执行到需要初始化变量的地方时，如果有其他线程正在初始化该变量，则阻塞当前线程，直到初始化完成为止。
    //单利模式实现就很简单了 static Singleton instance;return instance;这也成了饿汉模式。
    static Singleton* getInstance(){
        if(instance==NULL){
            mutex mtx;
            mtx.lock();
            if(instance==NULL){
                //懒汉模式
                instance=new Singleton();
            }
            mtx.unlock();
        }
        return instance;
    }
    void dosome(){
        cout << "working..." << endl;
    }
};
/*When we declare a static member variable inside a class, 
we’re telling the compiler about the existence of a static member variable, 
but not actually defining it (much like a forward declaration). 
Because static member variables are not part of the individual class objects 
(they are treated similarly to global variables, and get initialized when the program starts), 
you must explicitly define the static member outside of the class, in the global scope.
*/
//虽然外部定义了，但是private还是代过来了,外部不能直接访问;
//也不能Singleton::GC gc；这样，这个gc和类里的无关，相当与重新定义一个Singleton::GC变量，因为是private显然不行
//记住这种语法：类内声明，类外定义
Singleton* Singleton::instance=NULL;
Singleton::GC Singleton::gc;


int main(){
    Singleton* instance = Singleton::getInstance();
    instance->dosome();
    return 0;
}