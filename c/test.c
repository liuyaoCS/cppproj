#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
// #include <math.h>

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

void test1(){
  int i,pid;
  // for(i=0;i<2;i++){
    pid=fork();
    printf("hi pid=%d\n",pid);
  // }
  // wait(NULL);
  wait(NULL);
  // sleep(60);
}
void test2(){
    // struct A a;
    // struct B b;

    // int pa=(int)&a;
    // int ret = pa%sizeof(a);

    // printf("size: %d %d address: %p %p ret:%d\n",sizeof(a),sizeof(b),&a,&b,ret);
}

void test3(){
  // int *value = NULL;
  // value = calloc(2*2,sizeof(int));
  // for(int i=0;i<4;i++){
  //   value[i]=i;
  // }
  // for(int i=0;i<2;i++){
  //   for(int j=0;j<2;j++){
  //     printf("%d ",value[i][j]);
  //   }

    
  // }
  // printf("\n");

  
}
void test4(){
  int a=2;
  printf("%d\n",a%1);
}
void test5(){
  //相容性：可相互赋值
  char c='d' ;
  const char d =c;
  //1 指针指向内容相容 2 指向内容的限定符，左侧限定符包含右侧所有限定符
  char *p="";
  const char *cp=p;
  //相容性不具传递性(const限定符针对的是char，而不是指针)
  // char **pp=&p;
  // const char **pp0 = pp;
}
char * const *test7_0(){
  char* const *pp=NULL;
  return pp;
}
void test7(){
  char * const *(*next)();
  next=test7_0;
  next();
}
void test8(){
  signal(SIGUSR1, SIG_DFL);
}
void test9(){
    int a[2]={1,2};
    int (*p)[2];
    p=&a;
    printf("%d\n",**p);
}
void f(char **p){
    *p += 2;
}
void test10(){
    char *a[] = { "123","abc","456"},**p;
    p = a;
    f(p);
    printf("%c\r\n",**p); //3
}
// int printf (int a)
// {
//   return 1;
// }
double sqrt(double x){
  return 0;
}
void test11(){
  
  // printf("%d\n",(int)sqrt(100));
  printf("%lf\n",sqrt(4));
  // char str[10];
  // printf("Input a string.\n");
  // gets(str);
  // int v = atoi(str);
  // int x = sqrt(1000);
  // printf("%d\n",x);
}
void test12(){
  char a='a';
  float f=1.2;
  //类型提升 sizeof(1.4) sizeof('b')
  printf("%d %d %d %d %d %d\n",sizeof(float),sizeof(f),sizeof(1.4),sizeof(char),sizeof(a),sizeof('b'));
}
int (*test13())[20]{
  int (*pear)[20];
  pear = calloc(20,sizeof(int));
  return pear;
}
int test14(){
  int i=1;
  printf("%d %d %d %d\n",i+2, i++,i++,i);
}
int test15(){
  float a = 0;
  if(a>0.0 || a<0.0){
    printf("ok!\n");
  }
}
struct st1
{
  unsigned char a:7;/*字段a占用了一个字节的7个bit*/
  unsigned char b:2;/*字段b占用了2个bit*/
  unsigned char c:7;/*字段c占用了7个bit*/
}s1;
int test16(){
  printf("%ld\n",sizeof(struct st1));
}
int main(){
  // int (*ret)[20];
  // ret =  test13();
  // (*ret)[3]=12;
  test16();
  return 0;
}