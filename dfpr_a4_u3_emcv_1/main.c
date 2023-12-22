#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Prototipos de funciones
char sacar_elemento (char *);
void insertar_elemento (char *, char);
int vaciar_pila (char *);
int menu (void);

int tope = 0, n = 0;			//variable que indica la cantidad de elementos dentro de la pila.

int main (int argc, char *argv[])
{
    do
    {
        printf ("\nCuantos datos para la pila: ");
        scanf ("%i", &n);
    }
    while(n <= 0);
    char array[n];

    while(1)
    {
        switch(menu())
        {
            case 1:
                printf ("\nIngresa el elemento deseado en la pila: ");
                while(getchar() != '\n');
                insertar_elemento(array, getchar());
            break;
    
            case 2:
                if(sacar_elemento(array) == '\n')
                    printf("Pila vacía");
                else
                    printf("elemento sacada: %c", sacar_elemento(array));
            break;
    
            case 3: 
                vaciar_pila(array);
            break;
            default:
                return 0;
        }
        
    }

    return 0;
}

int menu (void)
{
    int opc = 0;

    printf("\nQue desea realizar");
    printf("\n1 Ingresar un dato a la pila  \n2 sacar elemento de la pila   \n3 vaciar la pila  \n4 salir   \nOpcion: ");
    scanf("%i", &opc);

    return opc;
}

void insertar_elemento (char array[], char elemento)
{
    if (tope < n)
    {
        array[tope++] = elemento;
        printf ("\nElemento ingresado: %c", array[tope - 1]);
    }
    else
        printf ("\nPila llena.");
}

char sacar_elemento (char array[])
{  
    return tope == 0 ? '\0' : array[tope--];
}

int vaciar_pila (char array[])
{
    return tope == 0 ? -1 : 
}

void mostrar_pila(char pila)
