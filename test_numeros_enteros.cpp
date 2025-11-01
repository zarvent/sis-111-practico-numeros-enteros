// Archivo de pruebas para numeros enteros.cpp
#include <iostream>
#include <cassert>

// Prototipos de las funciones a probar
int ultimoDigito(int numero);
int quitarUltimoDigito(int numero);
int sumarTodosLosDigitos(int numero);
bool existeDigito(int numero, int digito);
int cantidadDeDigitos(int numero);
int extraerDigitoPorPosicion(int numero, int posicion);
int digitoMenor(int numero);
int digitoMayor(int numero);
int invertirNumero(int numero);
int unirEntero(int numero);

// Función principal de pruebas
int main() {
    std::cout << "Iniciando pruebas..." << std::endl;

    // Pruebas para ultimoDigito
    assert(ultimoDigito(123) == 3);
    assert(ultimoDigito(-456) == 6);
    assert(ultimoDigito(0) == 0);

    // Pruebas para quitarUltimoDigito
    assert(quitarUltimoDigito(123) == 12);
    assert(quitarUltimoDigito(-456) == 45);
    assert(quitarUltimoDigito(7) == 0);

    // Pruebas para sumarTodosLosDigitos
    assert(sumarTodosLosDigitos(123) == 6);
    assert(sumarTodosLosDigitos(-45) == 9);
    assert(sumarTodosLosDigitos(0) == 0);

    // Pruebas para existeDigito
    assert(existeDigito(123, 2) == true);
    assert(existeDigito(-789, 5) == false);
    assert(existeDigito(0, 0) == true);
    assert(existeDigito(101, 0) == true);

    // Pruebas para cantidadDeDigitos
    assert(cantidadDeDigitos(123) == 3);
    assert(cantidadDeDigitos(-45) == 2);
    assert(cantidadDeDigitos(0) == 1);

    // Pruebas para extraerDigitoPorPosicion
    assert(extraerDigitoPorPosicion(9876, 1) == 6);
    assert(extraerDigitoPorPosicion(9876, 3) == 8);
    assert(extraerDigitoPorPosicion(-25, 2) == 2);
    assert(extraerDigitoPorPosicion(123, 0) == -1);
    assert(extraerDigitoPorPosicion(123, -2) == -1);
    assert(extraerDigitoPorPosicion(123, 5) == -1);

    // Pruebas para digitoMenor
    assert(digitoMenor(395) == 3);
    assert(digitoMenor(-742) == 2);
    assert(digitoMenor(0) == 0);

    // Pruebas para digitoMayor
    assert(digitoMayor(395) == 9);
    assert(digitoMayor(-742) == 7);
    assert(digitoMayor(0) == 0);

    // Pruebas para invertirNumero
    assert(invertirNumero(123) == 321);
    assert(invertirNumero(-450) == 54);
    assert(invertirNumero(7) == 7);
    assert(invertirNumero(0) == 0);

    // Pruebas para unirEntero
    assert(unirEntero(12) == 1212);
    assert(unirEntero(-34) == 3434);
    assert(unirEntero(7) == 77);
    assert(unirEntero(0) == 0);

    std::cout << "Todas las pruebas pasaron exitosamente." << std::endl;

    return 0;
}
