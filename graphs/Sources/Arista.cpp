#include "../Headers/Arista.h"

Arista::Arista(){}

Arista::Arista(NodoG* nodoOrigen, NodoG* nodoDestino, double distanciaEntre)
{
    origen = nodoOrigen;
    destino = nodoDestino;
    distancia = distanciaEntre;
}

NodoG* Arista::obtenerOrigen()
{
    return origen;
}

void Arista::cambiarOrigen(NodoG* nuevoOrigen)
{
    origen = nuevoOrigen;
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