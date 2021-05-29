#include "../include/usoTads.h"
#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/binario.h"
#include "../include/pila.h"
#include "../include/colaBinarios.h"
#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../include/iterador.h"
#include "limits.h"

/*
  Devuelve 'true' si y solo si en 'cad' hay un elemento cuyo campo natural es
  'elem'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
/*
  Devuelve la cantidad de elementos de 'it'.
  La posición actual de 'it' queda indefinida.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'it'.
 */
// nueva
/*
  Devuelve un 'TConjunto' con los elementos que pertenecen a 'c1' y 'c2'.
  El 'TConjunto' resultado no comparte memoria ni con 'c1' no con 'c2'.
  El tiempo de ejecucion en el peor caso es O(n1 + n2 + n.log n),
  siendo 'n1' y 'n2' la cantidad de elementos de 'c1' y 'c2' respectivamente y
  'n' la del 'TConjunto' resultado.
 */
TConjunto interseccionDeConjuntos(TConjunto c1, TConjunto c2);

nat cantidadEnIterador(TIterador it){
    //printf("%i", actualEnIterador(it));
    reiniciarIterador(it);
    nat i = 0;
    if(estaDefinidaActual(it)){
    while(estaDefinidaActual(it)){
        it = avanzarIterador(it);
        i++;
    }
    }
    return i;
 }

// nueva
/*
  Devuelve un TIterador con los elementos que están en 'a' o en 'b'.
  En una recorrida del iterador devuelto los elementos aparecerían en orden
  creciente estricto (no habrá elementos repetidos; si un elemento está en
  'a' y en 'b' se agrega solo una vez).
  La posiciones actual de 'a' y de 'b' quedan indefinidas.
  Precondición: en recorridas de 'a' o de 'b' los elementos aparecerían en
  orden creciente estricto (no hay elementos repetidos).
  El tiempo de ejecución en el peor caso es O(na + nb), siendo 'na' y 'nb' la
  cantidad de elementos de 'a' y 'b' respectivamente.
 */
bool esMayor(TIterador it2, TIterador it){
  assert(estaDefinidaActual(it)&&estaDefinidaActual(it));
  return actualEnIterador(it2) > actualEnIterador(it);
}
TIterador enAlguno(TIterador a, TIterador b){
    TIterador res = crearIterador();
    reiniciarIterador(a);
    reiniciarIterador(b);
    nat alguno;
    nat mem = 0;
  if(estaDefinidaActual(a)&& estaDefinidaActual(b)){
   if(actualEnIterador(a) < actualEnIterador(b)){
        alguno = actualEnIterador(a);
        if(mem != alguno)
          agregarAIterador(alguno, res);
        alguno = actualEnIterador(b);
        if(mem != alguno)
           agregarAIterador(alguno, res);
        avanzarIterador(a);
      }
      else if(actualEnIterador(a) > actualEnIterador(b)){
        alguno = actualEnIterador(b);
        if(mem != alguno)
          agregarAIterador(alguno, res);
        avanzarIterador(b);
      }else{
        alguno = actualEnIterador(b);
        if(mem != alguno)
          agregarAIterador(alguno, res); 
        avanzarIterador(b);
        avanzarIterador(a);
      }
       mem = alguno;
    }
    while(estaDefinidaActual(a)&& estaDefinidaActual(b)){
      if(actualEnIterador(a) < actualEnIterador(b)){
        alguno = actualEnIterador(a);
        if(mem != alguno)
        agregarAIterador(alguno, res);
        alguno = actualEnIterador(b);
        if(mem != alguno)
        agregarAIterador(alguno, res);
        avanzarIterador(a);
      }
      else if(actualEnIterador(a) > actualEnIterador(b)){
        alguno = actualEnIterador(b);
        if(mem != alguno)
        agregarAIterador(alguno, res);
        avanzarIterador(b);
      }else{
        alguno = actualEnIterador(b);
        if(mem != alguno)
         agregarAIterador(alguno, res); 
        avanzarIterador(b);
        avanzarIterador(a);
      }
      mem = alguno;
      }
      if(estaDefinidaActual(a)){
        while(estaDefinidaActual(a)){
          alguno = actualEnIterador(a);
	  if(mem!=alguno)
          agregarAIterador(alguno, res);
          avanzarIterador(a); 
	  mem = alguno;  
        }
      }
      if(estaDefinidaActual(b)){
        while(estaDefinidaActual(b)){
          alguno = actualEnIterador(b);
	  if(mem!=alguno)
          agregarAIterador(alguno, res);
          avanzarIterador(b);
	  mem = alguno;  	
        }
      }
    return res;
}

