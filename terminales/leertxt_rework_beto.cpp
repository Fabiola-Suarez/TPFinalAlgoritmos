/*
El trabajo práctico consiste en realizar una aplicación para el manejo de terminales de ómnibus.
Terminales de ómnibus
La información de las terminales estará dada en un archivo de texto terminales.txt que deberá
leerse al iniciar la aplicación.
En cada línea del archivo estará la información de la terminal, separada por espacios:
codigo nombre ciudad pais superficie #cantidad_terminales #destinos_nacionales
#destinos_internacionales
El código son tres letras que identifica a cada terminal. Por ejemplo, RET es la terminal de
Retiro, COR es la teminal de Córdoba capital.
La superficie es un número flotante que indica los km2. Los últimos tres datos son números
enteros con las cantidades correspondientes.
Ejemplo:
RET Terminal de Retiro Argentina 34.75 4 12 46
COR Terminal de Córdoba Argentina 14 9 87 69
Se debe mostrar un menú en el cual se pueda:
- consultar por una terminal en particular
- dar de alta una nueva terminal
- dar de baja a alguna
- mostrar todas las terminales (ordenados por los distintos datos)
Consideraciones
- El archivo está bien formado.
- La implementación debe utilizar una tabla de hashing.
- La función de hashing a utilizar debe lograr una buena dispersión.

Viajes
A partir de la lectura de un archivo de texto viajes.txt, que deberá hacerse inmediatamente
después de leer el archivo terminales.txt, se generará un grafo pesado dirigido.
En cada línea estará la información de cada viaje, separada por espacios:
codigo_partida código_destino costo_viaje horas_viaje
El costo del viaje es un entero que representa el costo en pesos y las horas de viaje será un
flotante.
Ejemplo:
RET COR 22483 7.31
USU SAL 222205 46
RET ROS 14736 3.25
...
La aplicación debe pedir al usuario el ingreso de los códigos de partida y de destino, y debe
buscar la combinación de viajes más económica o de menor tiempo. El usuario debe poder
elegir si el camino mínimo está representado por el costo del viaje o por la duración.
Se debe imprimir el detalle del viaje, el costo de cada tramo (o el tiempo de viaje) y el total del
viaje. Si hubiera más de una combinación óptima, deberá listarlas todas. Puede suceder que no
haya ninguna combinación, en ese caso se informa que no hay conexiones posibles.
Consideraciones
- El archivo está bien formado.
- La implementación puede ser recursiva o iterativa.

Tener en cuenta
- Funcionalidad
- Interfaz con el usuario
- Nombres de métodos y atributos
- Modularización
- Buenas prácticas de programación
- Diseño UML
Nota: la aplicación debe estar completamente orientada a objetos, y el lenguaje utilizado debe
ser C++. Debe hacerse correcto uso de la memoria dinámica.
Entrega
Semanalmente cada equipo deberá realizar una exposición del avance del proyecto.
La entrega final del trabajo será en horario de clases, momento en el que se hará la defensa de
este. Por defensa se entiende la muestra del trabajo junto con una explicación por parte de
cada uno de los integrantes.
*/

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

struct Viaje
{
    string codigoPartida;
    string codigoDestino;
    int costoViaje;
    float horasViaje;
};

struct Hash
{
    vector<Terminal> terminales;
    vector<Viaje> viajes;
};

void mostrarOpciones();

void consultarTerminal(vector<Terminal> terminales)
{
    string codigo;
    cout << "Ingrese el codigo de la terminal: ";
    cin >> codigo;
    // codigo en uppercase
    for (int i = 0; i < codigo.length(); i++)
    {
        codigo[i] = toupper(codigo[i]);
    }

    for (int i = 0; i < terminales.size(); i++)
    {
        if (terminales[i].codigo == codigo)
        {
            cout << "Codigo: " << terminales[i].codigo << endl;
            cout << "Nombre: " << terminales[i].nombre << endl;
            cout << "Ciudad: " << terminales[i].ciudad << endl;
            cout << "Pais: " << terminales[i].pais << endl;
            cout << "Superficie: " << terminales[i].superficie << endl;
            cout << "Cantidad de terminales: " << terminales[i].cantidadTerminales << endl;
            cout << "Destinos nacionales: " << terminales[i].destinosNacionales << endl;
            cout << "Destinos internacionales: " << terminales[i].destinosInternacionales << endl;
            cout << endl;
            return;
        }
    }
    cout << "No se encontro la terminal" << endl;
    cout << endl;
}

