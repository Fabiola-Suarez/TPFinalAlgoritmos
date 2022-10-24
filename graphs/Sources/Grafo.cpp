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
    for(int i=1; i<=numNodos; i++){
        aux->verDatos();
        if(!(i == numNodos)){
            aux = aux->obtenerSiguiente();
        }
    }
}

void Grafo::eliminarNodos()
{
    while (numNodos > 0){
        NodoG* borrar = primero;
        NodoG* aux;
        if(numNodos>1){
            aux = borrar->obtenerSiguiente();
            primero = aux;
        }
        borrar->eliminarAristas();
        delete borrar;
        numNodos--;
    }
}

void Grafo::eliminarNodo(string ciudad) 
{
    if(primero->obtenerCiudad() == ciudad){
        NodoG* borrar = primero;
        primero = borrar->obtenerSiguiente();
        borrar->eliminarAristas();
        eliminarAristasConDestino(ciudad);
        delete borrar;
        numNodos--;
        cout << "Se eliminó el nodo que representaba a " << ciudad << endl;
    }
    else{
        if(numNodos > 1){
            NodoG* anterior = primero;
            
            for (int i=1; i<numNodos; i++){
                NodoG* actual = anterior->obtenerSiguiente();

                if(actual->obtenerCiudad() == ciudad){
                    anterior->cambiarSiguiente(actual->obtenerSiguiente());
                    actual->eliminarAristas();
                    eliminarAristasConDestino(ciudad);
                    delete actual;
                    numNodos--;
                    cout << "Se eliminó el nodo que representaba a " << ciudad << endl;
                }
                else {
                    cout << "No se encontró el nodo que representa a " << ciudad << endl;
                    anterior = anterior->obtenerSiguiente();
                }
            }
        }
        else {
            cout << "No se encontró el nodo que representa a " << ciudad << endl;
        }
    }
}

void Grafo::agregarNodo(NodoG* nodo)
{   
    if(numNodos==0){
        primero = nodo;
        numNodos++;
    }
    else{    
        NodoG* aux = primero;
        
        for (int i=1; i<numNodos; i++) {
            aux = aux->obtenerSiguiente();
        }

        aux->cambiarSiguiente(nodo);

        numNodos++;
    }
}

void Grafo::eliminarAristasConDestino(string destino)
{
    NodoG* actual = primero;
    for(int i=1; i<numNodos; i++){
        actual->eliminarArista(destino);
        actual = actual->obtenerSiguiente();
    }
}

Grafo::~Grafo()
{
    eliminarNodos();
}

bool Grafo::existeNodo(string ciudad){
    NodoG* aux = primero;
    int i=1;
    if(numNodos > 0){
        while(!(aux->obtenerCiudad() == ciudad) && i < numNodos){
           aux = aux->obtenerSiguiente();
           i++;
        }
    }
    return aux->obtenerCiudad() == ciudad;
}

NodoG* Grafo::obtenerNodo(string ciudad) {
    NodoG* aux;
    if(existeNodo(ciudad)) {
        aux = primero;
        while(!(aux->obtenerCiudad() == ciudad) ){
           aux = aux->obtenerSiguiente();
        }
    }
    return aux;
}