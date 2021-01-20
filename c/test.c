#include <stdlib.h>
#include <stdio.h>

//
struct A
{
    int a;
    short b;
    int c;
    char d;
};
struct B{
    int a ;
    int c;
    short b;
    char d;
};
int main(){
    struct A a;
    struct B b;
    
    int pa=(int)&a;
    int ret = pa%sizeof(a);

    printf("size: %d %d address: %p %p ret:%d\n",sizeof(a),sizeof(b),&a,&b,ret);
    return 0;
}