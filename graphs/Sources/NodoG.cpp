#include "../Headers/NodoG.h"
#include <iostream>

NodoG::NodoG(string nombreCiudad, int cantAristas)
{
    ciudad = nombreCiudad;
    if (cantAristas!=0){
        listaAristas = new Arista[cantAristas];
    }
}

string NodoG::obtenerCiudad()
{
    return ciudad;
}

void NodoG::cambiarCiudad(string nombreCiudad)
{
    ciudad = nombreCiudad;
}

void NodoG::verAristas()
{   
    for (int i=0; i<numAristas; i++){
        Arista arista = listaAristas[i];
        cout << arista.obtenerOrigen()->obtenerCiudad()  << " -> " << arista.obtenerDestino()->obtenerCiudad() << " = " << arista.obtenerDistancia()<<endl;
    }
}

void NodoG::agregarArista(NodoG* nodoOrigen, NodoG* nodoDestino, double distancia)
{
    Arista* guardar = (listaAristas+numAristas);
    
    guardar->cambiarOrigen(nodoOrigen);
    guardar->cambiarDestino(nodoDestino);
    guardar->cambiarDistancia(distancia);
    numAristas++;
}

