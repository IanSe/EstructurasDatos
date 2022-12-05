#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ElemInt.h""
#include"ArBin.h"

int main(){

    ArBin x=consAB(100,vacioAB(),vacioAB());

    printf("%d\t%d\n",Altura(x),NumElemsAB(x));

    PreOrd(x);
    PostOrd(x);
    InOrd(x);

    return 0;
}
