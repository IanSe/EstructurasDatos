#include<stdio.h>
#include<stdlib.h>
#include"ElemInt.h"
#include"Lista.h"

int NumElems(Lista);
void ImpLista(Lista);

int main(){

    Lista a=vacia();
    Elem x;

    while((x=LeeElem())!=0)
          a=cons(x,a);
    ImpElem(cabeza(a));
    printf("La lista tiene %d elementos.\n",NumElems(a));
    printf("Los elementos de la lista son:\n");
    ImpLista(a);
    puts("\n--------");
    ImpLista(resto(a));
    return 0;

}
