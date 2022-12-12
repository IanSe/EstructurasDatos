#include<stdio.h>
#include<stdlib.h>
#include"ElemInt.h"
#include"AVL.h"

int main(){
    int i,e;
	AVL x=vacioAB();
    x=InsAVL(10,x);
    x=InsAVL(5,x);
    x=InsAVL(20,x);
    x=InsAVL(30,x);
    x=InsAVL(1,x);
    x = BorraAVL(10,x);
    PostOrd(x);
}

