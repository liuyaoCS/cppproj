#include <unistd.h> 
#include<pthread.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

#include <iostream>
#include <sstream>
#include <fstream>

#include <algorithm>
#include <functional>

#include <memory>

#include <typeinfo>

extern "C"{
    #include <stdio.h>
}

using namespace std;

//g++ -Wno-deprecated-declarations  -o test test.cpp
void test1(){
    int sum=0,value;
    //ctrl+d：( Terminate input, or exit shell ) 一个特殊的二进制值，表示 EOF，作用相当于在终端中输入exit后回车；
    while(cin>>value){
        sum+=value;
    }
    //一行的末尾加一个反斜杠：可将此行和下一行当做一行处理。（多用于长字符串）
    cou\
t << "hi\
            sum "
            ":" << sum << endl;
}
void test2(){
    //cin会忽略空白字符 getline只忽略最后的换行符
    // string s;
    // cin>>s;
    // cout<<s<<endl;

    // string line;
    // while(getline(cin,line)){
    //     cout<<line<<endl;
    // }

    string str("hi,what is your name");
    size_t len = str.size(); 
    for(size_t i=0;i<len;i++){
        str[i]='*';
    }
    cout<<str<<endl;
}
void test3(){
    vector<string> strs(10,"*");
    for(size_t i;i<strs.size();i++){
        strs[i]="#";
    }
    strs.push_back("over");
    cout << strs[2] << endl;

    vector<int> ints(10);
    vector<int>::iterator it = ints.begin();
    for(vector<int>::iterator it = ints.begin();it!=ints.end();it++){
        cout << *it <<endl;
    }
}
void test4(){

}
void test5(){

}
void test6(){

}
void test7(){

}
void test8(){
    string line,word;
    while(getline(cin,line)){
        istringstream stream(line);
        while(stream >> word){
            cout << word <<endl;
        }
    }
}
void test9(){
    vector<int> vec(2,0);
    vector<int>::iterator iter=vec.begin()+vec.size()/2;
    list<int> ilist(vec.begin(),vec.end());
    int a=1;
    ilist.push_back(a);


}
void test10(){
    // pair<string,int> word_count;
    // string word;
    // int count;
    // while (cin>>word>>count)
    // {
    //     word_count = make_pair(word,count);
    //     cout << word_count.first << word_count.second <<endl;
    // }

    map<string,int> word_count;
    string word;
    while(cin>>word){
        word_count[word]++;
    }
    map<string,int>::const_iterator it = word_count.begin();
    while(it!=word_count.end()){
        cout << it->first << ":" << it->second << endl;
        it++;
    }

    vector<int> vecs;
    for(int i=0;i<5;i++){
        vecs.push_back(i);
    }
    set<int> sets;
    sets.insert(vecs.begin(),vecs.end());
    for(set<int>::iterator it = sets.begin();it!=sets.end();it++){
        cout << *it << endl;
    }
    
}
void test11(){
    vector<int> vecs;
    for(int i=0;i<5;i++){
        vecs.push_back(i);
    }

    vector<int>::iterator it= find(vecs.begin(),vecs.end(),2);
    string str = ( it==vecs.end() )? "not found" : "found" ;
    cout << str <<  endl;
}
void test12(){

}

class U_Ptr{
    friend class HasPtr;
    int* ip;
    size_t use;
    U_Ptr(int* p):ip(p),use(1){}
    ~U_Ptr(){
        cout << "deconstruct U_ptr" << endl;
        delete ip;
    }
};
class HasPtr{
public:
    HasPtr(int* p, int i):ptr(new U_Ptr(p)),val(i){}
    HasPtr(HasPtr& orig):ptr(orig.ptr),val(orig.val){++ptr->use;}
    HasPtr& operator=(HasPtr& rhs){
        ++rhs.ptr->use;
        if(--ptr->use == 0){
            delete ptr;
        }
        ptr = rhs.ptr;
        val = rhs.val;
        return *this;
    }
    ~HasPtr(){
        cout << "deconstruct HasPtr" << endl;
        if(--ptr->use==0)delete ptr;
    }
private:
    U_Ptr* ptr;
    int val;
};
void test13(){
    //前提是使用智能指针HasPtr负责释放对象，不要直接释放ip对象
    int *ip=new int(42);
    HasPtr ptr1(ip,10);
    HasPtr ptr2(ptr1);
    cout << "exit test13" << endl;
}
void test14(){
    plus<int> intAdd;
    cout << intAdd(1,2) << endl;
} 
void test15(){

}  
template<typename T,size_t N>
void array_init(T (&param)[N]){
    for(size_t i=0;i!=N;i++){
        param[i]=0;
    }
}
void test16(){
    
    //引用的数组 int &array[]
    //array首先向右结合，所以这个相当于 (int&)array[] array是个数组，其中的元素是引用
    //数组的引用 int (&array)[10] 
    //array首先和&结合，所以array是引用，引用的对象是数组
    int x[42];
    array_init(x);
}
void test17(){
    //exception
    auto_ptr<int> ap(new int(1024));
    if(ap.get()){
        *ap = 10;
    }
    cout << *ap << endl;
    //using space

}
typedef unsigned int Bit;
enum {
    READ = 01,
    WRITE = 02
};
class File{
public:
    Bit mode:2;
    Bit modified:1;
    Bit owner:3;
    Bit group:3;
    Bit other:3;
    void write(){
        modified = 1;
    }
};
void test18(){
    //rtti
    int a;
    cout <<typeid(a).name() << endl
         << typeid(std::string).name() << endl
         << typeid(HasPtr).name() << endl;
    //bitt-filed
    File file;
    file.mode |= READ;
    if(file.mode & READ){
        cout << "read mode set!" << endl;
    }
    //extern "C"
    printf("test c function\n");
}
void test19(){
    fork(); 

    printf("Hello world!\n"); 
}
static void * pthread_func(void *arg)
{
     printf("i am new pthread\n");
     return NULL;
}
void test20(){
  pthread_t tidp; 
    /* 创建线程pthread */
  if ((pthread_create(&tidp, NULL, pthread_func, NULL)) == -1)
  {
    printf("create error!\n");
  }
}
void test21(){
  long val = 2234567;
  int ival = val;
}

// int operator+(int a, int b){
//     return a+b;
// }
void test22(){
  
}
int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    // test10();
    // test11();
    // test12();
    // test13();
    // test14();
    // test15();
    // test16();
    // test17();
    // test18();
    // test19();
    // test20();
    // test21();
    test22();
    cout << "exit main" << endl;
    return 0;
}