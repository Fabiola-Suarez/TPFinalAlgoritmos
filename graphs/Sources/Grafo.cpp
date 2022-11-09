#include "../Headers/Grafo.h"
#include <iostream>
#include <limits.h>

using namespace std;
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

// Encontrar el vértice con mínimo valor de la distancia, del conjunto 
// de vértices aún no visitados en el árbol de la ruta más corta
int Grafo::minimumDist(double peso[], bool visitados[])
{
    
    int min = INF, min_index;

    for (int v = 0; v < numNodos; v++)
        if (visitados[v] == false && peso[v] <= min)
            min = peso[v], min_index = v;

    return min_index;
}

// imprime la matriz de distancia construida
void Grafo::printSolution(double peso[], int parent[], int origen, int destino, int choice)
{
    NodoG *NodoOrigen = obtenerNodoPorPosicion(origen);
    NodoG *NodoDestino = obtenerNodoPorPosicion(destino);
    double res = peso[destino];
    int i = destino;
    string camino = "";
    string ciudadPadre = "";

    if(choice == 1) 
    {
        cout << "La distancia más corta entre " << NodoOrigen->obtenerCiudad() << " y " << NodoDestino->obtenerCiudad() << " es " << int(res) << endl;
    }
    else 
    {
        cout << "La ruta con menor tiempo entre " << NodoOrigen->obtenerCiudad() << " y " << NodoDestino->obtenerCiudad() << " es de " << res << " horas." << endl;
    }
    
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

// Función que implementa el algoritmo Dijkstra
// de ruta más corta para un gráfico representado usando
// representación de la matriz de adyacencia
void Grafo::dijkstra(int src, int destiny, int choice)
{
    // La matriz de salida. dist[i] mantendrá la distancia más corta de src a i
    double peso[MAX_NODES]; 
    
    // sptSet[i] será verdadero si el vértice i se incluye en el árbol de ruta más corto 
    // o se finaliza la distancia más corta desde src a i
    bool sptSet[MAX_NODES]; 

    int parent[MAX_NODES];

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < MAX_NODES; i++)
        peso[i] = INF, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    peso[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < MAX_NODES - 1; count++)
    {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minimumDist(peso, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.

        for (int v = 0; v < MAX_NODES; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && matriz[u][v] && peso[u] != INT_MAX && peso[u] + matriz[u][v] < peso[v])
            {
                peso[v] = peso[u] + matriz[u][v];
                parent[v] = u;
            }
    }

    // imprime la matriz de distancia construida
    printSolution(peso, parent, src, destiny, choice);
}

void Grafo::calcularCaminoMinimo(string origen, string destino, int choice)
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
    dijkstra(indexOrigen, indexDestino, choice);
}