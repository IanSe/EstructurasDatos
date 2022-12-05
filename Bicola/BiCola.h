typedef struct NodoBi{
         Elem dato;
         struct NodoBi *izq;
         struct NodoBi *der;
        } *ApNodoBi;

typedef struct BiNodo{
           ApNodoBi izq;
           ApNodoBi der;
           }*BiCola;

BiCola nuevaBi(){
     BiCola t=(BiCola)malloc(sizeof(struct BiNodo));
     t->izq=t->der=NULL;
     return t;
}

int esnuevaBi(BiCola q){return (q->izq==NULL)&&(q->der==NULL);}

BiCola formIzq(Elem e, BiCola q){
     ApNodoBi t=(ApNodoBi)malloc(sizeof(struct NodoBi));
     t->dato=e;
     t->izq=NULL;
     t->der=NULL;
     if(esnuevaBi(q))
         q->izq=q->der=t;
     else{
         t->der=q->izq;
         q->izq->izq=t;
         q->izq=t;
     }
     return q;
}

BiCola formDer(BiCola q, Elem e){
     ApNodoBi t=(ApNodoBi)malloc(sizeof(struct NodoBi));
     t->dato=e;
     t->izq=NULL;
     t->der=NULL;
     if(esnuevaBi(q))
         q->izq=q->der=t;
     else{
         t->izq=q->der;
         q->der->der=t;
         q->der=t;
     }
     return q;
}
Elem izquierdo(BiCola q){return q->izq->dato;};
Elem derecho(BiCola q){return q->der->dato;};
BiCola desfIzq(BiCola q){
  ApNodoBi t=q->izq;
  if(q->izq==q->der)
       q->izq=q->der=NULL;
  else{
       q->izq=q->izq->der;
       q->izq->izq=NULL;
  }
  free(t);
  return q;
}

BiCola desfDer(BiCola q){
  ApNodoBi t=q->der;
  if(q->izq==q->der)
       q->izq=q->der=NULL;
  else{
       q->der=q->der->izq;
       q->der->der=NULL;
  }
  free(t);
  return q;
}



/*
Espec BiCola
     nuevaBi:-> BiCola;
     formIzq: Elem, BiCola -> BiCola;
     formDer: BiCola, Elem -> BiCola;
     esnuevaBi: BiCola -> Bool;
     izquierdo: BiCola -> Elem;
     derecho: BiCola -> Elem;
     desfIzq: BiCola -> BiCola;
     desfDer: BiCola -> BiCola;
  Axiomas Elem e1, e2; BiCola b;
     [b1] esnuevaBi(nuevaBi())= Cierto;
     [b2] esnuevaBi(formIzq(e1,b))= Falso;
     [b3] esnueva(formDer(b,e2)) = Falso;
     [b4] desfIzq(nuevaBi())= ERROR;
     [b5] desfIzq(formIzq(e1,b)) = b;
     [b6] desfIzq(formDer(b,e2))=
                  Si esnuevaBi(b)
                      ret b;
                  Sino
                      ret formDer(desfIzq(b),e2);
     [b7] desfDer(nuevaBi())= ERROR;
     [b8] desfDer(formIzq(e1,b))=
                  Si esnuevaBi(b)
                      ret b;
                  Sino
                      ret formIza(e1,desfDer(b));
     [b9] desfDer(formDer(e1,b)) = b;
Fin BiCola.
*/
