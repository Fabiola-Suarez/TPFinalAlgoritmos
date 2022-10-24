#include "Grafo.cpp"
#include "Arista.cpp"
#include "NodoG.cpp"
#include <windows.h>

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

// int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevIns, LPSTR lpszArgument, int iShow)

void cargarNodos(Grafo *grafo);
void cargarAristas(Grafo *grafo);
void inicializarGrafo(Grafo *grafo);

int main()
{
    Grafo *grafo = new Grafo();
    inicializarGrafo(grafo);
    grafo->verNodos();

    grafo->~Grafo();
    return 0;
}

void inicializarGrafo(Grafo *grafo)
{
    cargarNodos(grafo);
    cargarAristas(grafo);
}

void cargarNodos(Grafo *grafo)
{
    ifstream archivo;
    string linea;
    string cod, nombre, ciudad, pais;
    double superficie;
    int cantidadTerminales, destinosNacionales, destinosInternacionales;

    archivo.open("terminales.txt", ios::in);
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof())
    {
        archivo >> cod >> nombre >> ciudad >> pais >> superficie >> cantidadTerminales >> destinosNacionales >> destinosInternacionales;
        grafo->agregarNodo(new NodoG(cod, ciudad));
    }
    archivo.close();
}

void cargarAristas(Grafo *grafo)
{
    ifstream archivo;
    string linea;
    string codOrigen, codDestino;
    double distancia, horasDeViaje;
    archivo.open("viajes.txt", ios::in);
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!archivo.eof())
    {
        archivo >> codOrigen >> codDestino >> distancia >> horasDeViaje;
        grafo->obtenerNodo(codOrigen)->agregarArista(grafo->obtenerNodo(codDestino), distancia, horasDeViaje);
    }
    archivo.close();
}