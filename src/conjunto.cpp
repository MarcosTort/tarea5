/*
  Devuelve un 'TConjunto' vacío (sin elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
#include "../include/conjunto.h"
#include "../include/utils.h"
#include "../include/iterador.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/cadena.h"
#include "../include/binario.h"
#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
struct _rep_conjunto{
  TBinario dato;
};
TConjunto crearConjunto(){
  return NULL;
}

/*
  Devuelve un 'TConjunto' cuyo único elemento es 'elem'.
  El tiempo de ejecución en el peor caso es O(1).
 */
TConjunto singleton(nat elem){
  return NULL;
}


/*
  Devuelve un 'TConjunto' con los elementos que pertenecen a 'c1' o 'c2'.
  El 'TConjunto' resultado no comparte memoria ni con 'c1' no con 'c2'.
  El tiempo de ejecucion en el peor caso es O(n),
  siendo  'n' la cantidad de elementos del 'TConjunto' resultado.
 */
TConjunto unionDeConjuntos(TConjunto c1, TConjunto c2){
  return NULL;
}


/*
  Devuelve un 'TConjunto' con los elementos de 'c1' que no pertenecen a 'c2'.
  El 'TConjunto' resultado no comparte memoria ni con 'c1' no con 'c2'.
  El tiempo de ejecucion en el peor caso es O(n1 + n2),
  siendo 'n1' y 'n2' la cantidad de elementos de 'c1' y 'c2' respectivamente y
  'n' la del 'TConjunto' resultado.
 */
TConjunto diferenciaDeConjuntos(TConjunto c1, TConjunto c2){
  return NULL;
}


/*
  Devuelve 'true' si y solo si 'elem' es un elemento de 'c'.
  El tiempo de ejecución en el peor caso es O(log n), siendo 'n' la cantidad de
  elementos de 'c'.
 */
bool perteneceAConjunto(nat elem, TConjunto c){
  return true;
}


/*
  Devuelve 'true' si y solo si 'c' es vacío (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaVacioConjunto(TConjunto c){
  return true;
}


/*
  Devuelve la cantidad de elementos de 'c'.
  El tiempo de ejecución en el peor caso es O(1).
 */
nat cardinalidad(TConjunto c){
  return 0;
}


/*
  Devuelve el mínimo de 'c'.
  Precondición: ! estaVacioConjunto(c).
  El tiempo de ejecución en el peor caso es O(1).
 */
nat minimo(TConjunto c){
  return 0;
}


/*
  Devuelve el máximo de 'c'.
  Precondición: ! estaVacioConjunto(c).
  El tiempo de ejecución en el peor caso es O(1).
 */
nat maximo(TConjunto c){
  return 0;
}


/*
  Devuelve un 'TConjunto' con los 'n' elementos que están en en el rango
  [0 .. n - 1] del arreglo 'elems'.
  Precondiciones:
  - n > 0
  - Los elementos están ordenados de manera creciente estricta
  (creciente y sin repetidos).
  El tiempo de ejecución en el peor caso es O(n).
 */
TConjunto arregloAConjunto(ArregloNats elems, nat n){
  return NULL;
}


/*
  Devuelve un 'TIterador' de los elementos de 'c'.
  En la recorrida del iterador devuelto los elementos aparecerán en orden
  creciente.
  El 'TIterador' resultado no comparte memoria con 'c'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'c'.
 */
TIterador iteradorDeConjunto(TConjunto c){
  return NULL;
}


/*
  Libera la memoria asignada a 'c'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'c'.
 */
void liberarConjunto(TConjunto c){
  
}

