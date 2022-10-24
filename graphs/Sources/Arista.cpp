#include "../Headers/Arista.h"

Arista::Arista(){}

Arista::Arista( NodoG* nodoDestino, double distanciaEntre)
{
    destino = nodoDestino;
    distancia = distanciaEntre;
}

NodoG* Arista::obtenerDestino()
{
    return destino;
}

void Arista::cambiarDestino(NodoG* nuevoDestino)
{
    destino = nuevoDestino;
}

double Arista::obtenerDistancia()
{
    return distancia;
}

void Arista::cambiarDistancia(double nuevaDistancia)
{
    distancia = nuevaDistancia;
}

Arista* Arista::obtenerSiguiente()
{
    return siguiente;
}

void Arista::cambiarSiguiente(Arista* nuevoSiguiente)
{
    siguiente = nuevoSiguiente;
}