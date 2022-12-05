typedef struct Nodo {
       Elem dato;
       struct Nodo *sig;
}*Pila;

Pila empty(){ return NULL;}
Pila push(Elem e, Pila p){
   Pila t=(Pila)malloc(sizeof(struct Nodo));
   t->dato=e;
   t->sig=p;
   return t;
}
int isempty(Pila p){return p==NULL;}
Elem top(Pila p){return p->dato;}
Pila pop(Pila p){return p->sig;}

void ImpPila(Pila p){
     if(!isempty(p)){
        ImpElem(top(p));
        ImpPila(pop(p));
     }
}
