#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
	char valor;
	struct nodo *hijo_izquierdo,*hijo_derecho;
}Ab;

/* escribir un arbol binario en txt */
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

Ab *insertarValor( Ab *arbol, char valor ){
	//if(valor == 'N') valor = NULL;
	if(arbol == NULL){
		arbol = (Ab *)malloc(sizeof(Ab));
		arbol->valor = valor;
		arbol->hijo_izquierdo = NULL;
		arbol->hijo_derecho = NULL;	
	}
	else{
		if( arbol->hijo_izquierdo == NULL || (arbol->hijo_izquierdo->valor != 'N' && arbol->hijo_derecho != NULL) ){
			if(arbol->hijo_izquierdo == NULL){
				arbol->hijo_izquierdo = insertarValor(arbol->hijo_izquierdo,valor);
			}
			else if(arbol->hijo_izquierdo->hijo_izquierdo != NULL && arbol->hijo_izquierdo->hijo_derecho!=NULL){
				if(arbol->hijo_derecho->hijo_izquierdo == NULL || arbol->hijo_derecho->hijo_izquierdo == NULL){
					arbol->hijo_derecho = insertarValor(arbol->hijo_derecho,valor);
				}
			}
			
		}
		else if(arbol->hijo_derecho == NULL || arbol->hijo_derecho->valor != 'N'){
			arbol->hijo_derecho = insertarValor(arbol->hijo_derecho,valor);
		}
		else if(arbol->hijo_izquierdo->valor == 'N' && arbol->hijo_derecho->valor != 'N'){
			arbol->hijo_derecho = insertarValor(arbol->hijo_derecho,valor);
		}
		else if(arbol->hijo_derecho->valor == 'N'){
			arbol->hijo_izquierdo = insertarValor(arbol->hijo_izquierdo,valor);
		}
	}
	return arbol;	
}

Ab *convertirN(Ab *arbol){
	if( arbol!=NULL ){
		if(arbol->valor == 'N'){
			arbol = NULL;
		}else{
		arbol->hijo_izquierdo = convertirN(arbol->hijo_izquierdo);
		arbol->hijo_derecho = convertirN(arbol->hijo_derecho);
		}
	
	}
	return arbol;
}

//generar arbol binario en memoria, a partir de un txt
Ab *deserializar(){
	FILE *archivo = fopen("arbolBinario.txt", "r");
	Ab *arbolBinario = iniciarArbolBinario();
	char valor;
	while( !feof(archivo) ){
		valor = fgetc(archivo);
		printf("%c \n",valor);
		arbolBinario = insertarValor(arbolBinario,valor);
		printf("%c \n",arbolBinario->valor);
	}
	
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



