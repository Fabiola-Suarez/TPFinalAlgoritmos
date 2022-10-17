#ifndef ARISTA_H_INCLUDED
#define ARISTA_H_INCLUDED
#include "NodoG.h"

class NodoG;
class Arista 
{
    private:
        NodoG* origen;
        NodoG* destino;
        double distancia;
    public:
        // Constructor
        Arista();
        Arista(NodoG* nodoOrigen, NodoG* nodoDestino, double distanciaEntre);

        NodoG* obtenerOrigen();

        void cambiarOrigen(NodoG* nuevoOrigen);

        NodoG* obtenerDestino();

        void cambiarDestino(NodoG* nuevoDestino);

        double obtenerDistancia();

        void cambiarDistancia(double distancia);
};

#endif // ARISTA_H_INCLUDED