#include <cstdlib>
#include <cstdio>
#include "list.h"
#define RandBetween(a, b) (rand()%(b-a+1)+a)


int main() {
    jack::list<int> l;
    printf("将在链表中插入100个随机数\n");
    for(int i = 0; i < 100; i++){
        l.push_back(RandBetween(1,100));
    }
    for(int i = 0; i < 100; i++){
        printf("当前尾部元素为%d \n", *(--l.end()));//访问不到实际的尾部元素,现在明白了，初始化head的时候head的PreV是nullptr,所以end()的迭代器是没有办法自减的
        l.pop_back();
    }
    l.clear();
    return 0;
}
