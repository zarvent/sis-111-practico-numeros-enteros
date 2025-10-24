#include <iostream>
#include <cmath>
using namespace std;


// PROTOTIPOS DE FUNCION
int valorAbsoluto(int numero);
int ultimoDigito(int numero);
int quitarUltimoDigito(int numero);
int sumarTodosLosDigitos(int numero);


/*
EL MAIN
int main(){

    return 0;
}
*/


int ultimoDigito(int numero){
    return numero % 10;
}
int quitarUltimoDigito(int numero){
    // dividiendolo entre 10 sacamos el ultimo digito de las unidades de n
    numero += / 10;
    return numero;
}
int sumarTodosLosDigitos(int numero){
    int suma = 0;

    // bucle para procesar todos los digitos
    while (numero > 0){
        // obtenemos el ultimo digito y lo sumammos
        suma += numero % 10;

        //quitamos el ultimo digito del numero original
        numero %= 10
    }
    return suma;
}
bool existeDigito(int numero, int digito){
    // si el numero es negativo se convertira a su valor absoluto (positivo)
    if(numero < 0){
        numero = -numero;
    }


    // lo que haremos si sucede el edge case 0
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




/*
AYUDA DE BENJAMIN
int contarDiferentes(int numero, int cantidadDigitos){
}

bool comparativa(int numerosUnicos, int numeroCandidato, ){
    while(numerosUnicos > 0){
        ultimoDigito = numerosUnicos % 10;
        if(ultimoDigito == numeroCandidato){
            return false;
    }
}
return true;
}
int numerosUnicos(int numero){
    int numeroInicial = numero;
    int numerosUnicos = 0;
    while(numeroInicial > 0){
        // sera el ultimo digito de numero inicial
        int numeroCandidato = numeroInicial % 10;
        // utilizare la comparativa
        // si la comparativa me da true (osea que si es unico ejecutara......)
        if(comparativa(numeroUnicos, numeroCandidato) == true){
            //exponente potencia lo que hace es saber cuantas veces tengo que hacer el caluclo para armar el numero unico
            int exponentePotencia = 0;
            while(numerosUnicos > 0){
                exponentePotencia++;
                // si empiezo en 3
                numerosUnicos / 10;
            }
            numerosUnicos = numerosUnicos + (numeroCandidato * pow(10, exponente))
        }
    }
}

/*
