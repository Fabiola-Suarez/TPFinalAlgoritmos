#include "../Headers/Grafo.h"

Grafo::Grafo()
{
    numNodos = 0;
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
    NodoG* aux = primero;
    for(int i=0; i<=numNodos; i++){
        aux->verDatos();
        aux = aux->obtenerSiguiente();
    }
}

void Grafo::eliminarNodos()
{
    while (numNodos != 0){
        NodoG* borrar = primero;
        NodoG* aux = borrar->obtenerSiguiente();
        borrar->eliminarAristas();
        delete borrar;
        primero = aux;
        numNodos--;
    }
}

void Grafo::agregarNodo(NodoG* nodo)
{
    NodoG* aux = primero;
    
    for (int i=0; i<numNodos; i++) {
        aux = aux->obtenerSiguiente();
    }

    aux->cambiarSiguiente(nodo);

    numNodos++;
}