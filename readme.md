# 🔢 Práctico: Numeros Enteros

Un práctico en c++ de la asignatura SIS-111 [Introduccion A La Programacion]

![Campus UCB](archives/ucbCampus.jpg)

> 📄 **[Ver enunciado del práctico](practico%20numeros%20enteros.pdf)**

---

## ¿De qué va esto?

Básicamente tenemos un conjunto de funciones que te permiten **jugar con los dígitos** de cualquier número. Extraer dígitos, sumarlos, buscar si existe uno en particular... ese tipo de cosas que parecen simples pero son la base para algoritmos mucho más complejos.

---

## 📋 Funciones disponibles

| Función | ¿Qué hace? |
|---------|-----------|
| **ultimoDigito(n)** | Devuelve el último dígito del número |
| **quitarUltimoDigito(n)** | Elimina el último dígito |
| **sumarTodosLosDigitos(n)** | Suma todos los dígitos (ej: 123 → 6) |
| **existeDigito(n, d)** | Te dice si un dígito existe en el número |
| **cantidadDeDigitos(n)** | Cuántos dígitos tiene el número |
| **extraerDigitoPorPosicion(n, p)** | Extrae el dígito en una posición específica |
| **digitoMenor(n)** | Encuentra el dígito más pequeño |

---

## 🔍 Notas

- Las funciones manejan **números negativos** sin drama (usan `abs()`)
- El caso especial del **0** ya está contemplado en cada función
- Todo está en C++ clásico, sin complicaciones

---

**Cesar Sebastian Zambrana Ventura** | 2025
