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
        cout << "Se eliminĂ³ el nodo que representaba a " << ciudad << endl;
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
                    cout << "Se eliminĂ³ el nodo que representaba a " << ciudad << endl;
                }
                else
                {
                    cout << "No se encontrĂ³ el nodo que representa a " << ciudad << endl;
                    anterior = anterior->obtenerSiguiente();
                }
            }
        }
        else
        {
            cout << "No se encontrĂ³ el nodo que representa a " << ciudad << endl;
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

// Encontrar el vĂ©rtice con mĂ­nimo valor de la distancia, del conjunto
// de vĂ©rtices aĂºn no visitados en el Ă¡rbol de la ruta mĂ¡s corta
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

    if (choice == 1)
    {
        cout << "La distancia mĂ¡s corta entre " << NodoOrigen->obtenerCiudad() << " y " << NodoDestino->obtenerCiudad() << " es " << int(res) << endl;
    }
    else
    {
        cout << "La ruta con menor tiempo entre " << NodoOrigen->obtenerCiudad() << " y " << NodoDestino->obtenerCiudad() << " es de " << res << " horas." << endl;
    }

    cout << "El camino mĂ¡s corto es: " << endl;
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

// FunciĂ³n que implementa el algoritmo Dijkstra
// de ruta mĂ¡s corta para un grĂ¡fico representado usando
// representaciĂ³n de la matriz de adyacencia
void Grafo::dijkstra(int src, int destiny, int choice)
{
    // La matriz de salida dist[i] mantendrĂ¡ la distancia mĂ¡s corta de src a i
    double peso[MAX_NODES]; 

    // sptSet[i] serĂ¡ verdadero si el vĂ©rtice i se incluye en el Ă¡rbol de rutas mĂ¡s cortas
    // o se finaliza la distancia mĂ¡s corta desde src hasta i
    bool sptSet[MAX_NODES]; 

    int parent[MAX_NODES];

    // Inicializa todas las distancias como INFINITE y stpSet [] como false
    for (int i = 0; i < MAX_NODES; i++)
        peso[i] = INF, sptSet[i] = false;

    // Distancia del origen a si mismo sera 0
    peso[src] = 0;

    // Buscar el camino mĂ¡s corto para todos los vĂ©rtices
    for (int count = 0; count < MAX_NODES - 1; count++)
    {
        // Seleccionar el vertice con la distancia mĂ­nima del
        // conjunto de vĂ©rtices aĂºn no procesados.
        // u es siempre igual a src en la primera iteraciĂ³n.
        int u = minimumDist(peso, sptSet);

        // Marcar el vĂ©rtice seleccionado como procesado
        sptSet[u] = true;

        // Actualizar el valor de dist de los vĂ©rtices adyacentes
        // del vĂ©rtice seleccionado.

        for (int v = 0; v < MAX_NODES; v++)

            //Actualiza el valor del peso[u] solo si no esta en sptSet, un arista desde u a v, 
            //y el peso total de ruta desde src a v a traves de u es menor que el valor actual de peso[v]
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