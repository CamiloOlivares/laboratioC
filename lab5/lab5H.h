#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
	char dato;
	struct nodo *hijoIzq,*hijoDer;
}Arbol;

int llenarArreglo(char arreglo[],int pos,Arbol *arbol);

Arbol *iniciaArbol(){
	Arbol *arbol = NULL;
	arbol = (Arbol *)malloc(sizeof(Arbol));
	arbol->dato = '2';
	arbol->hijoDer = (Arbol *)malloc(sizeof(Arbol));
	arbol->hijoIzq = (Arbol *)malloc(sizeof(Arbol));
	arbol->hijoDer->dato = '4';
	arbol->hijoIzq->dato = '1';
	arbol->hijoDer->hijoDer = NULL;
	arbol->hijoDer->hijoIzq = NULL;
	arbol->hijoIzq->hijoDer = NULL;
	arbol->hijoIzq->hijoIzq = NULL;
	return arbol;
}

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}

int altura(Arbol *unArbol){
	if(unArbol==NULL){
		return -1;
	}
	return(1+(max(altura(unArbol->hijoDer),altura(unArbol->hijoIzq))));
}

char *crearArbolEnArreglo(Arbol *unArbol){
	int h = altura(unArbol);
	char *arreglo;
	int nodos = 2^(h+1)-1;
	arreglo = (char *)malloc(sizeof(char) * (nodos));
	int pos = 0;
	int i=0;
	arreglo[0]=unArbol->dato;
	arreglo[1]=unArbol->hijoDer->dato;
	arreglo[2]=unArbol->hijoIzq->dato;
	//llenarArreglo(arreglo,pos,unArbol);
	for(i=0;i<nodos;i++){
		printf("\n %i",arreglo[i]);
	}
	return arreglo;
}


int llenarArreglo(char *arreglo,int pos,Arbol *unArbol){
	if(unArbol==NULL)return 0;
	arreglo[pos] = unArbol->dato;
	llenarArreglo(arreglo,2*pos+1,unArbol->hijoDer);
	llenarArreglo(arreglo,2*pos+2,unArbol->hijoIzq);
}



