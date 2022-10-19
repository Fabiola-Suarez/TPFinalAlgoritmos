#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "NodoG.h"

class Grafo
{
    private:
        NodoG* primero;
        int numNodos;
    public:
        Grafo();

        NodoG* obtenerPrimero();

        void cambiarPrimero(NodoG* nodo);

        void verNodos();

        void eliminarNodos();

        void agregarNodo(NodoG* nodo);
};

#endif //GRAFO_H_INCLUDED