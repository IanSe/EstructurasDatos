
#include<stdio.h>
#include<stdlib.h>
#include"ElemInt.h"
#include"BiCola.h"

BiCola rotaDer(BiCola);
BiCola rotaIzq(BiCola);
void ImpBiColaIzq(BiCola);
void ImpBiColaDer(BiCola);
BiCola rotarDerN(BiCola, int);
BiCola rotarIzqN(BiCola, int);

int main(){
   int i;
   BiCola q=nuevaBi();

   for(i=1;i<=10;i++)
        q=formDer(q,i);

   ImpBiColaIzq(rotarDerN(q,5));

   puts("\n------");

   ImpBiColaDer(rotarIzqN(q,5));
/*
   ImpBiColaIzq(q);
   puts("\n------");
   ImpBiColaIzq(q);
*/
/*

   q=rotaDer(q);
   ImpElem(izquierdo(q));
   ImpElem(derecho(q));
   puts("\n------");
   q=rotaIzq(q);
   ImpElem(izquierdo(q));
   ImpElem(derecho(q));
*/
   return 0;
}

BiCola rotaDer(BiCola q){
      q=formIzq(derecho(q),q);
      q=desfDer(q);
      return q;
};

BiCola rotaIzq(BiCola q){
      q=formDer(q,izquierdo(q));
      q=desfIzq(q);
      return q;
};

void ImpBiColaIzq(BiCola q){
     BiCola t=nuevaBi();
     while(!esnuevaBi(q)){
         ImpElem(izquierdo(q));
         t=formDer(t,izquierdo(q));
         q=desfIzq(q);
     }
     while(!esnuevaBi(t)){
         q=formDer(q,izquierdo(t));
         t=desfIzq(t);
     }
};

void ImpBiColaDer(BiCola q){
     BiCola t=nuevaBi();
     while(!esnuevaBi(q)){
         ImpElem(derecho(q));
         t=formIzq(derecho(q),t);
         q=desfDer(q);
     }
     while(!esnuevaBi(t)){
         q=formIzq(derecho(t),q);
         t=desfDer(t);
     }
};

BiCola rotarDerN(BiCola q, int n){
    if(n==0){
    	return q;
	}else{
		rotarDerN(rotaDer(q), n-1);
	}
}

BiCola rotarIzqN(BiCola q, int n){
    if(n==0){
    	return q;
	}else{
		rotarDerN(rotaDer(q), n-1);
	}
}
