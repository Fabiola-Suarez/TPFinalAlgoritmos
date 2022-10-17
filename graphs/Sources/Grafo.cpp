#include "../Headers/Grafo.h"

Grafo::Grafo(NodoG* primerNodo)
{
    primero = primerNodo;
}

NodoG* Grafo::obtenerPrimero()
{
    return primero;
}

void Grafo::cambiarPrimero(NodoG* nuevoPrimero)
{
    primero = nuevoPrimero;
}

void Grafo::verNodos()
{
    if (primero) {
        cout << ">>> Nodo: " << primero->obtenerCiudad() << endl;
        cout << " Aristas: " << endl;
        primero->verAristas();
    };
}