void mostrarOpciones()
{
    cout << "Elija una opcion: " << endl;
    cout << "1. Consultar terminal" << endl;
    cout << "2. Dar de alta una terminal" << endl;
    cout << "3. Dar de baja una terminal" << endl;
    cout << "4. Mostrar todas las terminales" << endl;
    cout << "5. Salir" << endl;
    cout << endl;
};

void darAltaTerminal(vector<Terminal> terminales)
{
    // deberia agregar la terminal al archivo terminales.txt
    // y luego llamar a la funcion ejecutarOpciones
    // para que se vuelva a mostrar el menu
    string codigo;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidadTerminales;
    int destinosNacionales;
    int destinosInternacionales;
    cout << "Ingrese el codigo de la terminal: ";
    cin >> codigo;
    // existe ese codigo?
    for (int i = 0; i < terminales.size(); i++)
    {
        if (terminales[i].codigo == codigo)
        {
            cout << "Ya existe una terminal con ese codigo" << endl;
            return;
        }
    }
    cout << "Ingrese el nombre de la terminal: ";
    cin >> nombre;
    cout << "Ingrese la ciudad de la terminal: ";
    cin >> ciudad;
    cout << "Ingrese el pais de la terminal: ";
    cin >> pais;
    cout << "Ingrese la superficie de la terminal: ";
    cin >> superficie;
    // calcular cantidadTerminales en ciudad
    // calcular destinosNacionales en ciudad
    // calcular destinosInternacionales a ciudad

    Terminal terminal;
    terminal.codigo = codigo;
    terminal.nombre = nombre;
    terminal.ciudad = ciudad;
    terminal.pais = pais;
    terminal.superficie = superficie;
    terminales.push_back(terminal);
    ofstream archivoTerminales("terminales.txt");
    if (archivoTerminales.is_open())
    {
        for (int i = 0; i < terminales.size(); i++)
        {
            archivoTerminales << terminales[i].codigo << " " << terminales[i].nombre << " " << terminales[i].ciudad << " " << terminales[i].pais << " " << terminales[i].superficie << " " << terminales[i].cantidadTerminales << " " << terminales[i].destinosNacionales << " " << terminales[i].destinosInternacionales << endl;
        }
        archivoTerminales.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo terminales.txt" << endl;
    }
}

void ejecutarOpciones(vector<Terminal> terminales)
{
    int opcion;
    do
    {
        mostrarOpciones();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Consultar por una terminal en particular" << endl;
            consultarTerminal(terminales);
            break;
        case 2:
            cout << "Dar de alta una nueva terminal" << endl;
            darAltaTerminal(terminales);
            break;
        case 3:
            cout << "Dar de baja a alguna" << endl;
            // darBajaTerminal(terminales);
            break;
        case 4:
            cout << "Mostrar todas las terminales (ordenados por los distintos datos)" << endl;
            // mostrarTerminales(terminales);
            break;
        case 5:
            cout << "Salir" << endl;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 5);
}
int main()
{
    Hash hash;
    ifstream archivoTerminales("terminales.txt");
    ifstream archivoViajes("viajes.txt");
    string linea;
    string codigo;
    string nombre;
    string ciudad;
    string pais;
    float superficie;
    int cantidadTerminales;
    int destinosNacionales;
    int destinosInternacionales;
    vector<Terminal> terminales;

    if (archivoTerminales.is_open())
    {
        while (getline(archivoTerminales, linea))
        {
            stringstream ss(linea);
            ss >> codigo >> nombre >> ciudad >> pais >> superficie >> cantidadTerminales >> destinosNacionales >> destinosInternacionales;
            Terminal terminal;
            terminal.codigo = codigo;
            terminal.nombre = nombre;
            terminal.ciudad = ciudad;
            terminal.pais = pais;
            terminal.superficie = superficie;
            terminal.cantidadTerminales = cantidadTerminales;
            terminal.destinosNacionales = destinosNacionales;
            terminal.destinosInternacionales = destinosInternacionales;
            terminales.push_back(terminal);
        }
        archivoTerminales.close();
        ejecutarOpciones(terminales);
    }
    else
    {
        cout << "No se pudo abrir el archivo terminales.txt" << endl;
    }
}