void imprimirIterador(TIterador it){
    printf("\n");
    printf("##################");
    printf("\n");
    printf("(");
  while(estaDefinidaActual(it)){
    
    printf("%i" "%s", actualEnIterador(it), ", ");
    avanzarIterador(it);
  }
    printf(")");
    printf("\n");
    printf("##################");
    printf("\n");
}

// nueva
/*
  Devuelve un TIterador con los elementos que están en 'a' pero no en 'b'.
  En una recorrida del iterador devuelto los elementos aparecerían en orden
  creciente estricto (no habrá elementos repetidos).
  La posiciones actual de 'a' y de 'b' quedan indefinidas.
  Precondición: en recorridas de 'a' o de 'b' los elementos aparecerían en
  orden creciente estricto (no hay elemenotos repetidos).
  El tiempo de ejecución en el peor caso es O(na + nb), siendo 'na' y 'nb' la
  cantidad de elementos de 'a' y 'b' respectivamente.
 */
TIterador soloEnA(TIterador a, TIterador b){
    TIterador res = crearIterador();
    reiniciarIterador(a);
    reiniciarIterador(b);
    nat distinto;
   
    
    while(estaDefinidaActual(a)&& estaDefinidaActual(b)){
      if(actualEnIterador(a) < actualEnIterador(b)){
        distinto = actualEnIterador(a);
        agregarAIterador(distinto, res);
        avanzarIterador(a);
      }
      else if(actualEnIterador(a) > actualEnIterador(b))
         avanzarIterador(b);
      else{
        avanzarIterador(b);
        avanzarIterador(a);
      }
      }
      while(estaDefinidaActual(a)){
        distinto = actualEnIterador(a);
        agregarAIterador(distinto, res);
        avanzarIterador(a);  
      }
  return res;
}

// nueva
/*
  Devuelve un TIterador con los componentes naturales de los elementos de
  cada nivel de 'b'.
  En la recorrida del TIterador resultado se encuentran primero los elementos
  que están en el nivel más profundo y al final el que corresponde a la raíz.
  Los elementos de cada nivel se encuentra en orden creciente (de izquierda a
  derecha).
  Para indicar el cambio de nivel se usa el valor UINT_MAX que se puede asumir
  que no es el componenete natural de ningún elemento de 'b'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'b'.

  Por ejemplo para el árbol (solo se muestran los componentes naturales)

       5
     /   \
    2     8
        /
       6

   la recorrida del TIterador resultado debe encontrar los siguientes valores
   en ese orden:

   6 UINT_MAX 2 8 UINT_MAX 5

  Ver más ejemplos en el caso 06.
 */

void aux( TBinario b, TIterador res){
  if( !esVacioBinario(b)){
    TPila s = crearPila(alturaBinario(b) + cantidadBinario(b));
    TColaBinarios q = crearColaBinarios();
    q = encolar(b, q);
    q = encolar(NULL, q);
    while(!estaVaciaColaBinarios(q)){
      b = frente(q);
      q = desencolar(q);
      if(b == NULL && !estaVaciaColaBinarios(q)){
        q = encolar(NULL, q);
        s = apilar(UINT_MAX, s);
       
      }else if (b != NULL){
      
      s = apilar(natInfo(raiz(b)), s);
      if(derecho(b) != NULL)
        q = encolar(derecho(b), q); 
      if(izquierdo(b) != NULL)
        q = encolar(izquierdo(b), q);
      }
      
    }
    liberarColaBinarios(q);
  while(!estaVaciaPila(s)){
    res = agregarAIterador(cima(s), res);
    s = desapilar(s);
  }
  liberarPila(s);
  }
}

TIterador recorridaPorNiveles(TBinario b){
    TIterador res = crearIterador();
    aux(b, res);
   return res;
}

/*
  Devuelve una 'TCadena' con los elementos del nivel 'l' de 'b'.
  La raíz es el nivel 1.
  La 'TCadena' resultado debe estar ordenada de manera creciente según los
  componentes naturales de sus elementos.
  Precondición: l > 0.
  La 'TCadena' devuelta no comparte memoria con 'b'.
 */
