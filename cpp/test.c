#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void test21(){
  int i,pid;
  // for(i=0;i<2;i++){
    pid=fork();
    printf("hi pid=%d\n",pid);
  // }
  // wait(NULL);
  wait(NULL);
  // sleep(60);
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
    test21();
    
    return 0;
}