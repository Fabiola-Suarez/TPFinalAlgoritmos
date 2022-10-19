#include "Grafo.cpp"
#include "Arista.cpp"
#include "NodoG.cpp"
#include <windows.h>

//int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevIns, LPSTR lpszArgument, int iShow)
int main()
{

    NodoG* bsas = new NodoG("Buenos Aires");
    NodoG* cord = new NodoG("Cordoba");
    NodoG* ros = new NodoG("Rosario");
    
    bsas->agregarArista(bsas, cord, 1200);
    bsas->agregarArista(bsas, ros, 3000);

    ros->agregarArista(ros, bsas,3000);
    
    Grafo* grafo;

    grafo->cambiarPrimero(bsas);
    grafo->agregarNodo(cord);
    grafo->agregarNodo(ros);
    grafo->verNodos();
    
    grafo->eliminarNodos();
    return 0;
}