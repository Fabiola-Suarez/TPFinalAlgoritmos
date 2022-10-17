#include "Grafo.cpp"
#include "Arista.cpp"
#include "NodoG.cpp"

using namespace std;

int main()
{
    Grafo *grafo = new Grafo();
    NodoG *bsas = new NodoG("Buenos Aires", 2);
    NodoG *cord = new NodoG("Cordoba", 3);
    NodoG *ros = new NodoG("Rosario", 3);

    bsas->agregarArista(bsas, cord, 1200);
    bsas->agregarArista(bsas, ros, 3000);

    Grafo *grafo = new Grafo(bsas);

    grafo->cambiarPrimero(bsas);
    grafo->verNodos();

    return 0;
}