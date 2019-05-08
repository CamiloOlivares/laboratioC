#include <stdlib.h>
#include <stdio.h>
#include "arbolBin.h"


void main(){
	Ab *arbol = iniciarArbolBinario();
	arbol = insertarValor(arbol,'1');
	arbol = insertarValor(arbol,'N');
	arbol = insertarValor(arbol,'2');
	recorrerOrdenAb(arbol);
	convertirN(arbol);
	printf("\n");
	recorrerOrdenAb(arbol);
	printf("\n");
	//arbol = deserializar();
	//recorrerOrdenAb(arbol);
	

}
