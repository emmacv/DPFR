#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Prototipos de funciones
char sacar_elemento (char *);
void insertar_elemento (char *, char);
int vaciar_pila (char *);
void mostrar_pila (char *);
int menu (void);

int tope = 0, n = 0;			//variable que indica la cantidad de elementos dentro de la pila.

int main (int argc, char *argv[])
{
    char elemento = '\0';

    do
    {
        printf ("\nCuantos datos para la pila: ");
        scanf ("%i", &n);
    }
    while(n <= 0);
    char pila[n];

    while(1)
    {
        switch(menu ())
        {
            case 1:
                printf ("\nIngresa el elemento deseado en la pila: ");
                while(getchar() != '\n');
                insertar_elemento(pila, getchar());
            break;
    
            case 2:
                elemento = sacar_elemento(pila);
                if(elemento == '\0')
                    printf("Pila vacia");
                else
                    printf("Elemento sacado: %c\n", elemento);
            break;
    
            case 3: 
                vaciar_pila(pila);
            break;

            case 4:
                mostrar_pila(pila);
            break;
            default:
                return 0;
        }

        system("pause");
        system("cls");
    }

    return 0;
}



int menu (void)         //Función que muestra el menú del usuario para manipular la pila.
{
    int opc = 0;

    printf("\nQue desea realizar");
    printf("\n1 Ingresar un dato a la pila  \n2 sacar elemento de la pila   \n3 vaciar la pila  \n4 Mostrar pila    \n5 salir   \nOpcion: ");
    scanf("%i", &opc);

    return opc;
}


void insertar_elemento (char pila[], char elemento)     //Función que inserta el elemento dentro de la pila.
{
    if (tope < n)
    {
        pila[tope++] = elemento;
        printf ("\nElemento ingresado: %c\n", pila[tope - 1]);
    }
    else
        printf ("\nPila llena.\n");
}

char sacar_elemento (char pila[])               //Función que retorna el último elemento de la pila.
{  
    return tope == 0 ? '\0' : pila[--tope];
}


int vaciar_pila (char pila[])                   //Función que vacia totalmente la pila.
{
    int i = 0;

    if(tope == 0)
        printf("\nLa pila ya está vacia.\n");
    else
    {
        tope = 0; 
        printf("\nPila vaciada.\n");
    }
}


void mostrar_pila (char pila[])                 //Función que muestra la pila.
{
    int i = 0;

    if(tope == 0)
        printf("\nPila vacia.\n");
    else
    {
        printf("\nElementos de la pila: ");
        for(; i < tope; i++)
            printf("%c ", pila[i]);    
        printf("\n");
    }
}

