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
        Arista arista = *(aristaCabeza);
        for(int i=0; i<numAristas; i++){
            cout << "       -> " << arista.obtenerDestino()->obtenerCiudad() << " = " << arista.obtenerDistancia()<<endl;
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

void NodoG::agregarArista(NodoG* nodoDestino, double distancia)
{
    
 
    if(numAristas==0){
        aristaCabeza = new Arista(nodoDestino, distancia);
    } 
    else {
        Arista* nueva = new Arista(nodoDestino, distancia);
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
    while(numAristas > 0){
        Arista* borrar = aristaCabeza;
        Arista* aux;
        if(numAristas>1){
            aux = aristaCabeza->obtenerSiguiente();
            aristaCabeza = aux;
        }
        delete borrar;
        numAristas--;
    }
}

void NodoG::eliminarArista(string ciudadDestino)
{   
    if(numAristas>0){
        if(aristaCabeza->obtenerDestino()->obtenerCiudad() == ciudadDestino){
            Arista* borrar = aristaCabeza;
            if(numAristas>1){
                aristaCabeza = borrar->obtenerSiguiente();
            }
            delete borrar;
            numAristas--;
            cout << "Se elimino la arista con destino " << ciudadDestino << endl;
        }
        else {
            if(numAristas > 1){
                Arista* anterior = aristaCabeza;
                for (int i=1; i<numAristas; i++) {
                    Arista* actual = anterior->obtenerSiguiente();

                    if(actual->obtenerDestino()->obtenerCiudad() == ciudadDestino){
                        anterior->cambiarSiguiente(actual->obtenerSiguiente());
                        delete actual;
                        numAristas--;
                        cout << "Se elimino la arista con destino " << ciudadDestino << endl;
                    }
                }
            }
        }
    }
}