#include "../Headers/NodoG.h"
#include <iostream>

NodoG::NodoG(string clave, string nombreCiudad, int indices)
{
    key = clave;
    ciudad = nombreCiudad;
    indice = indices;
}

string NodoG::obtenerKey()
{
    return key;
}

string NodoG::obtenerCiudad()
{
    return ciudad;
}

void NodoG::cambiarCiudad(string nombreCiudad)
{
    ciudad = nombreCiudad;
}

void NodoG::verDatos()
{
    cout << ">>> Nodo: " << ciudad << endl;
    if (numAristas > 0)
    {
        Arista arista = *(aristaCabeza);
        for (int i = 0; i < numAristas; i++)
        {
            cout << "       -> " << arista.obtenerDestino()->obtenerCiudad() << " | Distancia = " << arista.obtenerDistancia() << ", Horas = " << arista.obtenerHoras() << endl;
            if (i < numAristas - 1)
            {
                arista = *(arista.obtenerSiguiente());
            }
        }
    }
    else
    {
        cout << "    Aristas: -" << endl;
    }
}

NodoG *NodoG::obtenerSiguiente()
{
    return siguiente;
}

void NodoG::cambiarSiguiente(NodoG *nodo)
{
    siguiente = nodo;
}

void NodoG::agregarArista(NodoG *nodoDestino, double distancia, double horasDeViaje)
{
    if (!existeArista(nodoDestino->obtenerKey()))
    {
        if (numAristas == 0)
        {
            aristaCabeza = new Arista(nodoDestino, distancia, horasDeViaje);
        }
        else
        {
            Arista *nueva = new Arista(nodoDestino, distancia, horasDeViaje);
            Arista *aux = aristaCabeza;

            for (int i = 1; i < numAristas; i++)
            {
                aux = aux->obtenerSiguiente();
            }

            aux->cambiarSiguiente(nueva);
        }
        numAristas++;
    }
}

int NodoG::obtenerIndice()
{
    return indice;
}

void NodoG::cambiarIndice(int i)
{
    indice = i;
}

void NodoG::eliminarAristas()
{
    while (numAristas > 0)
    {
        Arista *borrar = aristaCabeza;
        Arista *aux;
        if (numAristas > 1)
        {
            aux = aristaCabeza->obtenerSiguiente();
            aristaCabeza = aux;
        }
        delete borrar;
        numAristas--;
    }
}

void NodoG::eliminarArista(string ciudadDestino)
{
    if (numAristas > 0)
    {
        if (aristaCabeza->obtenerDestino()->obtenerCiudad() == ciudadDestino)
        {
            Arista *borrar = aristaCabeza;
            if (numAristas > 1)
            {
                aristaCabeza = borrar->obtenerSiguiente();
            }
            delete borrar;
            numAristas--;
            cout << "Se elimino la arista con destino " << ciudadDestino << endl;
        }
        else
        {
            if (numAristas > 1)
            {
                Arista *anterior = aristaCabeza;
                for (int i = 1; i < numAristas; i++)
                {
                    Arista *actual = anterior->obtenerSiguiente();

                    if (actual->obtenerDestino()->obtenerCiudad() == ciudadDestino)
                    {
                        anterior->cambiarSiguiente(actual->obtenerSiguiente());
                        delete actual;
                        numAristas--;
                        cout << "Se elimino la arista con destino " << ciudadDestino << endl;
                    }
                }
            }
        }
    }
}

bool NodoG::existeArista(string claveCiudadDestino)
{
    Arista *aux;
    bool resultado;
    if (numAristas > 0)
    {
        aux = aristaCabeza;
        int i = 1;
        while (!(aux->obtenerDestino()->obtenerKey() == claveCiudadDestino) && i < numAristas)
        {
            aux = aux->obtenerSiguiente();
            i++;
        }
        resultado = aux->obtenerDestino()->obtenerKey() == claveCiudadDestino;
    }
    return resultado;
}

Arista *NodoG::obtenerAristaCabeza()
{
    return aristaCabeza;
}

void NodoG::cargarMatrizConAristas(double matriz[][100], int choice)
{
    Arista *aux = aristaCabeza;
    int contador = 0;
    // valor de posicion en memoria aux no es nulo
    while (numAristas > contador)
    {
        int indiceOrigen = indice;
        int indiceDestino = aux->obtenerDestino()->obtenerIndice();
        if (choice == 1)
        {
            matriz[indiceOrigen][indiceDestino] = aux->obtenerDistancia();
        }
        else
        {
            matriz[indiceOrigen][indiceDestino] = aux->obtenerHoras();
        }
        cout << "   -> " << indiceOrigen << " - " << indiceDestino << " = " << matriz[indiceOrigen][indiceDestino] << endl;
        aux = aux->obtenerSiguiente();
        contador++;
    }
}