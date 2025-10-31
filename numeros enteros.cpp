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
int invertirNumero(int numero);


/*
EL MAIN
int main(){

    return 0;
}
*/


// DEFINICIONES DE FUNCION

/**
 * @brief obtiene el digito de la ultima unidad del numero entero introducido, ignorando el signo
 * Modulo 10 (numero % 10): devuelve el resto de dividir el numero por 10, es decir el ultimo digito de las unidades
 * @details esta funcion utiliza el valor absoluto con abs(numero)
 * @code
 * ultimoDigito(123)  // Retorna 3
 * ultimoDigito(-456) // Retorna 6
 * ultimoDigito(0)    // Retorna 0
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) del cual se extraera el ultimo digito
 * @return un entero POSITIVO en el rango de [0, 9]
 */
int ultimoDigito(int numero){
    return abs(numero % 10);
}

/**
 * @brief remueve el ultimo digito del numero entero introducido, ignorando el signo
 * Division entera por 10 (numero / 10): elimina el digito de las unidades dejando solo las decenas en adelante
 * @details esta funcion utiliza el valor absoluto con abs(numero) para trabajar con numeros positivos y negativos
 * @code
 * quitarUltimoDigito(123)  // Retorna 12
 * quitarUltimoDigito(-456) // Retorna 45
 * quitarUltimoDigito(7)    // Retorna 0
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) al cual se le quitara el ultimo digito
 * @return un entero POSITIVO que representa el numero original sin su ultimo digito
 */
int quitarUltimoDigito(int numero){
    numero = abs(numero);
    numero /= 10;
    return numero;
}


/**
 * @brief suma todos los digitos del numero entero introducido, ignorando el signo
 * Suma acumulativa (suma += numero % 10): extraemos el ultimo digito y lo agregamos al total
 * @details esta funcion utiliza el valor absoluto con abs(numero) y un bucle while para recorrer cada digito hasta que no queden mas unidades
 * @code
 * sumarTodosLosDigitos(123)  // Retorna 6
 * sumarTodosLosDigitos(-45)  // Retorna 9
 * sumarTodosLosDigitos(0)    // Retorna 0
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) del cual se sumaran todos los digitos
 * @return un entero POSITIVO que representa la suma de los digitos del numero original
 */
int sumarTodosLosDigitos(int numero){
    int suma = 0;
    numero = abs(numero);

    while (numero > 0){
        suma += numero % 10;
        numero /= 10;
    }
    return suma;
}
/**
 * @brief verifica si el digito dado aparece dentro del numero entero introducido
 * Exploracion iterativa (numero % 10 == digito): revisa digito por digito de derecha a izquierda
 * @details esta funcion utiliza el valor absoluto con abs(numero) para permitir negativos y controla el caso especial cuando numero es 0
 * @code
 * existeDigito(123, 2)  // Retorna true
 * existeDigito(-789, 5) // Retorna false
 * existeDigito(0, 0)    // Retorna true
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) donde buscaremos el digito
 * @param digito El digito individual [0, 9] que deseamos encontrar
 * @return true si el digito existe en el numero, false en caso contrario
 */
bool existeDigito(int numero, int digito){
    numero = abs(numero);

    // edge case 0
    if(numero == 0){
        return (digito == 0);
    }

    while(numero > 0){
        if(numero % 10 == digito){
            return true;
        }
        numero /= 10;
    }
    return false;
}
/**
 * @brief calcula la cantidad de digitos que tiene el numero entero introducido, ignorando el signo
 * Conteo iterativo (numero /= 10): descartamos la ultima unidad hasta quedarnos sin numero
 * @details esta funcion utiliza el valor absoluto con abs(numero) y considera el caso especial del 0 que tiene un digito
 * @code
 * cantidadDeDigitos(123)  // Retorna 3
 * cantidadDeDigitos(-45)  // Retorna 2
 * cantidadDeDigitos(0)    // Retorna 1
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) del cual contaremos los digitos
 * @return un entero POSITIVO que indica la cantidad de digitos del numero original
 */
int cantidadDeDigitos(int numero){
    numero = abs(numero);

    // caso especial para 0
    if(numero == 0){
        return 1;
    }

    int cantidadDigitos = 0;

    while(numero > 0){
        numero /= 10;
        cantidadDigitos++;
    }
    return cantidadDigitos;
}
/**
 * @brief extrae el digito segun la posicion deseada dentro del numero entero introducido
 * Recorrido iterativo (numero /= 10): movemos la posicion hasta alcanzar el digito objetivo desde la derecha (posicion 1 = ultimo digito)
 * @details esta funcion utiliza el valor absoluto con abs(numero) y valida que la posicion sea valida (mayor a 0 y dentro del rango del numero)
 * @code
 * extraerDigitoPorPosicion(9876, 1) // Retorna 6 (primer digito desde derecha)
 * extraerDigitoPorPosicion(9876, 3) // Retorna 8 (tercer digito desde derecha)
 * extraerDigitoPorPosicion(-25, 2)  // Retorna 2 (segundo digito de 25)
 * extraerDigitoPorPosicion(123, 0)  // Retorna -1 (posicion invalida: cero)
 * extraerDigitoPorPosicion(123, -2) // Retorna -1 (posicion invalida: negativa)
 * extraerDigitoPorPosicion(123, 5)  // Retorna -1 (posicion invalida: supera cantidad de digitos)
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) del cual extraeremos un digito
 * @param posicion La posicion (base 1, desde la derecha) que indica cual digito deseamos recuperar
 * @return el digito POSITIVO que corresponde a la posicion solicitada o -1 si la posicion no es valida
 */
