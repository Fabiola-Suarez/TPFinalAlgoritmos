#include "../Headers/NodoG.h"
#include <iostream>

NodoG::NodoG(string nombreCiudad)
{
    ciudad = nombreCiudad;
}

string NodoG::obtenerCiudad()
{
    return ciudad;
}

void NodoG::cambiarCiudad(string nombreCiudad)
{
    ciudad = nombreCiudad;
}

void NodoG::verDatos()
{  
    cout << ">>> Nodo: " << ciudad << endl;
    if(numAristas>0){
        cout << "   Aristas: " << endl;
        Arista arista = *(aristaCabeza);
        for(int i=0; i<numAristas; i++){
            cout <<"        "<< arista.obtenerOrigen()->obtenerCiudad()  << " -> " << arista.obtenerDestino()->obtenerCiudad() << " = " << arista.obtenerDistancia()<<endl;
            if(i<numAristas-1){
                arista = *(arista.obtenerSiguiente());
            }
        }
    }
    else{
        cout <<"    Aristas: -" <<endl;
    }
}

 NodoG* NodoG::obtenerSiguiente()
 {
    return siguiente;
 }

 void NodoG::cambiarSiguiente(NodoG* nodo)
 {
    siguiente = nodo;
 }

void NodoG::agregarArista(NodoG* nodoOrigen, NodoG* nodoDestino, double distancia)
{
    
 
    if(numAristas==0){
        aristaCabeza = new Arista(nodoOrigen, nodoDestino, distancia);
    } 
    else {
        Arista* nueva = new Arista(nodoOrigen, nodoDestino, distancia);
        Arista* aux = aristaCabeza;
        
        for(int i=1; i<numAristas; i++){
          aux = aux->obtenerSiguiente();  
        }

        aux->cambiarSiguiente(nueva);
    }
    numAristas++;
}

void NodoG::eliminarAristas()
{   
    while(numAristas != 0){
        Arista* borrar = aristaCabeza;
        Arista* aux = aristaCabeza->obtenerSiguiente();
        delete borrar;
        aristaCabeza = aux;
        numAristas--;
    }
}