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
        Arista* listaAristas;
        int numAristas;
    public:
        // Constructor
        NodoG();
        NodoG(string nombreCiudad, int cantAristas);

        string obtenerCiudad();

        void cambiarCiudad(string ciudad);

        Arista* obtenerAristas();

        string verAristas();

        void agregarArista(NodoG* nodoOrigen, NodoG* nodoDestino, double distancia);

};

#endif // NODE_H_INCLUDED