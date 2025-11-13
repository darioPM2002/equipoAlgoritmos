#include <iostream>
#include <vector>
#include <map>
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

    cout << "El resultado final es: " << resultadoSuma << endl;
    cout << "Camino recorrido: ";
    for (int idx : caminoRecorrido)
        cout << nombresNodos[idx] << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{

    vector<vector<int>> matriz = {
        {0, 259, 177, 611, 504, 899, 827, 971, 969, 1007},
        {259, 0, 277, 546, 492, 906, 912, 1045, 1049, 1110},
        {177, 277, 0, 440, 327, 723, 670, 811, 830, 859},
        {611, 546, 440, 0, 139, 385, 507, 597, 612, 702},
        {504, 492, 327, 139, 0, 415, 453, 569, 578, 655},
        {899, 906, 723, 385, 415, 0, 274, 270, 296, 401},
        {827, 912, 670, 507, 453, 274, 0, 146, 142, 202},
        {971, 1045, 811, 597, 569, 270, 146, 0, 28, 131},
        {969, 1049, 830, 612, 578, 296, 142, 28, 0, 105},
        {1007, 1110, 859, 702, 655, 401, 202, 131, 105, 0}};

    vector<string> nombresNodos = {"Y", "CH", "CA", "TG", "V", "O", "X", "P", "T", "PA"};

    // Agentes viajero comenzando en Xalapa
    cout << "Agente viajero comenzando en Xalapa (X):" << endl;
    agenteViajero(matriz, "X", nombresNodos);
    cout << endl;
    // Agentes viajero comenzando en Yucatan
    cout << "Agente viajero comenzando en Yucatan (Y):" << endl;
    agenteViajero(matriz, "Y", nombresNodos);

    /* code */
    return 0;
}
