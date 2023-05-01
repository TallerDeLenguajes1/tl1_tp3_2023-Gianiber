#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(){
    char *nombres[5];
    char *buff;
    buff = (char*) malloc(MAX * sizeof(char));
    printf("Ingrese 5 nombres:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre %d: ",i+1);
        gets(buff);
        nombres[i] = (char*) malloc(strlen(buff)+1 * sizeof(char));
        strcpy(nombres[i],buff);
    }
    printf("Los nombres ingresados son:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n",nombres[i]);
        free(nombres[i]);
    }
    free(buff);
    return 0;
}