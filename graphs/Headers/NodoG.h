#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
#include "Arista.h"
using namespace std;

class Arista;
class NodoG
{
    private:
        string ciudad;
        NodoG* siguiente;
        Arista* aristaCabeza;
        int numAristas = 0;
    public:
        // Constructor
        NodoG();
        NodoG(string nombreCiudad);

        string obtenerCiudad();

        void cambiarCiudad(string ciudad);

        Arista* obtenerAristas();

        void verDatos();

        NodoG* obtenerSiguiente();

        void cambiarSiguiente(NodoG*);

        void agregarArista(NodoG* nodoOrigen, NodoG* nodoDestino, double distancia);

        void eliminarAristas();

};

#endif // NODE_H_INCLUDED