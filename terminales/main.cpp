#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#include "hash.cpp"

// mostrar opciones
void mostrarOpciones();

// Inicializar tabla hash a partir de la clase HashTable
HashTable tablaHash(30);

// Dar de alta una terminal agregandola a la tabla hash y a terminales.txt
void darDeAltaTerminal()
{
    Terminal terminal;
    cout << "Ingrese el codigo de la terminal: ";
    cin >> terminal.codigo;
    // codigo en uppercase
    for (int i = 0; i < terminal.codigo.length(); i++)
    {
        terminal.codigo[i] = toupper(terminal.codigo[i]);
    }
    cout << "Ingrese el nombre de la terminal: ";
    cin >> terminal.nombre;
    cout << "Ingrese la ciudad de la terminal: ";
    cin >> terminal.ciudad;
    cout << "Ingrese el pais de la terminal: ";
    cin >> terminal.pais;
    cout << "Ingrese la superficie de la terminal: ";
    cin >> terminal.superficie;
    cout << "Ingrese la cantidad de terminales de la terminal: ";
    cin >> terminal.cantidadTerminales;
    cout << "Ingrese la cantidad de destinos nacionales de la terminal: ";
    cin >> terminal.destinosNacionales;
    cout << "Ingrese la cantidad de destinos internacionales de la terminal: ";
    cin >> terminal.destinosInternacionales;
    cout << endl;

    // agregar terminal a la tabla hash
    tablaHash.insertar(terminal);

    // agregar terminal a terminales.txt
    ofstream terminalesFile;
    terminalesFile.open("terminales.txt", ios::app);
    terminalesFile << terminal.codigo << " " << terminal.nombre << " " << terminal.ciudad << " " << terminal.pais << " " << terminal.superficie << " " << terminal.cantidadTerminales << " " << terminal.destinosNacionales << " " << terminal.destinosInternacionales << endl;
    terminalesFile.close();

    mostrarOpciones();
}

// Mostrar todas las terminales
void mostrarTerminales()
{
    tablaHash.displayHash();
    mostrarOpciones();
}

// Mostrar una terminal a partir de su codigo
void mostrarTerminal()
{
    string codigo;
    cout << "Ingrese el codigo de la terminal: ";
    cin >> codigo;
    // codigo en uppercase
    for (int i = 0; i < codigo.length(); i++)
    {
        codigo[i] = toupper(codigo[i]);
    }
    tablaHash.buscar(codigo);
    mostrarOpciones();
}

// Eliminar una terminal a partir de su codigo
void eliminarTerminal()
{
    string codigo;
    cout << "Ingrese el codigo de la terminal: ";
    cin >> codigo;
    // codigo en uppercase
    for (int i = 0; i < codigo.length(); i++)
    {
        codigo[i] = toupper(codigo[i]);
    }
    tablaHash.eliminar(codigo);
    // eliminar terminal de terminales.txt
    ifstream terminalesFile;
    terminalesFile.open("terminales.txt");
    string line;
    string codigoTerminal;
    string nombreTerminal;
    string ciudadTerminal;
    string paisTerminal;
    float superficieTerminal;
    int cantidadTerminalesTerminal;
    int destinosNacionalesTerminal;
    int destinosInternacionalesTerminal;
    vector<Terminal> terminales;
    while (getline(terminalesFile, line))
    {
        stringstream ss(line);
        ss >> codigoTerminal >> nombreTerminal >> ciudadTerminal >> paisTerminal >> superficieTerminal >> cantidadTerminalesTerminal >> destinosNacionalesTerminal >> destinosInternacionalesTerminal;
        if (codigoTerminal != codigo)
        {
            Terminal terminal;
            terminal.codigo = codigoTerminal;
            terminal.nombre = nombreTerminal;
            terminal.ciudad = ciudadTerminal;
            terminal.pais = paisTerminal;
            terminal.superficie = superficieTerminal;
            terminal.cantidadTerminales = cantidadTerminalesTerminal;
            terminal.destinosNacionales = destinosNacionalesTerminal;
            terminal.destinosInternacionales = destinosInternacionalesTerminal;
            terminales.push_back(terminal);
        }
    }
    terminalesFile.close();
    ofstream terminalesFile2;
    terminalesFile2.open("terminales.txt");
    for (int i = 0; i < terminales.size(); i++)
    {
        terminalesFile2 << terminales[i].codigo << " " << terminales[i].nombre << " " << terminales[i].ciudad << " " << terminales[i].pais << " " << terminales[i].superficie << " " << terminales[i].cantidadTerminales << " " << terminales[i].destinosNacionales << " " << terminales[i].destinosInternacionales << endl;
    }
    terminalesFile2.close();

    mostrarOpciones();
}

// Mostrar opciones de menu con switch
void mostrarOpciones()
{
    int opcion;
    cout << "1. Dar de alta una terminal" << endl;
    cout << "2. Mostrar todas las terminales" << endl;
    cout << "3. Mostrar una terminal" << endl;
    cout << "4. Eliminar una terminal" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    cout << endl;
    switch (opcion)
    {
    case 1:
        darDeAltaTerminal();
        break;
    case 2:
        mostrarTerminales();
        break;
    case 3:
        mostrarTerminal();
        break;
    case 4:
        eliminarTerminal();
        break;
    case 5:
        exit(0);
        break;
    default:
        cout << "Opcion invalida" << endl;
        mostrarOpciones();
        break;
    }
}

int main()
{
    // Leer terminales.txt y agregarlas a la tabla hash
    ifstream terminalesFile;
    terminalesFile.open("terminales.txt");
    string line;
    while (getline(terminalesFile, line))
    {
        Terminal terminal;
        istringstream iss(line);
        iss >> terminal.codigo >> terminal.nombre >> terminal.ciudad >> terminal.pais >> terminal.superficie >> terminal.cantidadTerminales >> terminal.destinosNacionales >> terminal.destinosInternacionales;
        tablaHash.insertar(terminal);
    }
    terminalesFile.close();
    mostrarOpciones();
    tablaHash->~HashTable();
    return 0;
}