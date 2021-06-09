
#include "../include/avl.h"
#include "../include/utils.h"
#include "../include/iterador.h"
#include "../include/info.h"
#include "../include/binario.h"
#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
/*
  Devuelve un 'TAvl' vacío (sin elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
struct _rep_avl {
  nat *dato ;
  nat altura ;
  nat cantidad;
  TAvl izq , der ;
};


TAvl crearAvl(){
  // TAvl res = new _rep_avl;
  // res->cantidad = 0;
  // res->altura = 0;
  // res = res->izq = res->der = NULL;
  return NULL;
}

/*
  Devuelve 'true' si y solo si 'avl' es vacío (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaVacioAvl(TAvl avl){
  return avl == NULL;
}

/*
  Inserta 'elem' en 'avl' respetando la propiedad de orden definida.
  Precondición: esVacioAvl(buscarEnAvl(elem, avl).
  Devuelve 'avl'.
  El tiempo de ejecución en el peor caso es O(log n), siendo 'n' la cantidad
  de elementos de 'avl'.
*/
static nat max(nat a ,nat b){//LISTO
if(a > b) return a;
else      return b;
}
void rotarDerecha( TAvl & z ) { // precond : z y z->izq != NULL
  if(z->izq != NULL && z != NULL ){
    TAvl y = z->izq ;
    TAvl T3 = y->der ;
    y-> der = z ;
    z-> izq = T3 ;
    z-> altura = max( alturaDeAvl (z-> izq ) , alturaDeAvl (z-> der ) ) + 1;
    z->cantidad = cantidadEnAvl (z->der) + cantidadEnAvl (z->izq) + 1;
    y-> altura = max( alturaDeAvl (y-> izq ) , alturaDeAvl (y-> der ) ) + 1;
    y->cantidad =cantidadEnAvl (y->der) + cantidadEnAvl (y->izq) + 1;
    z = y ;
  }

}
void rotarIzquierda( TAvl & z ) { // precond : el z y z->der != ←-NULL
  if(z->der != NULL && z != NULL ){
    TAvl y = z -> der ;
    TAvl T2 = y -> izq ;
    y -> izq = z ;
    z -> der = T2 ;
    z -> altura = max ( alturaDeAvl (z -> izq ) , alturaDeAvl (z -> der ) ) +1;
    z->cantidad = cantidadEnAvl (z->der) + cantidadEnAvl (z->izq) + 1;
    y -> altura = max ( alturaDeAvl (y -> izq ) , alturaDeAvl (y -> der ) ) +1;
    y->cantidad = cantidadEnAvl (y->der) + cantidadEnAvl (y->izq) + 1;
    z = y ;
  }
}
TAvl insertarEnAvl(nat elem, TAvl avl){
  if(estaVacioAvl(avl)){
    TAvl res = new _rep_avl;
    *res->dato = elem;
    res->izq = res->der = NULL;
    res->altura = 1;
    res->cantidad = 1;
    return res;
  }
  else{
    if ( elem < *avl->dato){
      avl->izq = insertarEnAvl(elem, avl->izq);
      avl->altura = 1 + max(alturaDeAvl(izqAvl(avl)), alturaDeAvl(derAvl(avl)));
      avl->cantidad = cantidadEnAvl(avl->der) + cantidadEnAvl(avl->izq) + 1;
      //factor de balance
      int FB = alturaDeAvl(izqAvl(avl))  - alturaDeAvl( derAvl(avl ));
      if(FB > 1){
        if( alturaDeAvl(avl->izq->izq) > alturaDeAvl(avl->izq->der)){
          rotarDerecha(avl);
        }else{
          rotarIzquierda(avl->izq);
          rotarDerecha(avl);
        }
      }
    }
    else{
      avl->der = insertarEnAvl(elem, derAvl(avl));
      avl->altura = 1 + max(alturaDeAvl(izqAvl(avl)), alturaDeAvl(derAvl(avl)));
      avl->cantidad = cantidadEnAvl(avl->der) + cantidadEnAvl(avl->izq) + 1;
      int FB = alturaDeAvl(izqAvl(avl))  - alturaDeAvl( derAvl(avl ));
      if(FB < -1){
        if( alturaDeAvl(avl->der->der) > alturaDeAvl(avl->der->izq) ){
          rotarIzquierda(avl);
        }else{
          rotarDerecha(avl->der);
          rotarIzquierda(avl);
        }
      }
    }
    return avl;
  }
}

/*
  Devuelve el subárbol cuya raíz es 'elem'.
  Si ningún nodo cumple esa condición devuelve el árbol vacío.
  El 'TAvl' resultado comparte memoria con el parámetro.
  El tiempo de ejecución en el peor caso es O(log n), siendo 'n' la cantidad
  de elementos de 'avl'.
 */
TAvl buscarEnAvl(nat elem, TAvl avl){
  if(!estaVacioAvl(avl)){
    if(elem == *avl->dato){
      return avl;
    }
    else if(elem<*avl->dato){
      return buscarEnAvl(elem, izqAvl(avl));
    }
    else if(elem>*avl->dato){
      return buscarEnAvl(elem, derAvl(avl));
    }
    else return NULL;
  }
  else return NULL;
}

/*
  Devuelve el elemento asociado a la raíz de 'avl'.
  Precondición: ! esVacioAvl(b).
  El tiempo de ejecución en el peor caso es O(1).
 */
nat raizAvl(TAvl avl){
  return *avl->dato;
}

