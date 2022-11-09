#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Terminal
{
    string codigo;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidadTerminales;
    int destinosNacionales;
    int destinosInternacionales;
};

class HashTable
{
    int capacidad;
    vector<Terminal> *tabla;

public:
    HashTable(int V);
    void insertar(Terminal terminal);
    void eliminar(string codigo);

    int checkPrime(int n)
    {
        int i;
        if (n == 1 || n == 0)
        {
            return 0;
        }
        for (i = 2; i < n / 2; i++)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }

    int getPrime(int n)
    {
        if (n % 2 == 0)
        {
            n++;
        }
        while (!checkPrime(n))
        {
            n += 2;
        }
        return n;
    }

    int hashFunction(string codigo)
    {
        int posicion = 0;
        int codigoInt = 0;
        for (int i = 0; i < codigo.size(); i++)
        {
            codigoInt += codigo[i];
        }

        posicion = codigoInt % capacidad;

        return posicion;
    }

    void displayHash();
    void buscar(string codigo);
};

HashTable::HashTable(int b)
{
    this->capacidad = getPrime(b);
    tabla = new vector<Terminal>[capacidad];
}

void HashTable::insertar(Terminal terminal)
{
    int i = 1;
    int index = hashFunction(terminal.codigo);
    if (tabla[index].size() == 0)
    {
        tabla[index].push_back(terminal);
    }
    else
    {
        while (tabla[index].size() != 0)
        {
            index = index + i ^ 2;
            i++;
        }
        tabla[index].push_back(terminal);
    }
}

void HashTable::eliminar(string codigo)
{
    int index = hashFunction(codigo);
    int i = 1;
    if (tabla[index].size() == 0)
    {
        cout << "No existe la terminal" << endl;
    }
    else
    {
        while (tabla[index].size() != 0)
        {
            if (tabla[index][0].codigo == codigo)
            {
                tabla[index].erase(tabla[index].begin());
                cout << "Terminal eliminada con exito!" << endl;
            }
            else
            {
                index = index + i ^ 2;
                i++;
            }
        }
    }
}

void HashTable::displayHash()
{
    for (int i = 0; i < capacidad; i++)
    {
        cout << i;
        for (int j = 0; j < tabla[i].size(); j++)
        {
            cout << " --> " << tabla[i][j].codigo;
        }
        cout << endl;
    }
}

void HashTable::buscar(string codigo)
{
    int index = hashFunction(codigo);
    int i = 1;
    if (tabla[index].size() == 0)
    {
        cout << "No existe la terminal" << endl;
    }
    else
    {
        while (tabla[index].size() != 0)
        {
            if (tabla[index][0].codigo == codigo)
            {
                cout << "Codigo: " << tabla[index][0].codigo << endl;
                cout << "Nombre: " << tabla[index][0].nombre << endl;
                cout << "Ciudad: " << tabla[index][0].ciudad << endl;
                cout << "Pais: " << tabla[index][0].pais << endl;
                cout << "Superficie: " << tabla[index][0].superficie << endl;
                cout << "Cantidad de terminales: " << tabla[index][0].cantidadTerminales << endl;
                cout << "Destinos nacionales: " << tabla[index][0].destinosNacionales << endl;
                cout << "Destinos internacionales: " << tabla[index][0].destinosInternacionales << endl;
                break;
            }
            else
            {
                index = index + i ^ 2;
                i++;
            }
        }
    }
}