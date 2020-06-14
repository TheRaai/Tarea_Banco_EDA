#### Autor: Raimundo Moraga
#### Rut: 20.072.048-2
#### Sección: 3

### Instrucciones
Para poder ejecutar el programa, se debe escribir el siguiente comando en terminal:

```console
$gcc main.c hash.c lista.c pila.c -o main
$./main
```
o con el compilador preferido.


### Observaciones:
1. Al ocupar Valgrind para ejecutar el codigo, al liberar memoria en la funcion limpiar() (archivo main linea 215), se termina dando el siguiente reporte:

```console
==587== HEAP SUMMARY:
==587==     in use at exit: 74,454 bytes in 1,037 blocks
==587==   total heap usage: 7,005 allocs, 6,106 frees, 475,768 bytes allocated
```

2. Pruebas hechas usando gcc version 7.5.0 y Valgrind-3.13.0.
