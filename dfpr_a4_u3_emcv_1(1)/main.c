#include <stdio.h>
#include <stdlib.h>

//Prototipos de funciones
char sacar_elemento (char *);
int longitud_cadena(char *);
void verificar_parentesis(char *);


int tope = 0;			//variable que indica la cantidad de elementos dentro de la pila.


int main (int argc, char *argv[])
{
    char cadena[100];
    
    printf("Ingresa una cadena: ");
    fgets(cadena, 100, stdin);
    verificar_parentesis(cadena);

    return 0;
}


void verificar_parentesis (char cadena[])
{
    int i = 0, par_izq = 0, par_der = 0;
    char elemento = '\0';
    
    int n = longitud_cadena(cadena);
    for(; i < n; i++)
    {
        elemento = sacar_elemento(cadena);

        if(elemento == '(')
            par_izq++;
        else if(elemento == ')') 
            par_der++;
    }
    
    printf("%s", par_der == par_izq ? "La cadena tiene parentesis balanceados." : "La cadena no tiene parentesis balanceados.");
}


int longitud_cadena (char cadena[])
{
    //while(cadena[tope] != '\n' && cadena[tope] != '\0')
    //    tope++;
    for(; cadena[tope] != '\n' && cadena[tope] != '\0'; tope++);
    
    return tope;
}


char sacar_elemento (char pila[])               //Función que retorna el último elemento de la pila.
{  
    return pila[--tope];
}
