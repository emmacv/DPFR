#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 32
#define N_INFECTADOS 10

typedef struct estado{
    char nombre[20];
    int infectados_por_dia[10];
    float promedio_infectados, varianza;
}estados[N];
char nombre_estados[][20] = {"Aguascalientes", "Baja California", "Baja California Sur", "Campeche", "Coahuila", "Colima", "Chiapas", "Chihuahua", "CDMX", "Durango", "Guanajuato", "Guerrero", "Hidalgo", "Jalisco", "México", "Michoacan", "Morelos", "Nayarit", "Nuevo León", "Oaxaca", "Puebla", "Querétaro", "Quintana Roo", "San Luis Potosí", "Sinaloa", "Sonora", "Tabasco", "Tamaulipas", "Tlaxcala", "Veracruz", "Yucatan", "Zacatecas"};
int casos[][10] = { {96, 52, 72, 73, 18, 21, 69, 62, 59, 59}, {131, 130, 125, 76, 57, 132, 118, 113, 110}, {111, 115, 142, 105, 67, 39, 172, 152, 120, 153}, {98, 84, 79, 79, 34, 24, 68, 85, 67, 61}, {325, 305, 321, 343, 176, 105, 420, 388, 324, 335}, {64, 77, 71, 61, 41, 38, 49, 68, 52, 63}, {21, 22, 18, 33, 13, 14, 21, 26, 20, 18}, {90, 108, 100, 84, 44, 34, 75, 77, 84, 83}, {1088, 1146, 1060, 1000, 502, 249, 994, 964, 993, 947}, {115, 84, 88, 72, 21, 37, 120, 94, 97, 74}, {652, 540, 534, 502, 210, 180, 604, 614, 486, 546}, {147, 153, 219, 192, 96, 88, 209, 181, 142, 198}, 
{144, 127, 131, 127, 72, 70, 134, 132, 122, 131}, {298, 171, 222, 207, 121, 120, 310, 239, 248, 213}, {759, 690, 473, 585, 218, 193, 652, 562, 630, 514}, {170, 163, 188, 180, 79, 59, 204, 232, 203, 174}, {41, 35, 39, 36, 19, 20, 48, 48, 42, 48}, {73, 85, 65, 81, 33, 31, 77, 61, 50, 55}, {579, 525, 603, 543, 271, 132, 212, 361, 295, 350}, {170, 163, 145, 157, 113, 53, 166, 138, 152, 130}, {254, 375, 345, 337, 223, 104, 429, 323, 331, 333}, {74, 73, 64, 54, 48, 37, 80, 80, 85, 76}, {98, 84, 79, 79, 34, 24, 66, 79, 67, 60}, {404, 381, 397, 397, 246, 142, 390, 396, 367, 295}, 
{298, 171, 222, 207, 121, 120, 310, 239, 248, 213}, {96, 52, 72, 73, 18, 21, 69, 62, 59, 59}, {170, 163, 188, 180, 79, 59, 204, 232, 203, 174}, {1088, 1146, 1060, 1000, 502, 249, 994, 964, 993, 947}, {170, 163, 188, 180, 79, 59, 204, 232, 203, 174} , {652, 540, 534, 502, 210, 180, 604, 614, 486, 546}, {579, 525, 603, 543, 271, 132, 212, 361, 295, 350}, {170, 163, 145, 157, 113, 53, 166, 138, 152, 130} }; 


void llenar_lista(estados);
int mostrar_estados(estados);
void estadistica_estado(estados, int);
float varianza(estados, int);

int main()
{
    estados est_estados;
    
    llenar_lista(est_estados);
    printf("Lista de estados: \n");
    
    estadistica_estado(est_estados, mostrar_estados(est_estados) - 1);
    
    
    return 0;
}

void llenar_lista(estados lista_estados)
{
    int i = 0, j;
    
    
    for(; i < N; i++)
    {
        strcpy(lista_estados[i].nombre, nombre_estados[i]);
        for(j = 0; j < 10; j++)
            lista_estados[i].infectados_por_dia[j] = casos[i][j]; 
    }
}

int mostrar_estados(estados lista_estados)
{
    int i = 0, op = 0;
    
    for(; i < N; i++)
        printf("%i. %s\n", i + 1, lista_estados[i].nombre);
    
    printf("Opcion: ");
    scanf("%i", &op);
    
    return op;
}

void estadistica_estado(estados lista_estados, int estado)
{
    int i = 0, acum = 0;
    
    if(estado < 0 || estado > 31)
        printf("Opcion invalida.");
    else
    {
        printf("\t\t\t  Estado: %s\n", lista_estados[estado].nombre);
            
        printf("\t\tNumero de infectados del 21 al 30 de julio:\n\t\t");
        for(i = 0; i < N_INFECTADOS; i++)
        {
            printf("%i ", lista_estados[estado].infectados_por_dia[i]);
            acum += lista_estados[estado].infectados_por_dia[i];
        }
        lista_estados[estado].promedio_infectados = (float)acum / N_INFECTADOS;
        printf("\n\t\t\tPromedio de infectados: %.2f\n", lista_estados[estado].promedio_infectados);
        printf("\t\t\tVarianza estandar: %.2f",  varianza(lista_estados, estado));
    }
}

float varianza(estados lista_estados, int estado)
{
    float acum = 0.0;
    int i = 0;
    
    for(; i < N_INFECTADOS; i++)
        acum += pow(lista_estados[estado].promedio_infectados - lista_estados[estado].infectados_por_dia[i], 2);
        
    return acum / N_INFECTADOS;
}

