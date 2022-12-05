#include<stdio.h>
#include<stdlib.h>
#include"Elem.h"
#include"Pila.h"

Pila decabin(int);
int leeint();
void impBin(Pila);
Pila PegaPilas(Pila, Pila);
Pila InviertePila(Pila);

int main(){
	int n;
	printf("Escribe el numero ");
	scanf("%d", &n);
	Pila dab = decabin(n);
	ImpPila(InviertePila(dab));
	
	return 0;
}

Pila decabin(int n)
{   
    if(n==0){
    	return empty();
	}else{
		char b;
		b = ( n % 2 == 0 ? 0 : 1);
		n=n/2;
		return push(b,decabin(n));
	}
}

Pila PegaPilas(Pila l1, Pila l2){
    if(isempty(l1))
         return l2;
    else
        return push(top(l1),PegaPilas(pop(l1),l2));
};

Pila InviertePila(Pila p){
    if(isempty(p))
        return p;
    else{
        return PegaPilas(InviertePila(pop(p)),push(top(p),empty()));
	}
}
