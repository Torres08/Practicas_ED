# Programas de procesamiento de imágenes

Este repositorio contiene tres programas para procesamiento de imágenes: `contraste`, `subimagen` y `zoom`.

## Programa `contraste`

El programa `contraste` permite ajustar el contraste de una imagen mediante la transformación lineal de sus píxeles.

### Descripción de la función `AjustarContraste()`

La función `AjustarContraste()` toma los siguientes parámetros:

- `fich_orig`: Nombre del archivo de la imagen original.
- `fich_rdo`: Nombre del archivo de la imagen resultante.
- `e1`: Primer umbral usado para la transformación (x).
- `e2`: Segundo umbral usado para la transformación (x).
- `s1`: Primer umbral usado para la transformación (T(x)).
- `s2`: Segundo umbral usado para la transformación (T(x)).

ejemplo de uso 
```bash
./contraste ../Imagenes/vacas.pgm ../Imagenes/ejemplo2.png 10 10 20 20
```

## Programa `subimagen`

El programa `subimagen` permite extraer una subimagen de una imagen original dada cierta posición y tamaño.

### Descripción de la función `ExtraerSubimagen()`

La función `ExtraerSubimagen()` toma los siguientes parámetros:

- `fich_orig`: Nombre del archivo de la imagen original.
- `fich_rdo`: Nombre del archivo de la subimagen resultante.
- `fil`: Índice de la fila a partir de la cual se creará la subimagen resultante.
- `col`: Índice de la columna a partir de la cual se creará la subimagen resultante.
- `fils_sub`: Tamaño vertical de la subimagen resultante.
- `cols_sub`: Tamaño horizontal de la subimagen resultante.

Ejemplo de uso 
```bash
❯ ./subimagen ../Imagenes/vacas.pgm ../Imagenes/ejemplo2.pgm 10 10 20 20
```

## Programa `zoom`

El programa `zoom` permite hacer un zoom sobre una región específica de una imagen.

### Descripción de la función `HacerZoom()`

La función `HacerZoom()` toma los siguientes parámetros:

- `fich_orig`: Nombre del archivo de la imagen original.
- `fich_rdo`: Nombre del archivo de la imagen resultante.
- `fil`: Índice de la fila a partir de la cual se creará la subimagen resultante.
- `col`: Índice de la columna a partir de la cual se creará la subimagen resultante.
- `fils_sub`: Tamaño vertical de la imagen resultante.
- `cols_sub`: Tamaño horizontal de la imagen resultante.


Ejemplo de uso
```bash
./zoom ../Imagenes/vacas.pgm ../Imagenes/ejemplo.pgm 10 10 20 20
```

Ademas se genera su correspondiente documentacion con doxygen
