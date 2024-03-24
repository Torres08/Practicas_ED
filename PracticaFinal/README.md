# Practica Final

El estudiante implementará programas para simular el juego "Cifras y Letras", que consta de dos partes.
1. se busca formar un número de 3 cifras con un conjunto dado y operaciones elementales. 
2.  se debe encontrar la palabra más larga o con mayor puntuación usando letras aleatorias. 

Las tareas incluyen definir los T.D.A. necesarios y probar los módulos con programas test.
- Se puede usar la STL en todos los módulos


## Problema de cifras
En la primera parte del juego "Cifras", se busca formar un número de tres cifras utilizando seis números aleatorios del conjunto {1, 2, 3, ..., 100}. Se pueden utilizar operaciones de suma, resta, multiplicación y división entera, con la restricción de utilizar cada número como máximo una vez. Si no es posible obtener el número exacto, se puede buscar el número más cercano. 

## Problema de letras
En la segunda parte, se debe formar la palabra más larga posible utilizando un conjunto aleatorio de letras, pudiendo repetirse letras y eligiendo el tamaño del conjunto el usuario.



Ejecucion de los test

```bash
make all
make testdiccionario
make testcantidad
make testletras
```