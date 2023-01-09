typedef struct Nodo{
            Elem dato;
            struct Nodo *sig;
     } *Lista;

Lista vacia(){return NULL;}
Lista cons(Elem e, Lista l){
    Lista t=(Lista)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=l;
    return t;
}

int esvacia(Lista l){return l==vacia();}
Elem cabeza(Lista l){return l->dato;}
Lista resto(Lista l){return l->sig;}

int NumElems(Lista l){
	if(esvacia(l))
        return 0;
    else
        return 1+NumElems(resto(l));
};

void ImpLista(Lista l){
     if(!esvacia(l)){
        ImpElem(cabeza(l));
        ImpLista(resto(l));
     }
};

Lista PegaListas(Lista l1, Lista l2){
    if(esvacia(l1))
         return l2;
    else
        return cons(cabeza(l1),PegaListas(resto(l1),l2));
};

Lista LeeLista(Lista a){
    Elem x;
    while((x=LeeElem())!=0)
          a=cons(x,a);
    return a;
}
Lista InvierteLista(Lista l){
     if(esvacia(l))
         return l;
     else
         return PegaListas(InvierteLista(resto(l)),cons(cabeza(l),vacia()));
};

int SonIguales(Lista l1, Lista l2){
     if(esvacia(l1))
        if(esvacia(l2))
           return 1;
        else
            return 0;
     else if(esvacia(l2))
              return 0;
          else if(EsIgual(cabeza(l1),cabeza(l2)))
                  return SonIguales(resto(l1),resto(l2));
               else
                  return 0;
};