void rellenarCadena(nat l, nat cont,TCadena &c, TBinario b){
  if(!esVacioBinario(b)){
    if(l == cont ){ 
    insertarAlFinal(copiaInfo(raiz(b)), c);
    }
    else{
      cont ++;
      rellenarCadena(l, cont, c, derecho(b));
      rellenarCadena(l, cont, c, izquierdo(b));
    }
  }
}
TCadena nivelEnBinario(nat l, TBinario b){
  TCadena ret = crearCadena();
  rellenarCadena(l,1, ret, b);
  ordenar(ret);
  return ret;
}
bool esHoja(TBinario b)
{ // ?
  bool esAlgo = (esVacioBinario(derecho(b))) && (esVacioBinario(izquierdo(b)));
  return esVacioBinario(b) || esAlgo;
  
}

void avanzarLoc(TLocalizador &loc, TCadena cad)
{
  if (siguiente(loc, cad) != NULL)
    loc = siguiente(loc, cad);
}

bool aux(TLocalizador l, TCadena c, TBinario b)
{
  if (l == NULL && b == NULL)
    return true;
  else if (l == NULL || b == NULL)
  {
    return false;
  }
  return (natInfo(raiz(b)) == natInfo(infoCadena(l, c))) && (aux(siguiente(l, c), c, derecho(b)) || aux(siguiente(l, c), c, izquierdo(b)));
}

bool esCamino(TCadena c, TBinario b)
{
  TLocalizador loc = inicioCadena(c);
  return aux(loc, c, b);
}










bool pertenece(nat elem, TCadena cad){
  TLocalizador rec = inicioCadena(cad);
  if(!esVaciaCadena(cad)){
  while((!esFinalCadena(rec, cad)) && (natInfo(infoCadena(rec, cad)) != elem)){
    rec = siguiente(rec, cad);
  }
  return natInfo(infoCadena(rec, cad)) == elem;
  }
  else{return false;}
}
/*
  Devuelve la cantidad de elementos de 'cad'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
nat longitud(TCadena cad){
  if(esVaciaCadena(cad)){
    return 0;
  }
  else{
  nat contador = 1;
  TLocalizador rec = inicioCadena(cad);
  while(!esFinalCadena(rec, cad)){
    rec = siguiente(rec, cad);
    contador ++;
  }
  return contador;
  }
}

/*
  Devuelve 'true' si y solo si 'cad' está ordenada de forma no dereciente
  (creciente de manera no estricta) según las campos naturales de sus elementos.
  Si esVaciaVadena(cad) devuelve 'true'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
bool estaOrdenadaPorNaturales(TCadena cad){
  TLocalizador ctr = inicioCadena(cad);
  if(esVaciaCadena(cad) || esFinalCadena(ctr, cad) ){
    return true;
  }
  else{
    bool ordenado = true;
    while(!esFinalCadena(ctr, cad) && ordenado){
      ordenado = natInfo(infoCadena(ctr, cad)) <= natInfo(infoCadena(siguiente(ctr, cad), cad));
      ctr = siguiente(ctr, cad);
    }
    return ordenado;
  }
}
/*
  Devuelve 'true' si y solo si los componentes naturales de algún par de
  elementos de 'cad' son iguales.
  El tiempo de ejecución en el peor caso es O(n^2), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
 bool hayNatsRepetidos(TCadena cad){
  nat contador = 0;
  nat control;
  TLocalizador rec = inicioCadena(cad);
  TLocalizador rec2;
    if(esVaciaCadena(cad) || esFinalCadena(rec, cad) ){   //descarto cadena vacia o cadena con un elemento
      return false;
    }
    else{
    while((esLocalizador(rec)) && (contador < 1)){
      rec2 = siguiente(rec, cad);
      control = natInfo(infoCadena(rec, cad));
      while((esLocalizador(rec2)) && (contador < 1)){
        if (natInfo(infoCadena(rec2, cad)) == control){
          contador ++;
        }
        else
          rec2 = siguiente(rec2, cad);
      }
      rec = siguiente(rec, cad);
    }
    return contador == 1;
  }
}
/*
  Devuelve 'true' si y solo si 'c1' y 'c2' son iguales (es decir, si los
  elementos son iguales y en el mismo orden).
  Si esVaciaCadena(c1) y esVaciaCadena(c2) devuelve 'true'.
  El tiempo de ejecución en el peor caso es O(n1 + n2), siendo 'n1' u 'n2' la
  cantidad de elementos de 'c1' y 'c2' respectivamente.
 */
