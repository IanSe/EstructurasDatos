typedef struct{
      char *pais;
      char *capital;
} Elem;

Elem LeeElem(){
    Elem e;
    e.pais=(char*)malloc(25);
    e.capital=(char*)malloc(25);
    scanf("%s",e.pais);
    scanf("%s",e.capital);

    return e;
}

Elem LeeElemF(FILE *ent){
    Elem e;
    e.pais=(char*)malloc(25);
    e.capital=(char*)malloc(25);
    fscanf(ent,"%s%s",e.pais,e.capital);

    return e;
}

void ImpElem(Elem e){
    printf("%s\t%s\n",e.pais,e.capital);
}

int EsIgual(Elem e1, Elem e2){return !strcmp(e1.pais,e2.pais);}
