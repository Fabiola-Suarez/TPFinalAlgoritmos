#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "NodoG.h"

class Grafo
{
    private:
        NodoG* primero;
    public:
        Grafo();
        Grafo(NodoG* primerNodo);

        NodoG* obtenerPrimero();

        void cambiarPrimero(NodoG* nodo);

        void verNodos();
};

#endif //GRAFO_H_INCLUDED