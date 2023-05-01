#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50000
#define MIN 10000

int main(){
    int mes[5][12],suma,ma[3],mi[3];
    float promedio;
    srand(time(NULL));
    ma[0] = 0;
    mi[0] = MAX;
    for (int i = 0; i < 5; i++)
    {
        printf("---------Año %d---------\n",i+2023);
        suma = 0;
        for (int j = 0; j < 12; j++)
        {
            mes[i][j] = (rand() % (MAX - MIN + 1)) + MIN;
            if (mes[i][j] > ma[0])
            {
                ma[0] = mes[i][j];
                ma[1] = j+1;
                ma[2] = i+2023;
            }
            if (mes[i][j] < mi[0])
            {
                mi[0] = mes[i][j];
                mi[1] = j+1;
                mi[2] = i+2023;
            }
            suma = suma + mes[i][j];
            printf("El valor del mes %d = %d \n",j+1,mes[i][j]);
        }
        promedio = suma/12;
        printf("--El promedio de ganancias de este año es: %.2f--\n",promedio);
    }
    printf("El valor más grande obtenido fue en %d/%d: %d\n",ma[1],ma[2],ma[0]);
    printf("El valor más pequeño obtenido fue en %d/%d: %d\n",mi[1],mi[2],mi[0]);
    return 0;
}