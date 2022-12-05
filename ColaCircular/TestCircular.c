#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ElemInt.h"
#include"Circular.h"

void ImpCircular(Circular);
Elem dado(Circular);
Circular consDado(int);

int main(){

   srand(time(NULL));

   Circular q=consDado(6);
/*
   q=consCir(consCir(consCir(consCir(q,1),2),3),4);
*/

   while(1){
        ImpElem(dado(q));
        puts("\n---------");
        getchar();
   }

   return 0;

}


void ImpCircular(Circular c){
     Circular t=c;
     do{
         ImpElem(primeroCir(t));
         t=rotarCirc(t);
     }while(t!=c);
};

Elem dado(Circular c){
      int n= rand()%12347;
      while(n--)
        c=rotarCirc(c);
      return primeroCir(c);
};

Circular consDado(int n){
    int i;
    Circular c=vaciaCir();
    for(i=1;i<=n;i++)
        c=consCir(c,i);
    return c;
};
