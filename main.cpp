#include <cstdlib>
#include <cstdio>
#include "list.h"
#define RandBetween(a, b) (rand()%(b-a+1)+a)


int main() {
    jack::list<int> l;
    printf("���������в���100�������\n");
    for(int i = 0; i < 100; i++){
        l.push_back(RandBetween(1,100));
    }
    for(int i = 0; i < 100; i++){
        printf("��ǰβ��Ԫ��Ϊ%d \n", *(--l.end()));//���ʲ���ʵ�ʵ�β��Ԫ��
        l.pop_back();
    }
    l.clear();
    return 0;
}
