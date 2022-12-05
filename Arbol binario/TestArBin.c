#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ElemInt.h"
#include"ArBin.h"

int mayor(int,int);
int altura(ArBin);
int EsHoja(ArBin);
int NumElemsAB(ArBin);
int main(){

   ArBin b=consAB(50,vacioAB(),vacioAB());
   ArBin c=consAB(25,vacioAB(),vacioAB());
   ArBin a=consAB(5,b,c);
   ArBin d=consAB(10,consAB(5,consAB(1,vacioAB(),vacioAB()),consAB(2,vacioAB(),vacioAB())),
                  consAB(20,vacioAB(),vacioAB()));



   esvacioAB(d)?puts("Si."):puts("No.");
   esvacioAB(vacioAB())?puts("Si."):puts("No.");
   ImpElem(raiz(d));
   ImpElem(raiz(izqAB(d)));
   ImpElem(raiz(derAB(izqAB(d))));
   printf("\n-----\n%d\n",NumElemsAB(d));
   printf("\nAltura = %d\n",altura(d));
   printf("\nAltura = %d\n",altura(izqAB(d)));
   printf("\nAltura = %d\n",altura(derAB(d)));
/*
   EsHoja((b))?puts("Si."):puts("No.");
   EsHoja((c))?puts("Si."):puts("No.");
   EsHoja((a))?puts("Si."):puts("No.");

   printf("%d\n",NumElemsAB(a));
   puts("Preorder:");
   PreOrd(a);
   puts("\nInorder:");
   InOrd(a);
   puts("\nPostorder:");
   PostOrd(a);
*/

   return 0;

}

int NumElemsAB(ArBin a){
   if(esvacioAB(a))
      return 0;
   else
      return 1+NumElemsAB(izqAB(a))+NumElemsAB(derAB(a));
};
int mayor(int a, int b){
    if(a>b)
        return a;
    else
        return b;
};
int altura(ArBin a){
    if(esvacioAB(a))
        return 0;
    else if(EsHoja(a))
            return 1;
         else
            return 1+mayor(altura(izqAB(a)),altura(derAB(a)));
};
int EsHoja(ArBin a){
     return esvacioAB(izqAB(a))&&esvacioAB(derAB(a));
}