bool sonIgualesCadena(TCadena c1, TCadena c2){
  if(esVaciaCadena(c1) && esVaciaCadena(c2)){
    return true;}
    else{
      if(longitud(c1) != longitud(c2)){return false;}
      else{
        bool compar = true;
        TLocalizador l1 = inicioCadena(c1);
        TLocalizador l2 = inicioCadena(c2);
        compar = sonIgualesInfo(infoCadena(l1, c1), infoCadena(l2, c2));
        while(esLocalizador(l1) && compar){
          compar = sonIgualesInfo(infoCadena(l1, c1), infoCadena(l2, c2));
          l1 = siguiente(l1, c1);
          l2 = siguiente(l2, c2);
        }
        return compar;
      }
  }
}

/*
  Devuelve el resultado de concatenar 'c2' después de 'c1'.
  La 'TCadena' resultado no comparte memoria ni con 'c1' ni con 'c2'.
  El tiempo de ejecución en el peor caso es O(n1 + n2), siendo 'n1' u 'n2' la
  cantidad de elementos de 'c1' y 'c2' respectivamente.
 */
TCadena concatenar(TCadena c1, TCadena c2) {
	TCadena sgm = copiarSegmento(inicioCadena(c1), finalCadena(c1), c1);
  TCadena sgm2 = copiarSegmento(inicioCadena(c2), finalCadena(c2), c2);
	if(sgm == NULL)return sgm2;
  else if(sgm2 == NULL)
    return sgm; 
  else{
   insertarSegmentoDespues(sgm2, finalCadena(sgm), sgm);
  }
return sgm;
}

/*
  Se ordena 'cad' de manera creciente según los componentes naturales de sus
  elementos.
  Devuelve 'cad'
  Precondición: ! hayNatsRepetidos(cad)
  No se debe obtener ni devolver memoria de manera dinámica.
  Se debe mantener las relaciones de precedencia entre localizadores.
  Si esVaciaCadena(cad) no hace nada.
  El tiempo de ejecución en el peor caso es O(n^2), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
TCadena ordenar(TCadena cad){
  if (longitud(cad) > 1){
    TLocalizador rec = inicioCadena(cad);
    while (esLocalizador(siguiente(rec, cad)))
    {
      TLocalizador aux = siguiente(rec, cad);
      while (esLocalizador(aux))
      {
        if(natInfo(infoCadena(rec, cad))>natInfo(infoCadena(aux, cad)))
          intercambiar(aux, rec, cad);
        aux = siguiente(aux, cad);
      }
      rec = siguiente(rec, cad);
    }
  }
  return cad;
}
/*
  Cambia todas las ocurrencias de 'original' por 'nuevo' en los elementos
  de 'cad'.
  Devuelve 'cad'
  No debe quedar memoria inaccesible.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
TCadena cambiarTodos(nat original, nat nuevo, TCadena cad){
  if(!esVaciaCadena(cad)){
   double real;
   TInfo info;
   TInfo info_lib;
   TLocalizador loc = inicioCadena(cad);
   TLocalizador remov;
    while(esLocalizador(loc)){
      if(natInfo(infoCadena(loc, cad)) == original ){
         real = realInfo(infoCadena(loc, cad));
         info = crearInfo(nuevo, real);
         info_lib = copiaInfo(infoCadena(loc, cad));
         insertarAntes(info, loc, cad);
         remov = loc;
         loc = siguiente(loc, cad);
         removerDeCadena(remov, cad);
         liberarInfo(info_lib);
      }else{ loc = siguiente(loc, cad);
      }
    }
  }
  return cad;
}
/*
  Devuelve la 'TCadena' de elementos de 'cad' que cumplen
  "menor <= natInfo (elemento) <= mayor".
  El orden relativo de los elementos en la 'TCadena' resultado debe ser el mismo
  que en 'cad'.
  Precondición: estaOrdenadaPorNaturales (cad), 'menor' <= 'mayor',
  pertenece (menor, cad), pertenece (mayor, cad).
  La 'TCadena' resultado no comparte memoria con 'cad'.
  El tiempo de ejecución en el peor caso es O(n), siendo 'n' la cantidad de
  elementos de 'cad'.
 */
TCadena subCadena(nat menor, nat mayor, TCadena cad){
  TCadena sub = crearCadena();
  TLocalizador rec = inicioCadena(cad);
  TLocalizador inicioSub = NULL;
  TLocalizador finalSub = NULL;
  
  while(esLocalizador(rec)){
    if(natInfo(infoCadena(rec, cad))<= mayor) 
      finalSub = rec;

    if ((natInfo(infoCadena(rec, cad)) >= menor) && (inicioSub == NULL)) 
      inicioSub = rec;

    rec = siguiente(rec, cad);
    }
  insertarSegmentoDespues(copiarSegmento(inicioSub, finalSub, cad ), finalCadena(sub), sub);
return sub;
}

