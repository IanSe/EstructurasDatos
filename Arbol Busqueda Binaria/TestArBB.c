#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ElemInt.h""
#include"ArBB.h"

int main(){
    int i,e;
    ArBin x=vacioAB();

    for(i=1;i<=10;i++){
        x=insordAB(e=1+rand()%30,x);
        printf("%d ",e);
    }

    printf("Alt=%d\tNumElems=%d\n",Altura(x),NumElemsAB(x));

    PreOrd(x);
    puts("\n--------");
    PostOrd(x);
    puts("\n--------");
    InOrd(x);

    return 0;
}
