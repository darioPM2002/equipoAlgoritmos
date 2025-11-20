#pragma once

#include <vector>
#include <algorithm>
#include "grafo.h"
#include "nodo.h"

using namespace std;

vector<int> kruskal(vector<vector<int>> &listaAristas)
{
  // Ordenar aristas de menor a mayor
  sort(listaAristas.begin(), listaAristas.end(),
       [](const vector<int> &a, const vector<int> &b)
       {
         return a[2] < b[2]; // Comparar pesos
       });

  // Crear grafo y aplicar algoritmo
  Grafo g;
  g.listaANodos(listaAristas);

  for (size_t i = 0; i < listaAristas.size(); i++)
  {
    g.listaArevision(listaAristas[i], i);
  }

  // Regresamos indices de las aristas seleccionadas
  return g.indexRespuesta;
}

int calcularPesoTotal(const vector<vector<int>> &listaAristas, const vector<int> &selectedIndices)
{
  int pesoTotal = 0;
  for (int idx : selectedIndices)
  {
    pesoTotal += listaAristas[idx][2];
  }
  return pesoTotal;
}

/**
 * Print MST edges in the original format
 * Format: "Conexiones usadas: [x,y,weight], ... Peso final: total"
 */
void imprimirResultadoOriginal(const vector<vector<int>> &listaAristas, const vector<int> &selectedIndices)
{
  cout << "Conexiones usadas: ";

  for (size_t i = 0; i < selectedIndices.size(); i++)
  {
    int idx = selectedIndices[i];
    cout << "[" << listaAristas[idx][0] << ","
         << listaAristas[idx][1] << ","
         << listaAristas[idx][2] << "]";

    if (i < selectedIndices.size() - 1)
    {
      cout << ", ";
    }
  }

  int pesoTotal = calcularPesoTotal(listaAristas, selectedIndices);
  cout << ". Peso final: " << pesoTotal << endl;
}
