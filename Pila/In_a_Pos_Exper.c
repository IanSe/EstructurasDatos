#include<stdio.h>
#include<stdlib.h>
#include"Elem.h"
#include"Pila.h"

void Ina_Pos(Elem []);
Pila SacaOpsI(Pila);
Pila ProcesaOp(Elem,Pila);

int main(int argc, char *argv[]){
   Elem *in=*(argv+1);


   Ina_Pos(in);


   return 0;
}

void Ina_Pos(Elem in[]){
     Pila ops=empty();
     int i=0;
     Elem c;
     while(c=in[i]){
         if(EsParI(c))
            ops=push(c,ops);
         else if(EsParD((c)))
                   ops=SacaOpsI(ops);
              else if(EsOperador(c))
                       ops=ProcesaOp(c,ops);
                   else
                       ImpElem(c);
         i++;
      }
      while(!isempty(ops)){
            ImpElem(top(ops));
            ops=pop(ops);
      }
};

Pila SacaOpsI(Pila ops){
    while(!EsParI(top(ops))){
        ImpElem(top(ops));
        ops=pop(ops);
    }
    return ops=pop(ops);
}
Pila ProcesaOp(Elem c, Pila ops){
    int x, y, z; x=y=z=0;
    if((x=isempty(ops))||(y=EsParI(top(ops)))||(y=prec(c)>prec(top(ops)))){
        printf("x=%d, y=%d, z=%d\n",x,y,z); fflush(stdin); getchar();
        return push(c,ops);
    }
    else {
        while((x=!isempty(ops))&&(y=!EsParI(top(ops)))&&(z=prec(c)<=prec(top(ops)))){
            printf("x=%d, y=%d, z=%d\n",x,y,z); fflush(stdin); getchar();
            ImpElem(top(ops));
            ops=pop(ops);
        }
        return push(c,ops);
    }
};
