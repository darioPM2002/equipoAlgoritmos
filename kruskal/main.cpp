#include "nodo.h"
#include "grafo.h"
#include "kruskal_algorithm.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> listaPesosOrdenada;

    // Leer desde el archivo lista.txt
    ifstream infile("list.txt");
    string line;
    while (getline(infile, line))
    {
        istringstream iss(line);
        vector<int> elemento(3);
        if (iss >> elemento[0] >> elemento[1] >> elemento[2])
        {
            listaPesosOrdenada.push_back(elemento);
        }
    }
    infile.close();

    if (listaPesosOrdenada.empty())
    {
        cout << "Error: No se encontraron conexiones válidas en el archivo" << endl;
        return 1;
    }

    // Apply Kruskal's algorithm
    vector<int> mstIndices = kruskal(listaPesosOrdenada);

    // Print results
    imprimirResultadoOriginal(listaPesosOrdenada, mstIndices);

    return 0;
}