int extraerDigitoPorPosicion(int numero, int posicion){
    numero = abs(numero);

    // validacion: posicion debe estar entre 1 y la cantidad total de digitos
    // posicion <= 0 rechaza valores como 0, -1, -2 (invalidos)
    // posicion > cantidadDeDigitos rechaza valores que superen el tamaño del numero
    if(posicion <= 0 || posicion > cantidadDeDigitos(numero)){
        return -1;
    }

    while(posicion > 1){
        numero /= 10;
        posicion--;
    }
    return (numero % 10);
}
/**
 * @brief encuentra el digito mas pequeno dentro del numero entero introducido, ignorando el signo
 * Busqueda lineal (numeroAuxiliar < digitoMenor): comparamos cada digito con el minimo actual inicializado en 9
 * @details esta funcion utiliza el valor absoluto con abs(numero) y controla el edge case cuando numero es 0
 * @code
 * digitoMenor(395)  // Retorna 3
 * digitoMenor(-742) // Retorna 2
 * digitoMenor(0)    // Retorna 0
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) en el que buscaremos el digito mas pequeno
 * @return un entero POSITIVO en el rango de [0, 9] que representa el digito mas chico encontrado
 */
int digitoMenor(int numero){
    numero = abs(numero);
    int digitoMenor = 9; // maximo valor posible

    // edge case con el 0
    if(numero == 0){
        digitoMenor = 0;
    }

    while(numero > 0){
        int numeroAuxiliar = numero % 10;

        if(numeroAuxiliar < digitoMenor){
            digitoMenor = numeroAuxiliar;
        }
        numero /= 10;
    }
    return digitoMenor;
}
/**
 * @brief encuentra el digito mas grande dentro del numero entero introducido, ignorando el signo
 * Busqueda con do-while (digito > digitoMayor): saca el ultimo digito, lo compara y continua hasta quedarse sin unidades
 * @details esta funcion utiliza el valor absoluto con abs(numero) para trabajar con negativos y garantiza al menos una iteracion para cubrir el caso 0
 * @code
 * digitoMayor(395)  // Retorna 9
 * digitoMayor(-742) // Retorna 7
 * digitoMayor(0)    // Retorna 0
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) en el que buscaremos el digito mas grande
 * @return un entero POSITIVO en el rango de [0, 9] que representa el digito mas grande encontrado
 */
int digitoMayor(int numero){
    numero = abs(numero);
    int digitoMayor = -1; // ningun numero absoluto puede ser menor a esto

    // este bloque si o si se ejecutara 1 vez y previene edge cases como por ejemplo el 0
    do{
        int digito = numero % 10;
        if(digito > digitoMayor){
            digitoMayor = digito;
        }
        numero /= 10;
    }
    while(numero > 0);
    return digitoMayor;
}
/**
 * @brief invierte el orden de los digitos del numero entero introducido, ignorando el signo
 * Construccion progresiva (nuevoNumero * 10 + digito): vamos moviendo los digitos al nuevo numero multiplicando por 10 y sumando el ultimo digito
 * @details esta funcion utiliza el valor absoluto con abs(numero) y un while para procesar cada digito de derecha a izquierda
 * @code
 * invertirNumero(123)  // Retorna 321
 * invertirNumero(-450) // Retorna 54
 * invertirNumero(7)    // Retorna 7
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) que queremos invertir
 * @return un entero POSITIVO con los digitos del numero original en orden inverso
 */
int invertirNumero(int numero){
    int nuevoNumero = 0, digito = 0;
    numero = abs(numero);

    while(numero > 0){
        digito = numero % 10;
        numero = numero / 10;
        nuevoNumero = nuevoNumero * 10 + digito;
    }
    return nuevoNumero;
}

/**
 * @brief concatena el numero entero introducido consigo mismo para formar un nuevo entero mas largo
 * Desplazamiento por potencia de 10 (pow(10, digitos)): multiplicamos por potencias de 10 segun la cantidad de digitos para dejar espacio antes de sumar la copia
 * @details esta funcion reutiliza cantidadDeDigitos(numero) para conocer cuantas posiciones mover y funciona igual con numeros positivos o negativos gracias a abs dentro de las funciones auxiliares
 * @code
 * unirEntero(12)   // Retorna 1212
 * unirEntero(-34)  // Retorna 3434
 * unirEntero(7)    // Retorna 77
 * @endcode
 *
 * @param numero El numero entero (positivo,negativo o cero) que se concatenara consigo mismo
 * @return un entero POSITIVO que representa el numero original repetido dos veces
 */
int unirEntero(int numero){
    numero = abs(numero);
    int digitos = cantidadDeDigitos(numero);
    int desplazamiento = pow(10, digitos);
    int nuevoNumero = (numero * desplazamiento) + numero;

    return nuevoNumero;
}
