#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "list.h"

#define RandBetween(a, b) (rand()%(b-a+1)+a)


int main() {
    jack::list<int> l;
    printf("���������в���100�������\n");
    for (int i = 0; i < 100; i++) {
        l.push_back(RandBetween(1, 100));
        printf("��ǰͷԪ��Ϊ: %d\n", *(--l.end()));
    }
    printf("\n\n");
    for (int i = 0; i < 100; i++) {
        printf("��ǰβԪ��Ϊ: %d\n", *(--l.end()));
        l.pop_back();
    }

    l.clear();
    return 0;
}
