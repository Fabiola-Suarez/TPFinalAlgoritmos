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
        int i = 0;
        int codigoInt = 0;
        for (int i = 0; i < codigo.size(); i++)
        {
            codigoInt += codigo[i];
        }

        posicion = codigoInt % capacidad;

        while (tabla[posicion].size() != 0)
        {
            posicion = (posicion + i ^ (i + 1)) % capacidad;
            i++;
        }
        i = 0;

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
    int index = hashFunction(terminal.codigo);
    tabla[index].push_back(terminal);
}

void HashTable::eliminar(string codigo)
{
    int index = hashFunction(codigo);
    for (int i = 0; i < tabla[index].size(); i++)
    {
        if (tabla[index][i].codigo == codigo)
        {
            tabla[index].erase(tabla[index].begin() + i);
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
    for (int i = 0; i < tabla[index].size(); i++)
    {
        if (tabla[index][i].codigo == codigo)
        {
            cout << "Codigo: " << tabla[index][i].codigo << endl;
            cout << "Nombre: " << tabla[index][i].nombre << endl;
            cout << "Ciudad: " << tabla[index][i].ciudad << endl;
            cout << "Pais: " << tabla[index][i].pais << endl;
            cout << "Superficie: " << tabla[index][i].superficie << endl;
            cout << "Cantidad de terminales: " << tabla[index][i].cantidadTerminales << endl;
            cout << "Destinos nacionales: " << tabla[index][i].destinosNacionales << endl;
            cout << "Destinos internacionales: " << tabla[index][i].destinosInternacionales << endl;
            cout << endl;
            return;
        }
    }
    cout << "No se encontro la terminal" << endl;
}