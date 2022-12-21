#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ElemTH.h"
#include"ListaTH.h"
#include"TablaH.h"

int main(int argc, char *argv[]){

    Elem paises[10];
    FILE *ent=fopen(*++argv,"r");
 //   FILE *sal=fopen(*++argv,"w");
    int n=223;
    TablaH  t=consTH(n);
    Elem e;
    char nompais[80];
    int i;

    for(i=1;i<=183;i++){
       e=LeeElem(ent);
       t=InsElem(e, t, n);
    }

 //   puts("Lista de paises:");
   // ImpTablaH(t,7);

 //   printf("La llave de %s es %d\n",paises[0].pais,Llave(paises[0]));
    printf("Cual pais quieres conocer?");
    scanf("%s",nompais);
    strcpy(e.pais,nompais);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.pais,Llave(e),Llave(e)%n);
    Consulta(e,t,n);

    printf("Cual pais quieres eliminar?");
    scanf("%s",nompais);
    strcpy(e.pais,nompais);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.pais,Llave(e),Llave(e)%n);
    Borra(e,t,n);

    printf("Cual pais quieres conocer?");
    scanf("%s",nompais);
    strcpy(e.pais,nompais);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.pais,Llave(e),Llave(e)%n);
    Consulta(e,t,n);

 //   InsElem(TablaH t, int n, Elem e)

    printf("Cual pais quieres agregar?");
    e=LeeElemCons();
    t=InsElem(e, t, n);
    //t[Llave(e)%n]=cons(e,t[Llave(e)%n]);

    printf("Cual pais quieres conocer?");
    scanf("%s",nompais);
    strcpy(e.pais,nompais);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.pais,Llave(e),Llave(e)%n);
    Consulta(e,t,n);


    return 0;


}
