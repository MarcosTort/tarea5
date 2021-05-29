#include "../include/binario.h"
#include "../include/utils.h"
#include "../include/colaBinarios.h"
#include "stddef.h"
#include"assert.h"
// Representación de TColaBinarios'.
// Se debe definir en colaBinarios.cpp
// struct _rep_colaBinarios;
// Declaración del tipo 'TColaBinarios'
struct celda{
  TBinario bin;
  celda *sig;
};
struct _rep_colaBinarios {
  celda *primero;
  celda *ultimo;
};

/*
  Devuelve una 'TColaBinarios' vacía (sin elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
TColaBinarios crearColaBinarios(){
    TColaBinarios nuevo = new _rep_colaBinarios;
    nuevo->primero =  NULL;
    nuevo->ultimo = NULL;
    return nuevo;
}

/*
  Encola 'b' en 'c'.
  Devuelve 'c'.
  El tiempo de ejecución en el peor caso es O(1).
 */
TColaBinarios encolar(TBinario b, TColaBinarios c){
    celda *nuevo = new celda;
    nuevo->bin = b;
    nuevo->sig = NULL;
  if(estaVaciaColaBinarios(c)){
    c->primero = c->ultimo =nuevo;
  }
  else{
    c->ultimo->sig = nuevo;
    }
    c->ultimo = nuevo;
  return c;
}

/*
  Remueve de 'c' el elemento que está en el frente.
  Si estaVaciaColaBinarios(c) no hace nada.
  Devuelve 'c'.
  NO libera la memoria del elemento removido.
  El tiempo de ejecución en el peor caso es O(1).
 */

TColaBinarios desencolar(TColaBinarios c){
    celda *aux = c->primero;
    if(!estaVaciaColaBinarios(c)){
      c->primero =  c->primero->sig ;
      if(aux->sig == NULL)
        c->ultimo = NULL;
    }
    aux->sig = NULL;
    
    delete aux;
  return c;
}

/*
  Libera la memoria asignada a 'c', pero NO la de sus elementos.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad
  de elementos de 'c'.
 */
void liberarColaBinarios(TColaBinarios c){
  celda *aux;
	while (c->primero != NULL){
		aux = c->primero;
		c->primero = c->primero->sig;
		delete aux;
	}
	delete c;
}

/*
  Devuelve 'true' si y solo si 'c' es vacía (no tiene elementos).
  El tiempo de ejecución en el peor caso es O(1).
 */
bool estaVaciaColaBinarios(TColaBinarios c)
{
  return ((c->primero == NULL) && (c->ultimo == NULL));
}

/*
  Devuelve el elemento que está en el frente de 'c'.
  Precondición: ! estaVaciaColaBinarios(c);
  El tiempo de ejecución en el peor caso es O(1).
 */
TBinario frente(TColaBinarios c){
  assert(c->primero != NULL);
  return c->primero->bin;
}

