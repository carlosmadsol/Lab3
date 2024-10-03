#include <stdio.h>
// Creamos una funcion para la suma de diagonales, con void ya que no ocupamosm que retorne un valor especifico, solo que imprima el resultado
void suma_diagonales(int matriz[][100], int n) {
    int suma_principal = 0, suma_secundaria = 0; //Tanto suma_principal y suma_secundaria deben de empezar siendo 0
    /*Usamos el codigo dado por la profe para recorrer una matriz pero lo adaptamos a nuestras necesidades*/
    for (int i = 0; i < n; i++) {
        suma_principal += matriz[i][i];           //Diagonal principal
        suma_secundaria += matriz[i][n - 1 - i];  //Diagonal secundaria donde usamos [n - 1 - i] por que ocupamos el inverso de la diagonal principal, la n es el tamaño de la matriz cuadrada
        // Usamos el comando de += para se le sume los valores infinitos obtenidos en matriz [i][i] y en matriz [1][n - 1 - i] a 0 que es el valor de suma_principal y suma_secundaria
    }
// Aqui imprimos los resultados optenidos por suma_principal y suma_secundaria
    printf("Suma diagonal principal: %d\n", suma_principal);
    printf("Suma diagonal secundaria: %d\n", suma_secundaria);
}

int main() {
    // Ejemplo 1: Matriz 3x3
    int matriz1[100][100] = {{1, 2, 3}, 
                             {4, 5, 6}, 
                             {7, 8, 9}};
    
    printf("Matriz 3x3:\n");
    suma_diagonales(matriz1, 3);
    return 0;
}
