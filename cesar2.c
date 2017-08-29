#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128
//prototipo de funciones.
void encriptar(char frase[MAX],int numero);
void desencriptar(char frase[MAX],int numero);
 
//Procedimiento principal.
int main()
{
    //Variables necesarias
    int x;
    char cadena[MAX];
    printf("introduce una cadena:     ");
    //Un especificador que admite texto:
    scanf("%128[^\n]", cadena);
    //Vacía el buffer del teclado
    while(getchar()!='\n');
    //Pedimos el número
    printf("introduce un numero : ");
    scanf("%d",&x);
    //Vacía el buffer del teclado
    while(getchar()!='\n');
    //Llamamos a la función encriptar
    encriptar(cadena, x);
    getchar();
    //Llamamos a la función desencriptar
    desencriptar(cadena, x);
    getchar();
    //Salimos
    return 0;
}

//Función para encriptar Cifrado Cesar en C
void encriptar(char frase[MAX],int numero)
{
    int i=0;
    char letra;
    while(frase[i]!='\0')
    {
        frase[i]=frase[i]+numero;
        i++;
    }
    printf("\nLa frase encriptado es:\n%s\n",frase);
}

//Función para desencriptar Cifrado Cesar en C
void desencriptar(char frase[MAX],int numero)
{
    int i=0;
    while(frase[i]!='\0')
    {
        frase[i]=frase[i]-numero;
        i++;
    }
    printf("\nLa frase desencriptada es:\n%s\n",frase);
}
