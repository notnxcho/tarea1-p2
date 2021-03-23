// 5093257

#include "../include/cola.h"
#include "../include/lista.h"
#include "../include/utils.h"

#include <assert.h>

struct _rep_cola {
    TLista lista;
};

/*
  Devuelve un elemento de tipo 'TCola' vacío (sin elementos).
 */
TCola crearCola(){
    TCola cola = new _rep_cola;
    (*cola).lista = crearLista();
    return cola;
}

/*
  Devuelve 'true' si y solo si 'cola' no tiene elementos.
 */
bool esVaciaCola(TCola cola){
    return longitud((*cola).lista) == 0;
}
/*
  Si en 'cola' hay menos de MAX (definido en utils.h) elementos encola
  'nuevo' en 'cola'. En otro caso la operación no tiene efecto.
  Devuelve 'cola'.
 */
TCola encolar(info_t nuevo, TCola cola) {
    nat pos = longitud((*cola).lista) + 1;
    (*cola).lista = insertar(pos, nuevo, (*cola).lista);
    return cola;
}

/*
  Devuelve el frente de 'cola'.
  Precondición: 'cola' tiene elementos.
 */
info_t frente(TCola cola) {
    return infoLista(1, (*cola).lista);
}

/*
  Si 'cola' tiene elementos desapila el frente de 'cola'.
  En otro caso la operación no tiene efecto.
  Devuelve 'cola'.
 */
TCola desencolar(TCola c) {
    (*c).lista = remover(1, (*c).lista);
    return c;
}