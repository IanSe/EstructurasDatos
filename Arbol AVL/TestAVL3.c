#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ElemInt.h"
#include"AVL.h"

void ImpAVL(AVL a);

int main(){
    int i,e;
    AVL x=vacioAB();
    x=InsAVL(100,x);
    x=InsAVL(200,x);
	x=InsAVL(300,x);
    x=InsAVL(400,x);
    x=InsAVL(250,x);
	x=InsAVL(220,x);
	InOrd(x);
	return 0;
}


