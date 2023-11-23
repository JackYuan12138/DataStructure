#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "list.h"

#define RandBetween(a, b) (rand()%(b-a+1)+a)


int main() {
    jack::list<int> l;
    printf("将在链表中插入100个随机数\n");
    for (int i = 0; i < 100; i++) {
        l.push_back(RandBetween(1, 100));
        printf("当前头元素为: %d\n", *(--l.end()));
    }
    printf("\n\n");
    for (int i = 0; i < 100; i++) {
        printf("当前尾元素为: %d\n", *(--l.end()));
        l.pop_back();
    }

    l.clear();
    return 0;
}
