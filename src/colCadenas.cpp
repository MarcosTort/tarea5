#include "../include/cadena.h"
#include "../include/colCadenas.h"
#include "../include/binario.h"
#include "../include/utils.h"
#include "../include/colaBinarios.h"
#include "stddef.h"
#include "assert.h"
#include "stdlib.h"
#include <stdio.h>
/*
  Devuleve una colección de 'M' cadenas vacías.
  Precondición: M > 0.
  El tiempo de ejecución en el peor caso es O(M).
 */

struct _rep_colCadenas{
  TCadena *arr;
  nat tope;
  nat cota;
};

TColCadenas crearColCadenas(nat M){

  TColCadenas nuevo = new _rep_colCadenas;
  nuevo->arr = new TCadena[M];
  nuevo->cota= M;
  nuevo->tope = 0;
  for (nat i = 0; i < M ; i++)
  {
    nuevo->arr[i] = crearCadena();
  }
  
  return nuevo;
}

/*
  Inserta 'info' al inicio de la cadena de 'col' identificada con 'pos'.
  El tiempo de ejecución en el peor caso es O(1).
  Devuleve cad.
 */
TColCadenas insertarEnColCadenas(TInfo info, nat pos, TColCadenas col){
  if(!esVaciaCadena(col->arr[pos])){
    TLocalizador inicio = inicioCadena(col->arr[pos]);
    col->arr[pos] = insertarAntes(info, inicio, col->arr[pos]);
    return col;
  }
  else{
     col->arr[pos] = insertarAlFinal(info,  col->arr[pos]);
     return col;
  }
}


/*
  Devuelve 'true' si y solo si 'dato' es el componente natural de algún
  elemento de la cadena de 'col' identificada con 'pos'.
  El tiempo de ejecución en el peor caso es O(p), siendo 'p' la cantidad
  de elementos de la cadena identificada con 'pos'..
 */
bool estaEnColCadenas(nat dato, nat pos, TColCadenas col){
  
  TCadena cad = col->arr[pos];
  if(esVaciaCadena(cad)) return false;
  else{
    
    TLocalizador loc = inicioCadena(cad);
    if(esFinalCadena(loc, cad)) 
      return natInfo(infoCadena(loc, cad)) == dato;
    else{
      while(natInfo(infoCadena(loc, cad)) != dato && esLocalizador(siguiente(loc, cad)))
       loc = siguiente(loc, cad);
      return natInfo(infoCadena(loc, cad)) == dato;
    }
  }
}

/*
  Devuelve el primer elemento (el más cercano al inicio) de la cadena de 'col'
  identificada con 'pos' cuyo componenete natural es 'dato'.
  Precondición: estaEnColCadenas(dato, pos, col)
  El tiempo de ejecución en el peor caso es O(p), siendo 'p' la cantidad
  de elementos de la cadena identificada con 'pos'..
 */
TInfo infoEnColCadenas(nat dato, nat pos, TColCadenas col){
  TCadena cad = col->arr[pos];

    TLocalizador loc = inicioCadena(cad);
    if(esFinalCadena(loc, cad)) 
      return infoCadena(loc, cad);
    else{
      while(natInfo(infoCadena(loc, cad)) != dato && esLocalizador(siguiente(loc, cad)))
       loc = siguiente(loc, cad);
      return infoCadena(loc, cad);
    }
}

/*
  Remueve el primer elemento (el más cercano al inicio) de la cadena de 'col'
  identificada con 'pos' cuyo componenete natural es 'dato'.
  Precondición: estaEnColCadenas(dato, pos, col)
  El tiempo de ejecución en el peor caso es O(p), siendo 'p' la cantidad
  de elementos de la cadena identificada con 'pos'..
  Devuleve cad.
 */
TColCadenas removerDeColCadenas(nat dato, nat pos, TColCadenas col){
  TLocalizador inicio = inicioCadena(col->arr[pos]);
  TLocalizador aBorrar = siguienteClave(dato, inicio, col->arr[pos]);
  col->arr[pos] = removerDeCadena(aBorrar, col->arr[pos]);
  if(esVaciaCadena(col->arr[pos]))
    col--;
  return col;
}

/*
  Devuelve la memoria asignada a 'col' y todos sus elementos.
  El tiempo de ejecución es O(n), siendo 'n' la suma de ña cantidad de
  elementos en cada una de las cadenas de 'col'.
 */
void liberarColCadenas(TColCadenas col){
  nat i = 0;
  while(col->tope > 0){

    liberarCadena(col->arr[i]);
    col->tope--;
    i++;

  }
  delete col;
}
