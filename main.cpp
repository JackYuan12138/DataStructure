#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "queue.h"

#define RandBetween(a, b) (rand()%(b-a+1)+a)


int main() {
    jack::queue<int> l;
    printf("尝试插入元素到队列");
    l.push_back(1);
    l.push_back(2);
    l.pop_front();
    l.clear();
    return 0;
}
