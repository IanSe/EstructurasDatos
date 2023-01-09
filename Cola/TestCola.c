#include<stdio.h>
#include<stdlib.h>
#include"C:\Santiago\ClasesEnLinea\Ago2022\2AV2\Elem\ElemInt.h"
#include"C:\Santiago\ClasesEnLinea\Ago2022\2AV2\Cola\Cola.h"

int main(){

   Cola q=nueva();
   q=formar(formar(formar(formar(q,1),2),3),4);
   ImpElem(primero(q));
   desformar(q);
   ImpElem(primero(q));

   return 0;

}

