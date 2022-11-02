#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "NodoG.h"

#define MAX_NODES 100

class Grafo
{
private:
    NodoG *primero;                   // Puntero al primer nodo del grafo
    int numNodos;                     // Cantidad de nodos que contiene el grafo
    int matriz[MAX_NODES][MAX_NODES]; // Matriz de adyacencia
public:
    // Constructor
    Grafo();

    // Retorna el valor del atributo primero
    NodoG *obtenerPrimero();

    // Cambia el valor del atributo primero
    void cambiarPrimero(NodoG *nodo);

    // Hace un print por consola de los nodos y sus datos
    // que contiene el grafo.
    // PRE: Debe haber al menos un nodo.
    void verNodos();

    // Elimina todos los nodos y sus aristas del grafo.
    void eliminarNodos();

    // Elimina del grado el nodo correspondiente con ciudad.
    void eliminarNodo(string ciudad);

    // Agrega un nodo al grafo
    void agregarNodo(NodoG *nodo);

    // Elimina del grafo todas las aristas con el destino indicado.
    void eliminarAristasConDestino(string destino);

    // Libera la memoria
    virtual ~Grafo();

    // Retorna si existe en el grafo el nodo correspondiente a la ciudad.
    bool existeNodo(string clave);

    // Devuelve el nodo correspondiente a la ciudad
    NodoG *obtenerNodo(string clave);

    // Retorna la cantidad de nodos que contiene el grafo
    int obtenerNumNodos();

    // Retorna el nodo correspondiente a la ciudad
    void InicializarMatriz();

    // Retorna el nodo correspondiente a la ciudad
    void cargarMatrizConAristas(int opcion);

    void verMatriz();

    void calcularCaminoMinimo(string origen, string destino);

    void printSolution(int dist[], int parent[], int origen, int destino);

    void dijkstra(int src, int destiny);

    int minimumDist(int dist[], bool sptSet[]);

    NodoG *obtenerNodoPorPosicion(int pos);
};

#endif // GRAFO_H_INCLUDED