#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
#include "Arista.h"
using namespace std;

class Arista;
class NodoG
{
private:
    string key;                  // codigo que identifica la ciudad
    string ciudad;               // Dato que almacena el nodo
    NodoG *siguiente;            // Puntero al nodo siguiente
    Arista *aristaCabeza = NULL; // Puntero a la primera arista del nodo
    int numAristas = 0;          // Cantidad de aristas que contiene este nodo
    int indice;                  // Indice para recorrer la matriz de adyacencia
public:
    // Constructores
    NodoG();
    NodoG(string clave, string nombreCiudad, int indices);

    // Retorna el valor del atributo key
    string obtenerKey();

    // Retorna el valor del atributo ciudad
    string obtenerCiudad();

    // Cambia el valor del atributo ciudad
    void cambiarCiudad(string ciudad);

    // Retorna el puntero a la primera arista del nodo
    Arista *obtenerAristas();

    // Hace un print de los datos del nodo:
    // la ciudad que representa y hacia donde llevan sus aristas
    // y su distancia.
    void verDatos();

    // Retorna el puntero al siguiente nodo
    NodoG *obtenerSiguiente();

    // Cambia el puntero al siguiente nodo
    void cambiarSiguiente(NodoG *);

    // Crea una nueva arista y la agrega a la lista de aristas del nodo
    void agregarArista(NodoG *nodoDestino, double distancia, double horasDeViaje);

    // Elimina todas las aristas pertenecientes al nodo
    void eliminarAristas();

    // Elimina del nodo la arista que lo conecte con ciudadDestino
    void eliminarArista(string ciudadDestino);

    // Retorna si existe o no la arista en el nodo
    bool existeArista(string claveCiudadDestino);

    int obtenerIndice();

    void cambiarIndice(int indice);

    Arista *obtenerAristaCabeza();

    void cargarMatrizConAristas(int matriz[][100], int choice);
};

#endif // NODE_H_INCLUDED