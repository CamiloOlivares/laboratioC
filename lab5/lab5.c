#include <stdlib.h>
#include <stdio.h>
#include "lab5H.h"

void main(){
	Arbol *arbol = iniciaArbol();
	printf("%c  %c  %c",arbol->dato,arbol->hijoDer->dato,arbol->hijoIzq->dato);
	int h = altura(arbol);
	int nodos = 0;
	nodos = 2^(h+1)-1;
	printf("\n %i %i",h,nodos);
	char arbolArr[nodos];
	*arbolArr = crearArbolEnArreglo(arbol);
	int i;
	for(i=0;i<nodos;i++){
		printf("\n %i",arbolArr[i]);
	}
}
