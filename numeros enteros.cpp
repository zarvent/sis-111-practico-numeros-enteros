//DIRECTIVAS DEL PREPROCESADOR
#include <iostream>
#include <cmath>


using std::cout;
using std::endl;
using std::abs;


// PROTOTIPOS DE FUNCION
int ultimoDigito(int numero);
int quitarUltimoDigito(int numero);
int sumarTodosLosDigitos(int numero);
bool existeDigito(int numero, int digito);
int cantidadDeDigitos(int numero);


/*
EL MAIN
int main(){

    return 0;
}
*/


// DEFINICIONES DE FUNCION
int ultimoDigito(int numero){
    return abs(numero % 10);
}
int quitarUltimoDigito(int numero){
    // dividiendolo entre 10 sacamos el ultimo digito de las unidades de n
    numero /= 10;
    return numero;
}
int sumarTodosLosDigitos(int numero){
    int suma = 0;

    // para evitar recibir negativos
    numero = abs(numero);

    // bucle para procesar todos los digitos
    while (numero > 0){
        // obtenemos el ultimo digito y lo sumammos
        suma += numero % 10;
        //quitamos el ultimo digito del numero original
        numero /= 10;
    }
    return suma;
}
bool existeDigito(int numero, int digito){
    numero = abs(numero);  // ejemplo: -5 ahora sera 5

    // edge case 0
    if(numero == 0){
        return (digito == 0); // osea la variable digito tendra el valor de 0 y buscara los 0 en "el buscador"
    }


    while(numero > 0){
        //miramos si el ultimo digito del numero existen en el numero
        if(numero % 10 == digito){
            // detenemos "el buscador" si lo encontramos y decimos a la maquina que si existe
            return true;
        }

        // esto es lo que hara la maquina si no encuentra el numero
        numero /= 10; // osea buscara si el proximo digito existe en el algoritmo
    }
    return false;
}
int cantidadDeDigitos(int numero){
    numero = abs(numero);

    // caso especial para 0
    if(numero == 0){
        return 1;
    }

    int cantidadDigitos = 0;

    while(numero > 0){
        // si accedimos aca significa que tenemos digitos por contar
        numero /= 10;
        cantidadDigitos++;

    }
       return cantidadDigitos;
}
