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
 * @brief Obtiene el último dígito de un número entero, sin importar su signo.
 *
 * Usa el operador módulo (numero % 10) para extraer el dígito de las unidades.
 *
 * @details Utiliza abs(numero) para trabajar con valores absolutos.
 *
 * @code
 * ultimoDigito(123)  // Retorna 3
 * ultimoDigito(-456) // Retorna 6
 * ultimoDigito(0)    // Retorna 0
 * @endcode
 *
 * @param numero Número entero del cual extraer el último dígito (puede ser positivo, negativo o cero).
 * @return Entero positivo en el rango [0, 9] que representa el último dígito.
 */
int ultimoDigito(int numero){
    return abs(numero % 10);
}

/**
 * @brief Elimina el último dígito de un número entero, sin importar su signo.
 *
 * Utiliza división entera por 10 (numero / 10) para descartar el dígito de las unidades.
 *
 * @details Aplica abs(numero) para trabajar con el valor absoluto del número.
 *
 * @code
 * quitarUltimoDigito(123)  // Retorna 12
 * quitarUltimoDigito(-456) // Retorna 45
 * quitarUltimoDigito(7)    // Retorna 0
 * @endcode
 *
 * @param numero Número entero al que se le quitará el último dígito (puede ser positivo, negativo o cero).
 * @return Entero positivo que representa el número original sin su último dígito.
 */
int quitarUltimoDigito(int numero){
    numero = abs(numero);
    numero /= 10;
    return numero;
}


