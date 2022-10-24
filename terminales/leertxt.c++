#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <

/*
Terminales de ómnibus
La información de las terminales estará dada en un archivo de texto terminales.txt que deberá
leerse al iniciar la aplicación.
En cada línea del archivo estará la información de la terminal, separada por espacios:
codigo nombre ciudad pais superficie #cantidad_terminales #destinos_nacionales
#destinos_internacionales

*/

using namespace std;

void lectura(string nombre_archivo);
void escribir(string dato);
void darAltaNuevaTerminal(string codigo, string nombre, string ciudad, string pais, float superficie);
void modificarDatosTerminal(string codigo);
void darBajaTerminal(string codigo);
void mostrarTodasLasTerminales();
void mostrarOpciones();
void ingresarDatosDeNuevaTerminal();

int main()
{
    mostrarOpciones();
    // int opcion;
    // cin >> opcion;
    ingresarDatosDeNuevaTerminal();

    // switch (opcion)
    // {
    // case 1:
    //     mostrarOpciones();
    //     break;
    // case 2:
    // {
    //     char codigo;
    //     string nombre;
    //     string ciudad;
    //     string pais;
    //     float superficie;
    //     cout << "Ingrese el codigo de la terminal: ";
    //     cin >> codigo;
    //     cout << "Ingrese el nombre de la terminal: ";
    //     cin >> nombre;
    //     cout << "Ingrese la ciudad de la terminal: ";
    //     cin >> ciudad;
    //     cout << "Ingrese el pais de la terminal: ";
    //     cin >> pais;
    //     cout << "Ingrese la superficie de la terminal: ";
    //     cin >> superficie;
    //     modificarDatosTerminal(codigo, nombre, ciudad, pais, superficie);
    //     mostrarOpciones();
    //     break;
    // }
    // case 3:
    // {
    //     string codigo;
    //     cout << "Ingrese el codigo de la terminal: ";
    //     cin >> codigo;
    //     darBajaTerminal(codigo);
    //     mostrarOpciones();
    //     break;
    // }
    // case 4:
    // {
    //     mostrarTodasLasTerminales();
    //     mostrarOpciones();
    //     break;
    // }
    // case 5:
    // {
    //     break;
    // }
    // }
    lectura("viajes.txt");

    system("pause");

    return 0;
}

void modificarDatosTerminal(string codigo)
{
    // buscar
}

void ingresarDatosDeNuevaTerminal()
{
    string codigo;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    cout << "Ingrese el codigo de la terminal: ";
    cin >> codigo;
    // verificar Codigo que no sea repetido y formatear todo a UPPERCASE
    cout << "Ingrese el nombre de la terminal: ";
    // verificar que sea solamente una palabra y hacer primer mayuscula y el resto minuscula
    cin >> nombre;
    cout << "Ingrese la ciudad de la terminal: ";
    // verificar que sea solamente una palabra y hacer primer mayuscula y el resto minuscula
    cin >> ciudad;
    cout << "Ingrese el pais de la terminal: ";
    // verificar que sea solamente una palabra y hacer primer mayuscula y el resto minuscula
    cin >> pais;
    cout << "Ingrese la superficie de la terminal: ";
    // verificar que sea un numero float
    cin >> superficie;
    darAltaNuevaTerminal(codigo, nombre, ciudad, pais, superficie);
}

void lectura(string nombre_archivo)
{
    ifstream archivo;
    string texto;

    archivo.open(nombre_archivo, ios::in);

    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (!archivo.eof())
    {
        getline(archivo, texto);
        cout << texto << endl;
    }

    archivo.close();
}

void escribir(string dato)
{
    ofstream archivo;

    archivo.open("viajes.txt", ios::out | ios::app); // Creamos el archivo

    if (archivo.fail())
    { // Si a ocurrido algun error
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    archivo << dato << endl;

    archivo.close(); // Cerramos el archivo
}

void mostrarOpciones()
{
    cout << "Elija una opcion: " << endl;
    cout << "1. Dar de alta una nueva terminal" << endl;
    cout << "2. Modificar datos de una terminal" << endl;
    cout << "3. Dar de baja una terminal" << endl;
    cout << "4. Mostrar todas las terminales" << endl;
    cout << "5. Salir" << endl;
};

void darAltaNuevaTerminal(string codigo, string nombre, string ciudad, string pais, float superficie)
{
    string datos = codigo + " " + nombre + " " + ciudad + " " + pais + " " + std::to_string(superficie);
    escribir(datos);
}
