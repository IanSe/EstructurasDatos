typedef struct NodoCir{
      Elem dato;
      struct NodoCir *sig;
}*Circular;

Circular vaciaCir(){return NULL;}

int esvaciaCir(Circular c){ return c==NULL;}

Circular consCir(Circular c, Elem e){
       Circular t=(Circular)malloc(sizeof(struct NodoCir));
       t->dato=e;
       if(esvaciaCir(c)){
             c=t;
             c->sig=t;
       }else{
             t->sig=c->sig;
             c->sig=t;
           }
       return t;
}

Elem primeroCir(Circular c){ return c->sig->dato;}
Circular desformarCir(Circular c){
        Circular t=c->sig;
        if(c==c->sig)
             c=vaciaCir();
        else
             c->sig=c->sig->sig;
        free(t);
        return c;
}

Circular rotarCirc(Circular c){ return c->sig;}

