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

int main()
{
    HashTable hash(20);

    Terminal terminal1;
    terminal1.codigo = "JUJ";
    terminal1.nombre = "Terminal_de Jujuy";
    terminal1.ciudad = "Argentina";
    terminal1.pais = "10.10";
    terminal1.superficie = 39;
    terminal1.cantidadTerminales = 1;
    terminal1.destinosNacionales = 9;

    Terminal terminal2;
    terminal2.codigo = "SAL";
    terminal2.nombre = "Terminal_de Salta";
    terminal2.ciudad = "Argentina";
    terminal2.pais = "33.19";
    terminal2.superficie = 4;
    terminal2.cantidadTerminales = 10;
    terminal2.destinosNacionales = 36;

    Terminal terminal3;
    terminal3.codigo = "ROS";
    terminal3.nombre = "Terminal_de Rosario";
    terminal3.ciudad = "Argentina";
    terminal3.pais = "19.53";
    terminal3.superficie = 3;
    terminal3.cantidadTerminales = 19;
    terminal3.destinosNacionales = 31;

    Terminal terminal4;
    terminal4.codigo = "CRB";
    terminal4.nombre = "Terminal_de Cordoba";
    terminal4.ciudad = "Argentina";
    terminal4.pais = "24.00";
    terminal4.superficie = 8;
    terminal4.cantidadTerminales = 10;
    terminal4.destinosNacionales = 38;

    Terminal terminal5;
    terminal5.codigo = "BUE";
    terminal5.nombre = "Terminal_de Buenos_Aires";
    terminal5.ciudad = "Argentina";
    terminal5.pais = "37.82";
    terminal5.superficie = 10;
    terminal5.cantidadTerminales = 37;
    terminal5.destinosNacionales = 28;

    Terminal terminal6;
    terminal6.codigo = "COR";
    terminal6.nombre = "Terminal_de Corrientes";
    terminal6.ciudad = "Argentina";
    terminal6.pais = "14.16";
    terminal6.superficie = 9;
    terminal6.cantidadTerminales = 87;
    terminal6.destinosNacionales = 69;

    Terminal terminal7;
    terminal7.codigo = "SNT";
    terminal7.nombre = "Terminal_de Santa_Cruz";
    terminal7.ciudad = "Argentina";
    terminal7.pais = "43.3";
    terminal7.superficie = 19;
    terminal7.cantidadTerminales = 3;
    terminal7.destinosNacionales = 9;

    Terminal terminal8;
    terminal8.codigo = "MIS";
    terminal8.nombre = "Terminal_de Misiones";
    terminal8.ciudad = "Argentina";
    terminal8.pais = "38.73";
    terminal8.superficie = 10;
    terminal8.cantidadTerminales = 3;
    terminal8.destinosNacionales = 19;

    Terminal terminal9;
    terminal9.codigo = "USU";
    terminal9.nombre = "Terminal_de Usuahia";
    terminal9.ciudad = "Argentina";
    terminal9.pais = "91.83";
    terminal9.superficie = 9;
    terminal9.cantidadTerminales = 38;
    terminal9.destinosNacionales = 20;

    hash.insertar(terminal1);
    hash.insertar(terminal2);
    hash.insertar(terminal3);
    hash.insertar(terminal4);
    hash.insertar(terminal5);
    hash.insertar(terminal6);
    hash.insertar(terminal7);
    hash.insertar(terminal8);
    hash.insertar(terminal9);
    hash.displayHash();
    hash.eliminar("SNT");
    hash.displayHash();
    return 0;
}