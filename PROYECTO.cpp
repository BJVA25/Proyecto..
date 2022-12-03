#include <iostream>
#include <array>
using namespace std;

int main()
{
    // Declaramos tres arreglos, uno por cada columna de la tabla
    // Primero los nombres
    array<string, 4> videojuegos = {
        "Fortnite\n videojuego del ano 2017 desarrollado por la empresa Epic Games.\n Genero: Supervivencia, Mundo abierto, Battle Royale.\n Clasificaciones B / 12+",
        "Warzone\n videojuego del ano 2020 desarrollado por la empresa  Raven Software y Infinity Ward.\n Genero: Battle royale Disparos en primera persona.\n Clasificacion M",
        "FIFA 23\n videojuego del ano 2022 desarroladdo por la empresa  Electronic Arts, EA Canada, EA Canada, EA Romania y EA Romania.\n Generos: Videojuego de deportes, Soccer video game, Juego de simulacion, Simulation, Sports.\n Clasificacion A / TODOS  ",
        "Rocket League \n videojuego del año 2015 desarrollador por la empresa Psyonix. \n Genero: Deportes. \n Clasificaciones TODOS "
    };
    // Luego los costos
    array<double, 4> costos = {
        250, 600, 300, 150 };
    // Finalmente las existencias
    array<int, 4> cantidades = {
        100, 100, 100, 100 };


    // Mientras que la elección del usuario no sea "2" que es para salir...
    string eleccion = "";
    // Hacer el ciclo
    while (eleccion != "2")
    {
        // Imprimir los artículos
        cout << "____________" << endl;
        for (int i = 0; i < 4; i++)
        {
            // Imprimir el número para que el usuario pueda seleccionar el artículo
            cout << "Numero: " << i + 1 << endl;
            cout << "Videojuegos: " << videojuegos[i] << endl;
            cout << "Costo: " << costos[i] << endl;
            cout << "Cantidad: " << cantidades[i] << endl;
            cout << "____________" << endl;
        }
        // Imprimir el menú principal
        cout << "1. Comprar articulo\n2. Salir\nSeleccione: ";
        // Leer lo que el usuario elija
        cin >> eleccion;
        // Si elige 1, entonces solicitar número de artículo y cantidad
        if (eleccion == "1")
        {
            int numeroArticulo;
            cout << "Ingrese el numero del videojuego que desea comprar: ";
            cin >> numeroArticulo;
            // Necesitamos el índice del arreglo, que sería restarle 1 al número que elige el usuario pues los arreglos comienzan a contar en 0
            int indice = numeroArticulo - 1;
            // Validamos si el número de artículo está entre 0 y 4
            if (indice >= 0 && indice <= 4)
            {
                // Solicitamos cantidad
                int cantidad;
                cout << "Ingrese la cantidad que compra: ";
                cin >> cantidad;
                // Validar si la cantidad es correcta
                if (cantidad > cantidades[indice])
                {
                    cout << "No hay suficiente existencia" << endl;
                }
                else
                {
                    // En caso de que sí haya suficiente existencia, extraemos el costo
                    double costo = costos[indice];
                    // Sacamos el costo total
                    double total = costo * cantidad;
                    // Imprimimos
                    cout << "========================================" << endl;
                    cout << "Usted ha comprado " << videojuegos[indice] << " X " << cantidad << endl;
                    cout << "Total: " << total << endl;
                    cout << "GRACIAS POR SU COMPRA" << endl;
                    cout << "========================================" << endl;
                    // Y restamos la cantidad en el arreglo
                    cantidades[indice] = cantidades[indice] - cantidad;
                }
            }
            else
            {
                // Caso contrario, imprimimos que no es un artículo válido
                cout << "Numero de artículo " << numeroArticulo << " inválido" << endl;


            }
        }
    }
}