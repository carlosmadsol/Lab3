#include <stdio.h>

int factorial (int n) {
    int i = 1;
    while (n > 1) {
        i = i * n;
        n = n - 1; //El error estaba en que se estaba definiendo una una n con int n, lo que hacia que el n del while nunca cambiara
    }
    return i ;
}
int main (int argc , char * argv [ ]) {
    int num; //Agregamos y definimos la variable num como un integrer
    printf("Ingrese un número: "); //Agregamos este printf para que a la hora de ingresar el numero se sienta mas interactivo
    scanf("%d", &num); //Agregamos el scanf que lo que hace es pedirle al usuario de la terminal que agregue un numero que sera asignado a num
    int resultado_factorial = factorial (num); //Creamos esta variable resultado_factorial para guardar lo obtenido de la funcion factorial
    printf("%d! = %d\n", num, resultado_factorial); 
    return 0;
}