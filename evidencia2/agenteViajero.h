#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdint>
using namespace std;


void agenteViajero(vector<vector<int>> matriz, string nodoInicial, vector<string> nombresNodos)
{

    map<string, int> traducciionNombres;

    for (size_t i = 0; i < nombresNodos.size(); i++)
    {
        traducciionNombres[nombresNodos[i]] = i;
        // cout << "Traduccion: " << nombresNodos[i] << " -> " << traducciionNombres[nombresNodos[i]]<< endl;
    }

    vector<int> caminoRecorrido = {traducciionNombres[nodoInicial]};
    int resultadoSuma = 0;
    int n = matriz.size();
    int noodoActual = traducciionNombres[nodoInicial];

    for (int paso = 1; paso < n + 1; paso++)
    {
        int valorMinimo = INT32_MAX;
        int nodoPosible = -1;
        if (paso == n)
        {
            // cout << "Regresando al nodo inicial: " << nodoInicial << endl;

            for (int j = 0; j < n; j++)
            {
                // Si no hemos visitado el nodo y hay camino
                if (j == traducciionNombres[nodoInicial])
                {
                    if (matriz[noodoActual][j] < valorMinimo)
                    {
                        valorMinimo = matriz[noodoActual][j];
                        nodoPosible = j;
                    }
                }
            }
            if (nodoPosible == -1)
                break;
            caminoRecorrido.push_back(nodoPosible);
            resultadoSuma += valorMinimo;
            noodoActual = nodoPosible;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                // Si no hemos visitado el nodo y hay camino
                if (find(caminoRecorrido.begin(), caminoRecorrido.end(), j) == caminoRecorrido.end() && matriz[noodoActual][j] != traducciionNombres[nodoInicial])
                {
                    if (matriz[noodoActual][j] < valorMinimo)
                    {
                        valorMinimo = matriz[noodoActual][j];
                        nodoPosible = j;
                    }
                }
            }
            if (nodoPosible == -1)
                break;
            caminoRecorrido.push_back(nodoPosible);
            resultadoSuma += valorMinimo;
            noodoActual = nodoPosible;
        }
    }

    cout << "El peso final es: " << resultadoSuma << endl;
    cout << "Camino recorrido: ";
    for (int idx : caminoRecorrido)
        cout << nombresNodos[idx] << " ";
    cout << endl;
}

