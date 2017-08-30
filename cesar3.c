#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 128

//  	A-65
//		Z-90
//		Espacio-32

char adelante(char caracter, int cantidad);
char atras(char caracter, int cantidad);
void encriptar(char cadena[],int cantidad);
void desencriptar(char cadena[],int cantidad);
void mayusculas(char cadena[]);

int main(int argc, char const *argv[]){
	
	char cadena[MAX];
	int opc,cantidad;
	printf("Intreduce una cadena:\t");
	scanf("%128[^\n]",cadena);
	//printf("\n\t\tOpciones:\n1)\tEncriptar \n2)\tDesencriptar\n");
	//scanf("%d",&opc);
	printf("Introduce cantidad de espacios a mover:\t");
	scanf("%d",&cantidad);

	mayusculas(cadena);
	encriptar(cadena,cantidad);
	printf("Encriptada:\t%s\n",cadena);

	desencriptar(cadena, cantidad);
	printf("Descencriptada:\t%s\n", cadena);

	
	

	return 0;
}



void encriptar(char cadena[], int cantidad){	
	for(int i = 0; i<strlen(cadena); i++){
		if(i%2){
			cadena[i] = atras(cadena[i],cantidad);
		}else{
			cadena[i] = adelante(cadena[i],cantidad);
		}
	}
}

void desencriptar(char cadena[], int cantidad){
	for(int i = 0; i<strlen(cadena); i++){
		if(!(i%2)){
			cadena[i] = atras(cadena[i],cantidad);
		}else{
			cadena[i] = adelante(cadena[i],cantidad);
		}
	}
}

char adelante(char caracter, int cantidad){
	for(; cantidad > 0; cantidad--){
		if(caracter==32)
			return caracter;
		else if(caracter==90)
			caracter = 65;
		else
			caracter++;
	}
	return caracter;
}

char atras(char caracter, int cantidad){
	for(; cantidad > 0; cantidad--){
		if(caracter==32)
			return caracter;
		else if(caracter==65)
			caracter = 90;
		else
			caracter--;
	}
	return caracter;
}

void mayusculas(char cadena[]){
	for(int i = 0 ; i < strlen(cadena); i++)
		cadena[i] =  toupper(cadena[i]);
}
