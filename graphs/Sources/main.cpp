#include "Grafo.cpp"
#include "Arista.cpp"
#include "NodoG.cpp"
#include <windows.h>

//int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevIns, LPSTR lpszArgument, int iShow)
int main()
{

    NodoG* bsas = new NodoG("BSAS", "Buenos Aires");
    NodoG* cord = new NodoG("COR" ,"Cordoba");
    NodoG* ros = new NodoG("ROS", "Rosario");
    
    bsas->agregarArista(cord, 1200, 1.2);
    bsas->agregarArista(ros, 3000, 2.4);

    ros->agregarArista(bsas,3000, 3.2);

    cord->agregarArista(ros, 200, 2.1);
    
    Grafo* grafo = new Grafo();

    grafo->agregarNodo(bsas);
    grafo->agregarNodo(cord);
    grafo->agregarNodo(ros);
    grafo->verNodos();

    cout << grafo->existeNodo("Buenos Aires") << endl;

    //cout << grafo->obtenerNodo("Misiones")->obtenerCiudad() << endl;

    cout << bsas->existeArista("MIS")<<endl;

    grafo->~Grafo();
    return 0;
}