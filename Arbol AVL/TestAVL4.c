#include<stdio.h>
#include<stdlib.h>
#include"ElemInt.h"
#include"AVL.h"

int main(){
    int i,e;
    AVL x=vacioAB();
	for(e=1;e<25;e++){
    	x=InsAVL(e,x);
	}
	ImpElem(ElMenor(derAB(x)));
	return 0;
}


