#include "nodo.h"
#include "grafo.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    Nodo *n1 = new Nodo(1);
    Nodo *n2 = new Nodo(2);
    Nodo *n3 = new Nodo(3);

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

    // Ordenar por el último elemento de cada subvector
    sort(listaPesosOrdenada.begin(), listaPesosOrdenada.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
             return a[2] < b[2];
         });

    vector<Nodo *> nodos;
    Grafo g;

    g.listaANodos(listaPesosOrdenada);
    for (size_t i = 0; i < listaPesosOrdenada.size(); i++)
    {
        g.listaArevision(listaPesosOrdenada[i], i);
    }

    // nodos[0]
    g.imprmirRespuesta(listaPesosOrdenada);
    // g.revisionLinea(nodos[0], nodos[1], 0);

    return 0;
}
