#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
typedef struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto ;
typedef struct 
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;          // El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} Cliente ;

float Costo(Producto Prod);

int main()
{
    Cliente *carga;
    int cant;
    float total;
    char *buff,*random;
    srand(time(NULL));
    buff = (char *)malloc(MAX * sizeof(char));
    random = (char *)malloc(MAX * sizeof(char));
    printf("Ingrese la cantidad de clientes:");
    scanf("%d", &cant);
    carga = malloc(cant * sizeof(Cliente));
    for (int i = 0; i < cant; i++)
    {
        total = 0;
        carga[i].ClienteID = i + 1;
        fflush(stdin);
        printf("Nombre del cliente %d: ", i + 1);
        gets(buff);
        carga[i].NombreCliente = (char *)malloc(strlen(buff) + 1 * sizeof(char));
        strcpy(carga[i].NombreCliente, buff);
        carga[i].CantidadProductosAPedir = rand() % 4 + 1;
        carga[i].Productos = malloc(carga[i].CantidadProductosAPedir * sizeof(Producto));
        fflush(stdin);
        printf("------Cliente %d------\n", carga[i].ClienteID);
        printf("Nombre del cliente: %s\n", carga[i].NombreCliente);
        for (int j = 0; j < carga[i].CantidadProductosAPedir; j++)
        {
            carga[i].Productos[j].ProductoID = j + 1;
            carga[i].Productos[j].Cantidad = rand() % 9 + 1;
            random = TiposProductos[rand() % 4];
            fflush(stdin);
            carga[i].Productos[j].TipoProducto = (char*) malloc(strlen(random)+1 * sizeof(char));
            strcpy(carga[i].Productos[j].TipoProducto, random);
            carga[i].Productos[j].PrecioUnitario = (float)(rand() % 9000 + 1000)/100.00;
            total = total + Costo(carga[i].Productos[j]);
            fflush(stdin);
            printf("Producto: %s\n", carga[i].Productos[j].TipoProducto);
            printf("Cantidad: %d\n", carga[i].Productos[j].Cantidad);
            printf("Precio: %.2f\n", carga[i].Productos[j].PrecioUnitario);
        }
        fflush(stdin);
        printf("Total a pagar: %.2f\n", total);
    }
    for (int i = 0; i < cant; i++)
    {
        for (int j = 0; j < carga[i].CantidadProductosAPedir; j++)
        {
            free(carga[i].Productos[j].TipoProducto);
        }
        free(carga[i].NombreCliente);
        free(carga[i].Productos);
    }
    free(carga);
    free(buff);
    free(random);
    
    return 0;
}

float Costo(Producto Prod)
{
    return (Prod.Cantidad * Prod.PrecioUnitario);
}