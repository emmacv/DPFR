#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar_arreglo(int arreglo[], int);
int retorna_maximo(int arreglo[], int);

int main()
{
    int n = 10;
    int arreglo[n];
    srand(time(NULL));
    
    printf("el maximo elemento es: %i", retorna_maximo(arreglo, n));

    return 0;
}

int retorna_maximo(int arreglo[], int n)
{
    int i = 1, mayor = 0;
    generar_arreglo(arreglo, n);
    mayor = arreglo[i];
    
    for(; i < n; i++)
        if(mayor < arreglo[i])
            mayor = arreglo[i];
            
    return mayor;
}

void generar_arreglo(int arreglo[], int n)
{
    int i = 0;

    for(; i < n; i++)
    {
        arreglo[i] = rand() % 100 + 1;
        printf("%i\t", arreglo[i]);
    }
}
