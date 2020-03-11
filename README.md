# Tarea *1*. *Complejidad Computacional.*

---

##### Integrantes:
1. *Francisco Acuña Franco* - *A01027294* - *CSF*
2. *Isaac Garza Strimlingas* - *A01025798* - *CSF*
3. *Sebastián Gómez Gutiérrez* - *A01374843* - *CSF*
4. *Sergio Hernández Castillo* - *A01025210* - *CSF*
5. *Rodrigo Sibaja Villarreal* - *A01023121* - *CSF*

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

*Para empezar, se manda a llamar la función "leerGuardar()", donde abre el archivo dado como input y comienza a contar la cantidad de líneas qué hay en el código proporcionado. Tomando en cuenta la suma final, se crea un arreglo básico del tamaño de la cantidad de líneas. Cada línea es guardada en cada espacio/índice del arreglo. Luego, se manda a llamar la función "declaracion()" donde se analiza cada línea palabra por palabra para contar las operaciones elementales, y estas se guardan en un segundo arreglo llamado OE[]. Después se manda a llamar una función llamada "calculo()" donde se va a calcular el polinomio final que representa la complejidad temporal del algoritmo dado. Finalmente, los dos métodos que se llaman desde el "main()" son "editar()" y "tabla()". El primero se encarga de borrar todos los espacios blancos que se presentan antes de alguna declaración por cada linea del algoritmo. La segunda tiene la tarea de presentar toda la información/resultados en una tabla ordenada, y estos incluyen el número de linea, el código que se presenta en cada linea, el número total de operaciones elementales, el polinomio formado por cada linea, y el polinomio final que representa la complejidad temporal del algoritmo.*

### 2.1 Pasos a seguir para utilizar la aplicación

*1.- Abrir la terminal.*

*2.- Acceder al directorio donde vas a clonar el repositorio. Ej: cd desktop.*

*3.- Usar el comando "git clone" seguido del link del repositorio, que es  el siguiente: https://github.com/tec-csf/tc2017-t1-primavera-2020-equipo-4-1 . Quedaria de la siguente manera: "git clone https://github.com/tec-csf/tc2017-t1-primavera-2020-equipo-4-1".*

*4.- Acceder al clon/carpeta del repositorio desde la terminal, el cuál se guardó donde se hizo el "git clone". Ej: "cd tc2017-t1-primavera-2020-equipo-4-1".*

*5.- Una vez que estés dentro de la carpeta del repositorio tendras que acceder a la carpeta de sources con el siguente comando: "cd sources".*

*6.- Para poder utilizar el programa primero deberas compilar con el siguiente comando: "g++ Main.cpp -o Main".*

*7.- El siguiente paso, para poder correrlo, es ingresar el siguiente comando: "./Main -i " seguido por el path del archivo que quieres leer. Un ejemplo de path es el siguiente: "/Users/sebastiangomez/Desktop/tc2017-t1-primavera-2020-equipo-4-1/sources/example1.txt". 
El comando final para correr la aplicación es "./Main -i /Users/sebastiangomez/Desktop/tc2017-t1-primavera-2020-equipo-4-1/sources/example1.txt".*

## 3. Referencias

*DANIWEB. (2009). Simple Polinomila class. [Online] Recuperado de: https://www.daniweb.com/programming/software-development/code/217091/simple-polynomial-class*
*GeeksforGeeks. (2015). Remove spaces from a given string. [Online]. Recuperado de: https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/*
