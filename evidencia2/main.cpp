// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "agenteViajero.h"
#include "cptd.h"
using namespace std;

// Headers de cada parte
#include "parte1_mst.h" // Parte 1: cableado óptimo (MST, por ejemplo Prim)
// #include "parte2_tsp.h"       // Parte 2: ruta tipo agente viajero
// #include "parte3_centrales.h" // Parte 3: central más cercana

// Función para generar nombres de colonias A, B, C
vector<string> generarNombresColonias(int n)
{
    vector<string> nombres;
    nombres.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        char letra = 'A' + i;
        nombres.push_back(string(1, letra));
    }
    return nombres;
}

int main()
{
    // Abrimos el archivo de texto
    ifstream archivo("datos.txt");
    if (!archivo)
    {
        cerr << "No se pudo abrir el archivo datos.txt" << endl;
        return 1;
    }

    int N; // Se guarda en N ...
    archivo >> N;
    if (!archivo)
    {
        cerr << "Error al leer el numero de colonias (N)." << endl;
        return 1;
    }

    // Matriz de adyacencia N x N
    vector<vector<int>> matriz(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            archivo >> matriz[i][j];
        }
    }

    // Lista de N pares (x, y) para las centrales
    // Formato de entrada: (200,500) por línea, como en el ejemplo
    vector<pair<int, int>> centrales(N);
    for (int i = 0; i < N; ++i)
    {
        char ch;
        int x, y;

        // Leemos algo del estilo: (200,500)
        archivo >> ch; // '('
        archivo >> x;
        archivo >> ch; // ','
        archivo >> y;
        archivo >> ch; // ')'

        if (!archivo)
        {
            cerr << "Error al leer las coordenadas de la central " << i << "." << endl;
            return 1;
        }

        centrales[i] = {x, y};
    }

    // Generamos nombres de colonias: A, B, C
    vector<string> nombresColonias = generarNombresColonias(N);

    // ========================
    // PARTE 1: Cableado optimo
    // ========================

    cout << "=== Parte 1: Cableado con fibra optica ===" << endl;
    cableadoOptimo(matriz);
    cout << endl;

    // ========================
    // PARTE 2: Ruta tipo TSP
    // ========================
    cout << "=== Parte 2: Ruta de reparto (TSP) ===" << endl;
    agenteViajero(matriz, "A", nombresColonias);

    // ==============================
    // PARTE 3: Central mas cercana
    // ==============================

    cout << "=== Parte 3: Central mas cercana ===" << endl;
    centralMasCercana(centrales);

    return 0;
}
