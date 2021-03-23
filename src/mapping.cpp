// 5093257

#include "../include/mapping.h"
#include "../include/lista.h"
#include "../include/utils.h"

#include <assert.h>

struct _rep_mapping {
    TLista lista;
};

TMapping crearMapping() {
    TMapping map = new _rep_mapping;
    (*map).lista = crearLista();
    return map;
}

/*
  Si en 'map' hay menos de MAX (definido en utils.h) asociaciones y 'clave'
  no tiene un valor asociado en 'map' agrega en 'map' la asociación
  (clave,valor). En otro caso la operación no tiene efecto.
  Devuelve 'map'.
 */
TMapping asociar(nat clave, double valor, TMapping map){ 
    if (!esClave(clave, map)) {
        struct info_t nuevaInfo = { clave, valor};
        nat pos = longitud((*map).lista) + 1;
        (*map).lista = insertar(pos, nuevaInfo, (*map).lista);
    }
    return map;
}

/*
  Devuelve 'true' si y solo si 'clave' tiene un valor asociado en 'map'.
 */
bool esClave(nat clave, TMapping map) {
    return posNat(clave, (*map).lista) != 0;
}

/*
  Devuelve el valor que en 'map' está asociado a 'clave'.
  Precondición: esClave(clave, map)
 */
double valor(nat clave, TMapping map) {
    nat pos = posNat(clave, (*map).lista);
    info_t res = infoLista(pos, (*map).lista);
    return res.real;
}

/*
  Si 'clave' tiene un valor asociado en 'map' remueve de `map' la asociación de
  'clave'. En otro caso la operación no tiene efecto.
  Devuelve 'map'.
 */
TMapping desasociar(nat clave, TMapping map) {
    nat pos = posNat(clave, (*map).lista);
    (*map).lista = remover(pos, (*map).lista);
    return map;
}