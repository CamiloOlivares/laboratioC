#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
	char valor;
	struct nodo *hijo_izquierdo,*hijo_derecho;
}Ab;

//serializar: generar arbol binario en txt, a partir de un arbol binario en memoria
void escribe(int valor){
	FILE *archivo = fopen("arbolBinario.txt", "a");
	fwrite(&valor, 1, 1, archivo);
	fclose(archivo);	
}

void serializar(Ab *arbol){
	if(arbol == NULL){
		FILE *archivo = fopen("arbolBinario.txt", "a");
		fwrite("N", 1, 1, archivo);
		fclose(archivo);
	}
	else{
		escribe(arbol->valor);
		serializar(arbol->hijo_izquierdo);
		serializar(arbol->hijo_derecho);
	}
}

//iniciar arbol binario
Ab *iniciarArbolBinario(){
	Ab *arbol= NULL;
	return arbol;
}

void insertarAB( Ab *arbol, char valor ){
	if(arbol == NULL && valor != 'N'){
		arbol = (Ab *)malloc(sizeof(Ab));
		arbol->valor = valor;
		arbol->hijo_izquierdo = NULL;
		arbol->hijo_derecho = NULL;
	}
}

int llenarArbolBinario(Ab *arbol, char *valores, int inicio){
	if( valores[inicio] != 'N' ){
		insertarAB(arbol, valores[inicio]);
		inicio = llenarArbolBinario(arbol->hijo_izquierdo,valores,inicio+1);
		inicio = llenarArbolBinario(arbol->hijo_derecho,valores,inicio+1);
		return inicio+1;
	}
	return inicio;
}


//deserializar: genera un arbol binario en memoria, a partir de un txt
Ab *deserializar() {
	FILE *archivo = fopen("arbolBinario.txt", "r");
	Ab *arbolBinario = iniciarArbolBinario();
	char *valores;
	int i = 0;
	char caracter_leido = fgetc(archivo);
	while( caracter_leido != feof(archivo) ){
		valores[i] = caracter_leido;
		caracter_leido = fgetc(archivo);
		i++;
	}
	llenarArbolBinario(arbolBinario, valores, 0);
	
	return(arbolBinario);
}

void recorrerOrdenAb(Ab *arbol){
	if( arbol!=NULL ){
		printf("%c ",arbol->valor);
		recorrerOrdenAb(arbol->hijo_izquierdo);
		recorrerOrdenAb(arbol->hijo_derecho);	
	}
	else{
		
		printf("N");	
	}
}


