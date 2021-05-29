/*
  Módulo de definición de 'TPila'.

  Los elementos de tipo 'TPila' son estructuras lineales acotadas con
  comportamiento LIFO cuyos elementos son naturales.

  La cantidad de elementos que puede mantener se establece en el parámetro
  de 'crearPila'.


  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#include "../include/utils.h"
#include "../include/info.h"
#include "../include/pila.h"

// Representación de 'TPila'.
// Se debe definir en pila.cpp.
// struct _rep_pila;
// Declaracióndel tipo 'TPila'
typedef nat * apuntador;
struct _rep_pila{
    nat* array;
    int cota;
    int tope;
};
     
/*
  Devuelve una 'TPila' vacía (sin elementos) que puede tener hasta 'tamanio'
  elementos.
  Precondición: tamanio > 0.
 */
TPila crearPila(nat tamanio){
    TPila nuevo = new _rep_pila;
    nuevo->tope = 0;
    nuevo->array = new nat[tamanio];
    nuevo->cota = tamanio;
    return nuevo;
}

/*
  Apila 'num' en 'p'.
  Devuelve 'p'.
  Si estaLlenaPila(p) no hace nada.
  El tiempo de ejecución en el peor caso es O(1).
 */
TPila apilar(nat num, TPila p){
if(!estaLlenaPila(p)){
    p->array[p->tope] = num;
    p->tope ++;
    }   
return p;
}
/*
  Remueve de 'p' el elemento que está en la cima.
  Devuelve 'p'.
  Si estaVaciaPila(p) no hace nada.
  El tiempo de ejecución en el peor caso es O(1).
 */
TPila desapilar(TPila p){
    if(!estaVaciaPila(p)){
        apuntador *mem = new apuntador;
        *mem = &p->array[p->tope - 1];

        delete mem ;
        p->tope--;
    }
    return p;
}

/*
  Libera la memoria asignada a 'p'.
 */
void liberarPila(TPila p){
    for (int i = 0; i < p->tope - 1;i++ ){
        apuntador *mem = new apuntador;
        *mem = &p->array[p->tope - 1];
        delete mem;
        
    }
    delete[] p->array;
    delete p;
}

/*
  Devuelve 'true' si y solo si 'p' es vacía (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaVaciaPila(TPila p){
    return p->tope == 0;
}

/*
  Devuelve 'true' si y solo si la cantidad de elementos en 'p' es 'tamanio'
  (siendo 'tamanio' el valor del parámetro con que fue creada 'p').
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaLlenaPila(TPila p){
    return p->tope == p->cota;
}

/*
  Devuelve el elemento que está en la cima de 'p'.
  Precondición: ! estaVaciaPila(p);
  El tiempo de ejecución en el peor caso es O(1).
 */
nat cima(TPila p){
    return p->array[p->tope - 1];
}

 
