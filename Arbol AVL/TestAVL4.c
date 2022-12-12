#include<stdio.h>
#include<stdlib.h>
#include"ElemInt.h"
#include"AVL.h"

int main(){
    int i,e;
	AVL x=vacioAB();
	for(e=1;e<10;e++){
    	x=InsAVL(e,x);
	}
	PreOrd(x);
	x = BorraAVL(4,x);
	if(!EsAVL(x)){
		HazAVL(x);
	}
	puts("\n");
	PreOrd(x);
	return 0;
}


