            typedef struct Nodo{
                Elem dato;
                struct Nodo *sig;
            } *ApNodo;

            typedef struct CNodo{
                ApNodo prim;
                ApNodo ult;
            }*Cola;

            Cola nueva(){
            Cola t=(Cola) malloc(sizeof(struct CNodo));
            t->prim=t->ult=NULL;
            return t;
}

        int esnueva(Cola q){return (q->prim==NULL)&&(q->ult==NULL);}


        Cola formar(Cola q, Elem e){
            ApNodo t=(ApNodo)malloc(sizeof(struct Nodo));
            t->dato=e;
            t->sig=NULL;
            if(esnueva(q))
                 q->prim=q->ult=t;
            else{
                q->ult->sig=t;
                q->ult=t;
            }
            return q;
}
       Elem primero(Cola q){return q->prim->dato;}

       Cola desformar(Cola q){
           ApNodo t=q->prim;
           if(q->prim==q->ult)
                 q->prim=q->ult=NULL;
           else
                 q->prim=q->prim->sig;
           free(t);
       }

    /*
            Espec Cola
               nueva:->Cola;
               formar: Cola, Elem -> Cola;
               esnueva: Cola -> Bool;
               primer: Cola -> Elem;
               desformar: Cola -> Cola;
              Axiomas: Elem e, Cola q;
                [q1] esnueva(nueva())= Verdadero;
                [q2] esnueva(formar(q,e))= Falso;
                [q3] primer(nueva())=ERROR;
                [q4] primero(formar(q,e))= Si esnueva(q) ret e;
                                           Sino ret primero(q);
                [q5] desformar(nueva())= ERROR;
                [q6] desformar(formar(q,e))= Si esnueva(q) ret q;
                                     Sino ret formar(desformar(q),e);
            Fin Cola.

            */
