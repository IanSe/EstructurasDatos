#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ElemInt.h"
#include"AVL.h"

int main(){
    int i,e;
    AVL x=vacioAB();
    EsAVL(x)?puts("Si."):puts("No.");
    x=insordAB(100,x);
    EsAVL(x)?puts("Si."):puts("No.");
    x=insordAB(50,x);
    EsAVL(x)?puts("Si."):puts("No.");
    x=insordAB(25,x);
    EsAVL(x)?puts("Si."):puts("No.");
    x=insordAB(200,x);
    EsAVL(x)?puts("Si."):puts("No.");
    return 0;
}


