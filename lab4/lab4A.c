#include <stdlib.h>
#include <stdio.h>
#include "arbolBinario.h"


void main(){
	Ab *arbol = iniciarArbolBinario();
	insertarAB(arbol,'1');
	printf("%c",arbol->valor);
	insertarAB(arbol,'2');
	recorrerOrdenAb(arbol);
	printf("\n");
	//arbol = deserializar();
	//recorrerOrdenAb(arbol);
	

}
