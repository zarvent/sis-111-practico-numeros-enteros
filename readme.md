# Resumen de Mejoras en la Cobertura de Pruebas

Este documento resume las mejoras realizadas para aumentar la cobertura de pruebas del repositorio.

## Archivos Modificados

-   **`test_numeros_enteros.cpp`**: Se ha creado este nuevo archivo para contener todas las pruebas unitarias de las funciones definidas en `numeros enteros.cpp`.

## Nuevos Comportamientos y Casos Cubiertos

Se han implementado pruebas exhaustivas para todas las funciones, cubriendo los siguientes escenarios:

-   **Números Positivos**: Se verifica el comportamiento estándar de cada función con entradas positivas.
-   **Números Negativos**: Se asegura que todas las funciones manejen correctamente los números negativos, principalmente a través del uso de `abs()`.
-   **Cero**: Se han añadido casos de prueba específicos para el número `0`, que a menudo es un caso especial.
-   **Casos Extremos**:
    -   Números de un solo dígito.
    -   Posiciones inválidas (cero, negativas o fuera de rango) para la función `extraerDigitoPorPosicion`.
    -   Números que contienen ceros en posiciones intermedias (ej: `101`).

## Cómo Compilar y Ejecutar las Pruebas

Para verificar la correcta implementación y asegurarse de que no se han introducido regresiones, siga estos pasos:

1.  **Compilar los archivos**: Utilice un compilador de C++ (como g++) para compilar el código fuente junto con el archivo de pruebas.

    ```bash
    g++ "numeros enteros.cpp" "test_numeros_enteros.cpp" -o test_runner
    ```

2.  **Ejecutar las pruebas**: Ejecute el archivo compilado desde la terminal.

    ```bash
    ./test_runner
    ```

Si todas las pruebas se ejecutan correctamente, verá el siguiente mensaje en la consola:

```
Iniciando pruebas...
Todas las pruebas pasaron exitosamente.
```
