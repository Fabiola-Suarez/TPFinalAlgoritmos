#include "../Headers/Grafo.h"
#define MAX_NODES 100
#define INF 99999999

Grafo::Grafo()
{
    numNodos = 0;
    // crear la matriz
}

NodoG *Grafo::obtenerPrimero()
{
    return primero;
}

void Grafo::cambiarPrimero(NodoG *nuevoPrimero)
{
    primero = nuevoPrimero;
}

void Grafo::verNodos()
{
    NodoG *aux = primero;
    for (int i = 1; i <= numNodos; i++)
    {
        aux->verDatos();
        if (!(i == numNodos))
        {
            aux = aux->obtenerSiguiente();
        }
    }
}

void Grafo::eliminarNodos()
{
    while (numNodos > 0)
    {
        NodoG *borrar = primero;
        NodoG *aux;
        if (numNodos > 1)
        {
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
    if (primero->obtenerCiudad() == ciudad)
    {
        NodoG *borrar = primero;
        primero = borrar->obtenerSiguiente();
        borrar->eliminarAristas();
        eliminarAristasConDestino(ciudad);
        delete borrar;
        numNodos--;
        cout << "Se eliminó el nodo que representaba a " << ciudad << endl;
    }
    else
    {
        if (numNodos > 1)
        {
            NodoG *anterior = primero;

            for (int i = 1; i < numNodos; i++)
            {
                NodoG *actual = anterior->obtenerSiguiente();

                if (actual->obtenerCiudad() == ciudad)
                {
                    anterior->cambiarSiguiente(actual->obtenerSiguiente());
                    actual->eliminarAristas();
                    eliminarAristasConDestino(ciudad);
                    delete actual;
                    numNodos--;
                    cout << "Se eliminó el nodo que representaba a " << ciudad << endl;
                }
                else
                {
                    cout << "No se encontró el nodo que representa a " << ciudad << endl;
                    anterior = anterior->obtenerSiguiente();
                }
            }
        }
        else
        {
            cout << "No se encontró el nodo que representa a " << ciudad << endl;
        }
    }
}

void Grafo::agregarNodo(NodoG *nodo)
{

    if (numNodos == 0)
    {
        primero = nodo;
        numNodos++;
    }
    else
    {
        if (!existeNodo(nodo->obtenerKey()))
        {
            NodoG *aux = primero;

            for (int i = 1; i < numNodos; i++)
            {
                aux = aux->obtenerSiguiente();
            }
            aux->cambiarSiguiente(nodo);
            numNodos++;
        }
    }
}

void Grafo::eliminarAristasConDestino(string destino)
{
    NodoG *actual = primero;
    for (int i = 1; i < numNodos; i++)
    {
        actual->eliminarArista(destino);
        actual = actual->obtenerSiguiente();
    }
}

Grafo::~Grafo()
{
    eliminarNodos();
}

bool Grafo::existeNodo(string clave)
{
    NodoG *aux = primero;
    int i = 1;
    if (numNodos > 0)
    {
        while (!(aux->obtenerKey() == clave) && i < numNodos)
        {
            aux = aux->obtenerSiguiente();
            i++;
        }
    }
    return aux->obtenerKey() == clave;
}

NodoG *Grafo::obtenerNodo(string clave)
{
    NodoG *aux;
    if (existeNodo(clave))
    {
        aux = primero;
        while (!(aux->obtenerKey() == clave))
        {
            aux = aux->obtenerSiguiente();
        }
    }
    return aux;
}

NodoG *Grafo::obtenerNodoPorPosicion(int pos)
{
    NodoG *aux = primero;
    for (int i = 0; i < pos; i++)
    {
        aux = aux->obtenerSiguiente();
    }
    return aux;
}

void Grafo::InicializarMatriz()
{
    for (int i = 0; i < numNodos; i++)
    {
        for (int j = 0; j < numNodos; j++)
        {
            matriz[i][j] = INF;
        }
    }
}

void Grafo::cargarMatrizConAristas(int opcion)
{
    NodoG *aux = primero;
    for (int i = 1; i <= numNodos; i++)
    {
        cout << "Cargando aristas del nodo " << aux->obtenerCiudad() << endl;

        aux->cargarMatrizConAristas(matriz, opcion);
        if (!(i == numNodos))
        {
            aux = aux->obtenerSiguiente();
        }
    }
}

void Grafo::verMatriz()
{
    for (int i = 0; i < numNodos; i++)
    {
        for (int j = 0; j < numNodos; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include <iostream>
using namespace std;
#include <limits.h>

// Number of vertices in the graph

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int Grafo::minimumDist(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INF, min_index;

    for (int v = 0; v < numNodos; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void Grafo::printSolution(int dist[], int parent[], int origen, int destino)
{
    NodoG *NodoOrigen = obtenerNodoPorPosicion(origen);
    NodoG *NodoDestino = obtenerNodoPorPosicion(destino);
    int res = dist[destino];
    int i = destino;
    string camino = "";
    string ciudadPadre = "";

    cout << "La distancia más corta entre " << NodoOrigen->obtenerCiudad() << " y " << NodoDestino->obtenerCiudad() << " es " << res << endl;
    cout << "El camino más corto es: " << endl;
    cout << NodoDestino->obtenerCiudad();

    if (res != INF && res != 0)
    {
        while (parent[i] != origen)
        {
            ciudadPadre = obtenerNodoPorPosicion(parent[i])->obtenerCiudad();
            camino = camino + " <- " + ciudadPadre;
            i = parent[i];
        }
        camino = camino + " <- " + NodoOrigen->obtenerCiudad();
        cout << camino << endl;
    }
    else
    {
        cout << "No existe camino entre " << NodoOrigen->obtenerCiudad() << " y " << NodoDestino->obtenerCiudad() << endl;
    }
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void Grafo::dijkstra(int src, int destiny)
{
    int dist[MAX_NODES]; // The output array.  dist[i] will hold the
                         // shortest
    // distance from src to i

    bool sptSet[MAX_NODES]; // sptSet[i] will be true if vertex i is
                            // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    int parent[MAX_NODES];

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < MAX_NODES; i++)
        dist[i] = INF, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < MAX_NODES - 1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minimumDist(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.

        for (int v = 0; v < MAX_NODES; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && matriz[u][v] && dist[u] != INT_MAX && dist[u] + matriz[u][v] < dist[v])
            {
                dist[v] = dist[u] + matriz[u][v];
                parent[v] = u;
            }
    }

    // print the constructed distance array
    printSolution(dist, parent, src, destiny);
}

void Grafo::calcularCaminoMinimo(string origen, string destino)
{
    // origen a MAYUSCULAS
    for (int i = 0; i < origen.length(); i++)
    {
        origen[i] = toupper(origen[i]);
    }

    for (int i = 0; i < destino.length(); i++)
    {
        destino[i] = toupper(destino[i]);
    }

    int indexOrigen = obtenerNodo(origen)->obtenerIndice();
    int indexDestino = obtenerNodo(destino)->obtenerIndice();
    dijkstra(indexOrigen, indexDestino);
}