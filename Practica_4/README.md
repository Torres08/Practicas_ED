

# TDA Diccionario Y Guia telefonica


## Diccionario
El programa interactivo gestiona un diccionario desde un archivo. Verifica y carga el diccionario, luego muestra un menú para visualizar, obtener información, eliminar, filtrar y salir.

### Funcionalidad del Diccionario

1. **Borrar un Elemento por su Clave**
2. **Hacer la Unión de Diccionarios** (como operador +)
3. **Devolver Elementos Dentro de un Rango de Claves**
4. **Hacer la Diferencia de Diccionarios** (operador -)

### Ejemplo de Ejecución

```bash
make all
./bin/usodiccionario ./datos/data.txt
¡Diccionario leido con exito!

- 1. Visualizar el Diccionario
- 2. Obtener información sobre una palabra
- 3. Eliminar una palabra
- 4. Filtrar en un rango
- 5. Salir
```

## Guia Telefonica

El programa interactivo maneja una guía telefónica, ofreciendo opciones para visualizar, obtener información, insertar, filtrar y modificar contactos. Emplea iteradores para navegar la guía y brinda retroalimentación al usuario en la consola.


### Funcionalidad de la guia

1. Visualizar la guia cargada
2. obtener info de una persona
3. insertar contacto
4. devolver telefonos segun un rango 
5. Devolver telefonos segun una letra determinada
6. Modificar un telefono

### Ejemplo de Ejecución
```bash
make all
./bin/usoguia ./datos/guia.txt
    La guia insertada 
    Carlos Fardon Rue     333987124
    Carolina Fuentes Diaz   222222222
    Fernando Gonzalez Pro   111111111
    Francisca Conta Ere     110011001
    Laureano Cruz Sol       232323232
    Luis Sanlucas Tris      666999888
    Simon Bolivar Carrion   444444444
    Susana Arriba Bailon    958665544

  MENU           

- 1. Visualizar la guia
- 2. Obtener información sobre una persona
- 3. Inserccion de un contacto en mi guia
- 4. Devuelve telefonos cuyos nombres asociados estan en un rango
- 5. Devuelve los telefonos de aquellos que empiecen por una letradeterminada
- 6. Modifica un telefono

```
