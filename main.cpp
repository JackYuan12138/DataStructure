#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "deque.h"

#define RandBetween(a, b) (rand()%(b-a+1)+a)


int main() {
    jack::deque<int> l;
    printf("���Բ���Ԫ�ص�����");
    l.push_back(1);
    l.push_back(2);
    l.pop_back();
    l.pop_front();

    l.clear();
    return 0;
}
