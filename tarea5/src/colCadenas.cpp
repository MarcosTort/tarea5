#include "../include/cadena.h"
#include "../include/colCadenas.h"
#include "../include/binario.h"
#include "../include/utils.h"
#include "../include/colaBinarios.h"
#include "stddef.h"
#include "assert.h"
/*
  Devuleve una colección de 'M' cadenas vacías.
  Precondición: M > 0.
  El tiempo de ejecución en el peor caso es O(M).
 */
struct celda{
  nat lugar;
  TCadena cad;
};

struct _rep_colCadenas{
  celda *array;
  nat tope;
  nat cota;
};

TColCadenas crearColCadenas(nat M){

  TColCadenas nuevo = new _rep_colCadenas;
  nuevo->array = new celda[M];
  nuevo->cota= M;
  nuevo->tope = 0;
  return nuevo;
}

/*
  Inserta 'info' al inicio de la cadena de 'col' identificada con 'pos'.
  El tiempo de ejecución en el peor caso es O(1).
  Devuleve cad.
 */
TColCadenas insertarEnColCadenas(TInfo info, nat pos, TColCadenas col){
  
   i = 0;
  while( col->array[i]->lugar != pos ){
    i++
  }
  TLocalizador inicio = inicioCadena(col->array[i]->)

}

/*
  Devuelve 'true' si y solo si 'dato' es el componente natural de algún
  elemento de la cadena de 'col' identificada con 'pos'.
  El tiempo de ejecución en el peor caso es O(p), siendo 'p' la cantidad
  de elementos de la cadena identificada con 'pos'..
 */
bool estaEnColCadenas(nat dato, nat pos, TColCadenas col);

/*
  Devuelve el primer elemento (el más cercano al inicio) de la cadena de 'col'
  identificada con 'pos' cuyo componenete natural es 'dato'.
  Precondición: estaEnColCadenas(dato, pos, col)
  El tiempo de ejecución en el peor caso es O(p), siendo 'p' la cantidad
  de elementos de la cadena identificada con 'pos'..
 */
TInfo infoEnColCadenas(nat dato, nat pos, TColCadenas col);

/*
  Remueve el primer elemento (el más cercano al inicio) de la cadena de 'col'
  identificada con 'pos' cuyo componenete natural es 'dato'.
  Precondición: estaEnColCadenas(dato, pos, col)
  El tiempo de ejecución en el peor caso es O(p), siendo 'p' la cantidad
  de elementos de la cadena identificada con 'pos'..
  Devuleve cad.
 */
TColCadenas removerDeColCadenas(nat dato, nat pos, TColCadenas col);

/*
  Devuelve la memoria asignada a 'col' y todos sus elementos.
  El tiempo de ejecución es O(n), siendo 'n' la suma de ña cantidad de
  elementos en cada una de las cadenas de 'col'.
 */
void liberarColCadenas(TColCadenas col);
