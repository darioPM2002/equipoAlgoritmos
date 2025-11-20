#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "../kruskal/kruskal_algorithm.h"

using namespace std;

void cableadoOptimo(const vector<vector<int>> &matriz)
{
  int N = matriz.size();

  // Convertimos la matriz en la lista de aristas que necesitamos [nodo1, nodo2, peso]
  vector<vector<int>> listaAristas;

  for (int i = 0; i < N; ++i)
  {
    for (int j = i + 1; j < N; ++j)
    { // Only upper triangle to avoid duplicates
      if (matriz[i][j] > 0)
      { // Only add edges with positive weight
        listaAristas.push_back({i, j, matriz[i][j]});
      }
    }
  }

  // Aplicamos kruskal
  vector<int> mstIndices = kruskal(listaAristas);

  // Imprimimos las aristas a usar
  for (size_t i = 0; i < mstIndices.size(); ++i)
  {
    int index = mstIndices[i];
    int nodo1 = listaAristas[index][0];
    int nodo2 = listaAristas[index][1];
  }
  cout << endl;
}
