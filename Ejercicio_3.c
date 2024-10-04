#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Para poder usar el comando time()

#define SIZE 5  // Tamano de la matriz que puede ser cambiada

// Función que encuentra la secuencia de 1s consecutivos más larga en una matriz, usamos el script en el pdf como base
int findLargestLine(int matrix[][SIZE]) {
    int contadorMax = 0, contador_act = 0; //Primero creamos dos variables para que ellas guarden los datos obtenidos de la matriz

    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) { //Usando como ejemplo el script dado en clase sobre recorrer una matriz solo que cambiamos filas y columnas por SIZE
            if (matrix[i][j] == 1) { //Aqui tenemos que si la posicion de la matriz en [i] y [j] es 1 se le aumenta en uno el valor de contador_act y repetimos hasta que sea 0
                contador_act++;
            } else { //si no es 1 (o sea cuando es 0) corremos el siguiente if que actualiza el contadorMax con contador_act solo si este es mas grande.
                if (contador_act > contadorMax) {
                    contadorMax = contador_act;
                }
                contador_act = 0;  // Reiniciamos el contador a 0 para poder seguir analizando las demas lineas
            }
        }
    }
    // Verificamos la ultima secuencia ya que sin esto si la ultima fila es la que tiene la secuencia mas larga de 1 esta no quede atrapada en contador_act
    if (contador_act > contadorMax) {
        contadorMax = contador_act;
    }

    return contadorMax;
}

// Función para llenar la matriz de manera aleatoria con valores binarios (0 o 1)
void llenarMatriz(int matrix[][SIZE]) {
    srand(time(NULL));  // Inicializar el generador de números aleatorios, usamos el time(NULL) para que utilice la hora como semilla para el rand()
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 2;  // Generador de los numeros usando el rand(), el % 2 es para que solo de numeros de 0 y 1
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[SIZE][SIZE];

    // Llenamos la matriz aleatoriamente
    llenarMatriz(matrix);

    // Imprimimos la matriz generada
    printf("La matriz generada es:\n");
    imprimirMatriz(matrix);

    // Encontramos la secuencia más larga de 1s
    int largestLine = findLargestLine(matrix);
    printf("El tamaño de la secuencia de 1s más grande es: %d\n", largestLine);

    return 0;
}

