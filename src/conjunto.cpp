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
#include "../include/usoTads.h"
#include "../include/avl.h"
#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
struct _rep_conjunto{
  TAvl conjunto;
  nat minimo;
  nat maximo;
};
TConjunto crearConjunto(){
  TConjunto nuevo = new _rep_conjunto;
  nuevo->conjunto = NULL;
  nuevo->maximo = nuevo->minimo = 0;
  return nuevo;
}

/*
  Devuelve un 'TConjunto' cuyo único elemento es 'elem'.
  El tiempo de ejecución en el peor caso es O(1).
 */
TConjunto singleton(nat elem){
  TConjunto sing = crearConjunto();
  sing->conjunto = insertarEnAvl(elem ,sing->conjunto); 
  sing->maximo= sing->minimo = elem;
  return sing;
}


/*
  Devuelve un 'TConjunto' con los elementos que pertenecen a 'c1' o 'c2'.
  El 'TConjunto' resultado no comparte memoria ni con 'c1' no con 'c2'.
  El tiempo de ejecucion en el peor caso es O(n),
  siendo  'n' la cantidad de elementos del 'TConjunto' resultado.
 */
nat min(nat n, nat m){
 
  if (n < m) return n;
  else return m;
}
nat max(nat n, nat m){
  if (n < m) return m;
  else return n;
}
nat largoIter(TIterador i){
  nat l = 0;
  reiniciarIterador(i);
  while (estaDefinidaActual(i)){
    i = avanzarIterador(i);
    l++;
  }
  return l;
}
TConjunto unionDeConjuntos(TConjunto c1, TConjunto c2){
  TIterador conjunto1 = enOrdenAvl(c1->conjunto);
  TIterador conjunto2 = enOrdenAvl(c2->conjunto);
  TIterador uni = enAlguno(conjunto1, conjunto2);

  nat n = cantidadEnIterador(uni);
  uni = reiniciarIterador(uni);
  
  nat *elems = new nat[n];
  nat i;
  for ( i = 0; i < n; i++){
    if (estaDefinidaActual(uni)){  
      elems[i] = actualEnIterador(uni);
      avanzarIterador(uni);}
  }

  TConjunto res = crearConjunto();
  res->conjunto = arregloAAvl(elems, n);
  res->minimo = min(c1->minimo, c2->minimo);
  res->maximo = max(c1->maximo, c2->maximo);

  liberarIterador(conjunto2);
  liberarIterador(conjunto1);
  liberarIterador(uni);
  delete []elems;
  return res;
}

/*
  Devuelve un 'TConjunto' con los elementos de 'c1' que no pertenecen a 'c2'.
  El 'TConjunto' resultado no comparte memoria ni con 'c1' no con 'c2'.
  El tiempo de ejecucion en el peor caso es O(n1 + n2),
  siendo 'n1' y 'n2' la cantidad de elementos de 'c1' y 'c2' respectivamente y
  'n' la del 'TConjunto' resultado.
 */
TConjunto diferenciaDeConjuntos(TConjunto c1, TConjunto c2){
  TIterador conjunto1 = enOrdenAvl(c1->conjunto);
  TIterador conjunto2 = enOrdenAvl(c2->conjunto);
  TConjunto res = crearConjunto();
  TIterador dif = soloEnA(conjunto1, conjunto2);
  nat n = cantidadEnIterador(dif);
  dif = reiniciarIterador(dif);
  nat *elems = new nat[n];
  for (nat i = 0; i < n; i++){
    
    elems[i] = actualEnIterador(dif);
    if(i == 0) res->minimo = elems[i];
    if (i == n - 1) res->maximo = elems[i];
    avanzarIterador(dif);

  }
  res->conjunto = arregloAAvl(elems, n);
  
  liberarIterador(conjunto2);
  liberarIterador(conjunto1);
  liberarIterador(dif);
  delete []elems;
  return res;
}



/*
  Devuelve 'true' si y solo si 'elem' es un elemento de 'c'.
  El tiempo de ejecución en el peor caso es O(log n), siendo 'n' la cantidad de
  elementos de 'c'.
 */
bool perteneceAConjunto(nat elem, TConjunto c){

  return !estaVacioAvl(buscarEnAvl(elem, c->conjunto));
}


/*
  Devuelve 'true' si y solo si 'c' es vacío (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaVacioConjunto(TConjunto c){
  return c->conjunto == NULL;
}


/*
  Devuelve la cantidad de elementos de 'c'.
  El tiempo de ejecución en el peor caso es O(1).
 */
nat cardinalidad(TConjunto c){
  return cantidadEnAvl(c->conjunto);
}


/*
  Devuelve el mínimo de 'c'.
  Precondición: ! estaVacioConjunto(c).
  El tiempo de ejecución en el peor caso es O(1).
 */
nat minimo(TConjunto c){
  return c->minimo;
}


/*
  Devuelve el máximo de 'c'.
  Precondición: ! estaVacioConjunto(c).
  El tiempo de ejecución en el peor caso es O(1).
 */
nat maximo(TConjunto c){
  return c->maximo;
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
  TConjunto res = crearConjunto();
  res->conjunto = arregloAAvl(elems, n);
  res->minimo = elems[0];
  res->maximo = elems[n - 1];
  return res;
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
  TIterador it = enOrdenAvl(c->conjunto);
  return it;
}


/*
  Libera la memoria asignada a 'c'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'c'.
 */
void liberarConjunto(TConjunto c){
  liberarAvl(c->conjunto);
  delete c;
}

