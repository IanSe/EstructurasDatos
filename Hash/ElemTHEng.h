typedef struct{
      char *ing;
      char *esp;
} Elem;

Elem LeeElem(FILE *ent){
    Elem e;
    e.ing=(char*)malloc(25);
    e.esp=(char*)malloc(25);
    fscanf(ent,"%s",e.ing);
    fscanf(ent,"%s",e.esp);
    return e;
}

Elem LeeEsp(Elem t){
	Elem e;
	e.esp=(char*)malloc(25);
	scanf("%s",e.esp);
	e.ing=t.ing;
	return e;
}

Elem LeeElemCons(){
    Elem e;
    e.ing=(char*)malloc(sizeof(char)*25);
    e.esp=(char*)malloc(25);
    puts("English: ");
    scanf("%s",e.ing);
    puts("Spanish: ");
    scanf("%s",e.esp);
    return e;
}
/*
Elem LeeElemF(FILE *ent, Elem e){
    e.sim=(char*)malloc(3);
    e.nombre=(char*)malloc(15);
    fscanf(ent,"%s%s%d%f",e.sim,e.nombre,&e.na,&e.ma);

    return e;
}
*/
void ImpElemF(FILE *sal,Elem e){
    fprintf(sal,"%s\n",e.ing);
    fprintf(sal,"%s\n",e.esp);
}

void ImpElem(Elem e){
    printf("%s\t",e.ing);
    printf("%s\t",e.esp);
}

void ImpEng(Elem e){ printf("\t'%s'",e.ing);}

int EsIgualEsp(Elem e1, Elem e2){return !strcmp(e1.esp,e2.esp);}
int EsIgual(Elem e1, Elem e2){return !strcmp(e1.ing,e2.ing);}

int Llave(Elem e){
    int n=0,i=0;
    char *p= e.ing;
    while(e.ing[i])
        n=n+e.ing[i++];

    return n;
    }
