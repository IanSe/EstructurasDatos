#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"ElemTHEng.h"
#include"ListaTH.h"
#include"TablaH.h"

void Menu(FILE *f);
int CerrarArch(FILE *f);
void AgregaPal(Elem, TablaH, int);
void Diccionario(char[], Elem, int, TablaH);
Lista Palabras(TablaH, int, int, int);
void EliminaPal(char[], Elem, int, TablaH);

int main(int argc, char *argv[]){
    FILE *ent=fopen(*++argv,"r");
    Menu(ent);
	CerrarArch(ent);
    return 0;
}

Lista Palabras(TablaH t, int n, int cont, int ra){
	if(ra >= n)
		ra = rand() % n;
	
	if(!esvacia(t[ra]) && cont>0)
		return cons(DevuelveLlave(t[ra]), Palabras(t,n,cont-1, ra+1));
	else if(!esvacia(t[ra]) && cont==0)
		return vacia();
	else if(esvacia(t[ra]))
		return Palabras(t,n,cont,ra+1);
}


void Menu(FILE *f){
	int n=101, opt;
    TablaH t=consTH(n);
    Elem e;
    char word[80];
    int i;
    for(i=1;i<=100;i++){
       e=LeeElem(f);
       t=InsElem(e, t, n);
    }
    puts("\t1. Examen\n\t2. Agregar Palabras\n\t3. Diccionario\n\t4. Eliminar Palabras\n\t5. Imprimir Tabla\n");
    puts("Selecciona la opción que quieres");
    scanf("%d",&opt);
    switch(opt){
    	case 1:
			puts("Seleccionaste examen, se te mostraran 10 palabras en ingles y tendras que escribir su significado");
    		int counter=0;
			Elem tem, pal[10];
    		srand(time(NULL));
			int na = rand() % (10 + 1) - 1;   
			Lista l = Palabras(t,n,10,na);
			for(i=0;i<10;i++){
				pal[i] = cabeza(l);
				l = resto(l);
				ImpEng(pal[i]);
				puts("\nEscribe su significado: ");
				tem = LeeEsp(pal[i]);
				if(EsIgualEsp(tem, pal[i])) counter++; 
			}
			fflush(stdin);
			printf("Tu puntaje en el examen fue: %d", counter);
		break;
		case 2: 
			AgregaPal(e, t, n);
    	break;
    	case 3:
    		Diccionario(word, e, n, t);
    	break;
    	case 4:
    		EliminaPal(word, e, n, t);
    	break;
    	case 5:
    		ImpTablaH(t, n);
    	break;
    	default:
    		puts("Opcion Invalida");
    	break;
	}
}

void Diccionario(char word[], Elem e, int n, TablaH t){
	printf("Cual palabra en ingles quieres conocer?");
    scanf("%s",word);
    strcpy(e.ing,word);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.ing,Llave(e),Llave(e)%n);
    Consulta(e,t,n);
}

void EliminaPal(char word[], Elem e, int n, TablaH t){
	printf("Cual palabra quieres eliminar?");
    scanf("%s",word);
    strcpy(e.ing,word);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.ing,Llave(e),Llave(e)%n);
    Borra(e,t,n);
}

void AgregaPal(Elem e, TablaH t, int n){
	puts("Cuantas palabras quieres agregar?");
	int ntem,i;
	scanf("%d",&ntem);
	for(i=0;i<ntem;i++){
    	e=LeeElemCons();
    	t=InsElem(e, t, n);
    }
}

int CerrarArch(FILE *f){ return fclose(f);}