/*
  Devuelve el subárbol izquierdo de 'avl'.
  Precondición: ! esVacioAvl(TAvl).
  El 'TAvl' resultado comparte memoria con el parámetro.
  El tiempo de ejecución en el peor caso es O(1).
 */
TAvl izqAvl(TAvl avl){
  return avl->izq;
}

/*
  Devuelve el subárbol derecho de 'avl'.
  Precondición: ! esVacioAvl(TAvl).
  El 'TAvl' resultado comparte memoria con el parámetro.
  El tiempo de ejecución en el peor caso es O(1).
 */
TAvl derAvl(TAvl avl){
  return avl->der;
}

/*
  Devuelve la cantidad de elementos en 'avl'.
  El tiempo de ejecución en el peor caso es O(1).
 */
nat cantidadEnAvl(TAvl avl){
    if(estaVacioAvl(avl))
      return 0;
    else
      return avl->cantidad;
}


/*
  Devuelve la altura de 'avl'.
  La altura de un árbol vacío es 0.
  El tiempo de ejecución en el peor caso es O(1).
 */
nat alturaDeAvl(TAvl avl){
  int alt = 0;
  if ( !estaVacioAvl(avl) )
    alt = avl->altura ;
  return alt ;
}

/*
  Devuelve un 'TIterador' de los elementos de 'avl'.
  En la recorrida del iterador devuelto los elementos aparecerán en orden
  creciente.
  El 'TIterador' resultado no comparte memoria con 'avl'.
  El tiempo de ejecución en el peor caso es O(n) siendo 'n' la cantidad de
  elementos de 'avl'.
 */

TIterador ordenAvl(TIterador it, TAvl a){
  if(!estaVacioAvl(a)){
    ordenAvl(it, izqAvl(a));
    nat dato = raizAvl(a);
    agregarAIterador(dato, it);
    ordenAvl(it, derAvl(a));
    return it;
  }
  else return NULL;
}
TIterador enOrdenAvl(TAvl avl){
  if(avl != NULL)
 { TIterador res = crearIterador();
  res = ordenAvl(res, avl);
  return res ;
  }
  else return crearIterador();
}

/*
  Devuelve un 'TAvl' con los 'n' elementos que están en el rango [0 .. n - 1]
  del arreglo 'elems'.
  Precondiciones:
  - n > 0
  - Los elementos están ordenados de manera creciente estricta
  (creciente y sin  repetidos).
  En cada nodo del árbol resultado la cantidad de elementos de su subárbol
  izquierdo es igual a, o 1 menos que, la cantidad de elementos de su subárbol
  derecho.
  El tiempo de ejecución en el peor caso es O(n).
 */
TAvl avlaux(int start, int end, ArregloNats elems){

if(start > end)
  return NULL;
TAvl b = new _rep_avl;
b->dato = new nat;
int elementoMedio = (start+end)/2;
*b->dato = elems[elementoMedio];
b->cantidad = cantidadEnAvl(b->izq) + cantidadEnAvl(b->der) + 1;
b->altura = max(alturaDeAvl(b->der), alturaDeAvl(b->izq)) + 1;
if(elementoMedio < end){
  b->der = avlaux( elementoMedio + 1, end, elems);
  b->cantidad = cantidadEnAvl(b->izq) + cantidadEnAvl(b->der) + 1;
  b->altura = max(alturaDeAvl(b->der), alturaDeAvl(b->izq)) + 1;
}
if(start < elementoMedio){
  b->izq = avlaux( start, elementoMedio - 1, elems);
  b->cantidad = cantidadEnAvl(b->izq) + cantidadEnAvl(b->der) + 1;
  b->altura = max(alturaDeAvl(b->der), alturaDeAvl(b->izq)) + 1;
}

  
return b;
}

TAvl arregloAAvl(ArregloNats elems, nat n){
  return avlaux(0, n-1, elems);
}

/*
  Devuelve un 'TAvl' de altura 'h' con 'n' nodos, siendo 'n' la mínima cantidad
  de elementos que puede tener un 'TAvl' de altura 'h'.
  Los elementos van desde 1 hasta 'n'.
  En ningún nodo puede ocurrir que el subárbol derecho tenga más nodos que el
  subárbol izquierdo.
  La altura de un árbol vacío es 0.
  El tiempo de ejecución en el peor caso es O(n).
  Ver ejemplos en la letra.
 */
TAvl auxMin(nat h, nat &c){
 TAvl res = crearAvl();
 
  if(h <= 0){
    return res;
  }
  else if(h == 1){
    res = new _rep_avl;
    *res->dato = c;
    res->izq = res->der = NULL;
    res->altura = h;
    res->cantidad = h;
    c++;
    return res;
  }
  else{
    res = new _rep_avl;
    res->izq =  auxMin(h - 1, c);
    *res->dato = c;
    c++;
    res->der = auxMin(h-2, c);
    res->altura = h;
    res->cantidad = cantidadEnAvl(res->der) + cantidadEnAvl(res->izq) + 1;
    return res;
  }
  return res;
}
TAvl avlMin(nat h){
  nat x = 1;
  return auxMin(h, x);
}

/*
  Libera la memoria asignada a 'TAvl'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'TAvl'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad
  de elementos de 'avl'.
 */
void liberarAvl(TAvl avl){
  if(avl != NULL){
  liberarAvl(avl->der);
  liberarAvl(avl->izq);
  delete avl;
  }

}