/**
 * @brief Suma todos los dígitos de un número entero, sin importar su signo.
 *
 * Usa suma acumulativa (suma += numero % 10) extrayendo cada dígito y sumándolo al total.
 *
 * @details Utiliza abs(numero) y un bucle while para recorrer cada dígito de derecha a izquierda.
 *
 * @code
 * sumarTodosLosDigitos(123)  // Retorna 6 (1+2+3)
 * sumarTodosLosDigitos(-45)  // Retorna 9 (4+5)
 * sumarTodosLosDigitos(0)    // Retorna 0
 * @endcode
 *
 * @param numero Número entero del cual se sumarán todos sus dígitos (puede ser positivo, negativo o cero).
 * @return Entero positivo que representa la suma de todos los dígitos.
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
 * @brief Verifica si un dígito específico existe dentro de un número entero.
 *
 * Recorre el número dígito por dígito (numero % 10 == digito) de derecha a izquierda.
 *
 * @details Utiliza abs(numero) para manejar números negativos. Incluye validación especial para el caso numero == 0.
 *
 * @code
 * existeDigito(123, 2)  // Retorna true
 * existeDigito(-789, 5) // Retorna false
 * existeDigito(0, 0)    // Retorna true
 * @endcode
 *
 * @param numero Número entero donde se buscará el dígito (puede ser positivo, negativo o cero).
 * @param digito Dígito a buscar, debe estar en el rango [0, 9].
 * @return true si el dígito existe en el número, false en caso contrario.
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
 * @brief Calcula la cantidad de dígitos de un número entero, sin importar su signo.
 *
 * Cuenta iterativamente dividiendo por 10 (numero /= 10) hasta que el número sea cero.
 *
 * @details Utiliza abs(numero) y trata el caso especial del 0, que cuenta como un dígito.
 *
 * @code
 * cantidadDeDigitos(123)  // Retorna 3
 * cantidadDeDigitos(-45)  // Retorna 2
 * cantidadDeDigitos(0)    // Retorna 1
 * @endcode
 *
 * @param numero Número entero del cual contar los dígitos (puede ser positivo, negativo o cero).
 * @return Entero positivo que indica la cantidad de dígitos.
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
 * @brief Extrae el dígito en una posición específica de un número entero.
 *
 * Recorre iterativamente (numero /= 10) hasta alcanzar la posición deseada contando desde la derecha.
 * La posición 1 corresponde al último dígito (unidades).
 *
 * @details Utiliza abs(numero) y valida que la posición sea mayor a 0 y no exceda la cantidad de dígitos.
 *
 * @code
 * extraerDigitoPorPosicion(9876, 1) // Retorna 6 (primer dígito desde derecha)
 * extraerDigitoPorPosicion(9876, 3) // Retorna 8 (tercer dígito desde derecha)
 * extraerDigitoPorPosicion(-25, 2)  // Retorna 2 (segundo dígito de 25)
 * extraerDigitoPorPosicion(123, 0)  // Retorna -1 (posición inválida: cero)
 * extraerDigitoPorPosicion(123, -2) // Retorna -1 (posición inválida: negativa)
 * extraerDigitoPorPosicion(123, 5)  // Retorna -1 (posición inválida: excede dígitos)
 * @endcode
 *
 * @param numero Número entero del cual extraer un dígito (puede ser positivo, negativo o cero).
 * @param posicion Posición del dígito a extraer (base 1, desde la derecha).
 * @return Dígito positivo en la posición solicitada, o -1 si la posición es inválida.
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
 * @brief Encuentra el dígito más pequeño dentro de un número entero, sin importar su signo.
 *
 * Compara cada dígito (numeroAuxiliar < digitoMenor) con el mínimo actual, inicializado en 9.
 *
 * @details Utiliza abs(numero) e incluye validación especial para el caso numero == 0.
 *
 * @code
 * digitoMenor(395)  // Retorna 3
 * digitoMenor(-742) // Retorna 2
 * digitoMenor(0)    // Retorna 0
 * @endcode
 *
 * @param numero Número entero donde buscar el dígito menor (puede ser positivo, negativo o cero).
 * @return Entero positivo en el rango [0, 9] que representa el dígito más pequeño.
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
 * @brief Encuentra el dígito más grande dentro de un número entero, sin importar su signo.
 *
 * Usa un bucle do-while (digito > digitoMayor) para comparar cada dígito con el máximo actual, inicializado en -1.
 *
 * @details Utiliza abs(numero) y garantiza al menos una iteración para manejar correctamente el caso numero == 0.
 *
 * @code
 * digitoMayor(395)  // Retorna 9
 * digitoMayor(-742) // Retorna 7
 * digitoMayor(0)    // Retorna 0
 * @endcode
 *
 * @param numero Número entero donde buscar el dígito mayor (puede ser positivo, negativo o cero).
 * @return Entero positivo en el rango [0, 9] que representa el dígito más grande.
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
 * @brief Invierte el orden de los dígitos de un número entero, sin importar su signo.
 *
 * Construye el número invertido progresivamente (nuevoNumero * 10 + digito), extrayendo cada dígito
 * del original y agregándolo al nuevo número.
 *
 * @details Utiliza abs(numero) y un bucle while para procesar cada dígito de derecha a izquierda.
 * Los ceros a la izquierda del número original se pierden (ej: -450 → 54).
 *
 * @code
 * invertirNumero(123)  // Retorna 321
 * invertirNumero(-450) // Retorna 54
 * invertirNumero(7)    // Retorna 7
 * @endcode
 *
 * @param numero Número entero a invertir (puede ser positivo, negativo o cero).
 * @return Entero positivo con los dígitos en orden inverso.
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
 * @brief Concatena un número entero consigo mismo para formar un nuevo número.
 *
 * Desplaza el número original usando potencias de 10 (pow(10, digitos)) para hacer espacio,
 * luego suma el número original nuevamente.
 *
 * @details Reutiliza cantidadDeDigitos(numero) para calcular el desplazamiento necesario.
 * Funciona con números positivos y negativos gracias a abs() en las funciones auxiliares.
 *
 * @code
 * unirEntero(12)   // Retorna 1212
 * unirEntero(-34)  // Retorna 3434
 * unirEntero(7)    // Retorna 77
 * @endcode
 *
 * @param numero Número entero a concatenar consigo mismo (puede ser positivo, negativo o cero).
 * @return Entero positivo que representa el número original repetido dos veces.
 */
int unirEntero(int numero){
    numero = abs(numero);
    int digitos = cantidadDeDigitos(numero);
    int desplazamiento = pow(10, digitos);
    int nuevoNumero = (numero * desplazamiento) + numero;

    return nuevoNumero;
}
