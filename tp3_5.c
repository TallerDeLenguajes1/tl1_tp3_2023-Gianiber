#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(){
    char **nombres;
    char *buff;
    int cant;
    buff = (char*) malloc(MAX * sizeof(char));
    printf("Ingrese cuantos nombres desea registrar:\n");
    scanf("%d",&cant);
    nombres = (char**) malloc(cant * sizeof(char *));
    for (int i = 0; i < cant; i++)
    {
        printf("Nombre %d: ",i+1);
        fflush(stdin);
        gets(buff);
        nombres[i] = malloc(strlen(buff)+1 * sizeof(char));
        strcpy(nombres[i],buff);
    }
    printf("Los nombres ingresados son:\n");
    for (int i = 0; i < cant; i++)
    {
        printf("%s\n",nombres[i]);
        free(nombres[i]);
    }
    free(buff);
    return 0;
}