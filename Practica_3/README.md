
# Aplicación con TDA Cola y pila con Máximo


## Cola con maximo
Esta aplicación utiliza una estructura de datos de tipo cola con una función adicional que permite obtener el máximo valor en la cola en cualquier momento. La aplicación incluye una serie de números, como 2, 7, 6 y 9, y luego procede a vaciar la cola.

### Proceso

1. **Inserción de números**: Se insertan una serie de números en la cola en el siguiente orden: 2, 7, 6, 9.

2. **Vaciamiento de la cola**: Se comienza a vaciar la cola.

3. **Obtención del máximo valor y eliminación**: En cada iteración del vaciamiento de la cola, se muestra el valor máximo actual y se elimina el elemento de la cola.
   - **Iteración 1**: El máximo valor es 9, elimino el 9.
   - **Iteración 2**: El máximo valor es 7, se elimina el 6.
   - **Iteración 3**: El máximo valor sigue siendo 7, se elimina el 7.
   - **Iteración 4**: El máximo valor es 2, se elimina el 2.

### Resultado

El resultado final muestra el contenido de la cola después de cada eliminación, con el formato `[ valor_actual / max ]`.

### Ejecución del programa

Para ejecutar el programa y observar el comportamiento de la cola con máximo, se puede utilizar el siguiente comando:

```bash
./usocola_max_pila

[ 9 / 9 ]

[ 6 / 7 ]

[ 7 / 7 ]

[ 2 / 2 ]
```


## Pila con máximo
Igual que el ejercicio anterior pero usando una pila.

Formato sigue siendo el mismo `[ valor_actual / max ]`.

### Proceso
Se introduce los numeros 3,0,10,9,8,7,6,5,4,3,2,1,0 en la pila, luego se van retirando del tope y se actualiza el valor maximo en cada iteracion.


### Resultado
```bash
./usopilas_max_cola 
[ 0 / 10 ]

[ 1 / 10 ]

[ 2 / 10 ]

[ 3 / 10 ]

[ 4 / 10 ]

[ 5 / 10 ]

[ 6 / 10 ]

[ 7 / 10 ]

[ 8 / 10 ]

[ 9 / 10 ]

[ 10 / 10 ]

[ 0 / 3 ]

[ 3 / 3 ]
```


