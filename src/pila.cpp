// 5093257

#include "../include/pila.h"
#include "../include/lista.h"
#include "../include/utils.h"

#include <assert.h>

struct _rep_pila {
    TLista lista;
};

TPila crearPila() {
    TPila pila = new _rep_pila;
    (*pila).lista = crearLista();
    return pila;
}

/*
  Devuelve 'true' si y solo si 'pila' no tiene elementos.
 */
bool esVaciaPila(TPila pila) {
    return longitud((*pila).lista) == 0;
}

/*
  Si en 'pila' hay menos de MAX (definido en utils.h) elementos apila
  'nuevo' en 'pila'. En otro caso la operación no tiene efecto.
  Devuelve 'pila'.
 */
TPila apilar(info_t nuevo, TPila pila) {
    nat pos = longitud((*pila).lista) + 1;
    TLista resLista = insertar(pos, nuevo, (*pila).lista);
    (*pila).lista = resLista;
    return pila;
}

/*
  Devuelve el tope de 'pila'.
  Precondición: 'pila' tiene elementos.
 */
info_t cima(TPila pila) {
    nat pos = longitud((*pila).lista);
    return infoLista(pos, (*pila).lista);
}

/*
  Si 'pila' tiene elementos desapila el tope de 'pila'.
  En otro caso la operación no tiene efecto.
  Devuelve 'pila'.
 */
TPila desapilar(TPila pila){ 
    nat pos = longitud((*pila).lista);
    (*pila).lista = remover(pos, (*pila).lista);
    return pila;
}
