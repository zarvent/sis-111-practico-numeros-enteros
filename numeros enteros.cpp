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
int extraerDigitoPorPosicion(int numero, int posicion);
int digitoMenor(int numero);
int digitoMayor(int numero);


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
    numero = abs(numero);
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
int extraerDigitoPorPosicion(int numero, int posicion){
    numero = abs(numero);

    // si el usuario pone 0?
    if(posicion == 0){
        cout << "Introduce una posicion correcta";
        return -1;
    }

    // y si el usuario da una posicion mas grande que el numero que tenemos?
    if(posicion > cantidadDeDigitos(numero){
        cout << "Introduce una posicion correcta";
        return -1;
    }


    // posicion (dada en consola) recorrera todos los digitos del numero hasta extraer el digito que queremos
    while(posicion > 1){
        numero /= 10;
        posicion--;
    }
    return (numero % 10); // rebotamos el digito que el usuario pidio
}
int digitoMenor(int numero){
    numero = abs(numero);
    int digitoMenor = 9; // maximo valor posible

    // edge case con el 0
    if(numero == 0){
        digitoMenor = 0;
    }

    //recorremos todos los numeros
    while(numero > 0){
        int numeroAuxiliar = numero % 10;

        if(numeroAuxiliar < digitoMenor){
            digitoMenor = numeroAuxiliar;
        }
    numero /= 10;
    }
    return digitoMenor;
}
int digitoMayor(int numero){
    numero = abs(numero);
    int digitoMayor = -1; // ningun numero absoluto puede ser menor a esto

    //este bloque si o si se ejecutara 1 vez y previene edge cases como por ejemplo el 0
    do{
        int digito = numero % 10; // saca el ultimo digito
        if(digito > digitoMayor){ //
            digitoMayor = digito;
        }
        numero /= 10;
    }
    while(numero > 0);
    return digitoMayor;
}
