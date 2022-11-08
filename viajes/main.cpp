#include "../graphs/Sources/Grafo.cpp"
#include "../graphs/Sources/Arista.cpp"
#include "../graphs/Sources/NodoG.cpp"
#include <windows.h>

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>

// int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevIns, LPSTR lpszArgument, int iShow)

void cargarNodos(Grafo *grafo);
void cargarAristas(Grafo *grafo);
void inicializarGrafo(Grafo *grafo);
void calcularCaminoMinimo(Grafo *grafo);
void mostrarMenuPrincipal();

int main()
{
  int opcion;
  Grafo *grafo = new Grafo();
  inicializarGrafo(grafo);

  do
  {
    mostrarMenuPrincipal();
    cin >> opcion;
    switch (opcion)
    {
    case 1:
      grafo->verNodos();
      break;
    case 2:
      calcularCaminoMinimo(grafo);
      break;
    case 0:
      cout << "Saliendo del programa..." << endl;
      break;
    default:
      cout << "Numero incorrecto, intente de nuevo por favor";
      break;
    }
  } while (opcion != 0);

  grafo->~Grafo();
  return 0;
}

void inicializarGrafo(Grafo *grafo)
{
  cargarNodos(grafo);
  cargarAristas(grafo);
}

int reiniciarGrafo(Grafo *grafo)
{
  int opcion;
  cout << "Cargar Grafo de aristas segun..." << endl;
  cout << "1. Distancia" << endl;
  cout << "2. Tiempo" << endl;
  cin >> opcion;
  grafo->InicializarMatriz();
  grafo->cargarMatrizConAristas(opcion);
  return opcion;
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
  int i = 0;
  while (!archivo.eof())
  {
    archivo >> cod >> nombre >> ciudad >> pais >> superficie >> cantidadTerminales >> destinosNacionales >> destinosInternacionales;
    grafo->agregarNodo(new NodoG(cod, ciudad, i));
    i++;
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

void mostrarMenuPrincipal()
{
  cout << ' ' << endl;
  cout << "1. Mostrar todos los nodos del grafo" << endl;
  cout << "2. Mostrar Recorrido minimo de un nodo a otro" << endl;
  cout << "0. Salir" << endl;
  cout << ' ' << endl;
}

void calcularCaminoMinimo(Grafo *grafo)
{
  string origen, destino;
  cout << "Ingrese el codigo del nodo origen: ";
  cin >> origen;
  cout << "Ingrese el codigo del nodo destino: ";
  cin >> destino;
  int choice = reiniciarGrafo(grafo);
  grafo->calcularCaminoMinimo(origen, destino, choice);
}