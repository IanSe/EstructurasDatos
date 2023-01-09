#include<stdio.h>
#include<stdlib.h>
#include "ElemInt.h"
#include "Lista.h"

int main(){
   Lista l1 = cons(2,cons(3,cons(5,vacia())));
   ImpLista(l1);
   return 0;

}

