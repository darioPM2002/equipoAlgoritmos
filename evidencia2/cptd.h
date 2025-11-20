#include <iostream>
#include <vector>
#include <cmath>
#include <utility> // pair
using namespace std;

// Calcula distancias entre todas las centrales y se queda con la mínima
// Par de índices produce esa distancia
double comparacion(const vector<pair<int, int>> &centrales, int &idx1, int &idx2)
{
    double resultado = 0.0;
    double mejor = numeric_limits<double>::max(); // algo muy grande

    idx1 = -1;
    idx2 = -1;

    for (size_t i = 0; i < centrales.size(); i++)
    {
        for (size_t j = i + 1; j < centrales.size(); j++)
        {

            cout << "comparacion:  (" << centrales[i].first << ", " << centrales[i].second << ")  ";
            cout << "con (" << centrales[j].first << ", " << centrales[j].second << ")" << endl;

            resultado = sqrt(
                pow(centrales[i].first - centrales[j].first, 2) +
                pow(centrales[i].second - centrales[j].second, 2));

            cout << "resultado: " << resultado << endl;

            if (resultado < mejor)
            {
                mejor = resultado;
                idx1 = static_cast<int>(i);
                idx2 = static_cast<int>(j);
            }
        }
    }

    return mejor;
}

// Imprime todas las coordenadas y el par mas cercano.
void CPYTO(const vector<pair<int, int>> &centrales)
{

    cout << "Parte 3:" << endl
         << endl;

    if (centrales.size() < 2)
    {
        cout << "No hay suficientes centrales para comparar." << endl;
        return;
    }

    cout << "Coordenadas de las centrales:" << endl;
    for (size_t i = 0; i < centrales.size(); ++i)
    {
        cout << "Central " << i + 1 << ": ("
             << centrales[i].first << ", "
             << centrales[i].second << ")" << endl;
    }
    cout << endl;

    int idx1, idx2;
    double distanciaMinima = comparacion(centrales, idx1, idx2);

    // Redondear a 2 decimales
    double distancia_redondeada = round(distanciaMinima * 100.0) / 100.0;

    cout << "Par de centrales mas cercanas:" << endl;
    cout << "Central 1: (" << centrales[idx1].first
         << ", " << centrales[idx1].second << ")" << endl;
    cout << "Central 2: (" << centrales[idx2].first
         << ", " << centrales[idx2].second << ")" << endl;
    cout << "Distancia entre ellas: " << distancia_redondeada
         << endl
         << endl;
}

// Encuentra la central más cercana a una nueva contratación
void centralMasCercana(const vector<pair<int, int>> &centrales)
{
    cout << "\nNueva contratacion del servicio:" << endl;

    int x, y;
    cout << "Ingrese las coordenadas de la nueva casa (formato: x y): ";
    cin >> x >> y;

    if (!cin)
    {
        cout << "Error: Coordenadas invalidas" << endl;
        return;
    }

    cout << "\nCasa nueva: (" << x << ", " << y << ")" << endl;

    // Encontrar la central más cercana
    double mejorDistancia = numeric_limits<double>::max(); // valor máximo de variable double
    int centralMasCercana = -1;

    for (size_t i = 0; i < centrales.size(); i++)
    {
        double distancia = sqrt(
            pow(x - centrales[i].first, 2) +
            pow(y - centrales[i].second, 2));

        if (distancia < mejorDistancia)
        {
            mejorDistancia = distancia;
            centralMasCercana = static_cast<int>(i);
        }
    }

    // Redondear a 2 decimales
    double distanciaRedondeada = round(mejorDistancia * 100.0) / 100.0;

    cout << "\nCentral mas cercana:" << endl;
    cout << "Central " << (centralMasCercana + 1) << ": ("
         << centrales[centralMasCercana].first << ", "
         << centrales[centralMasCercana].second << ")" << endl;
    cout << "Distancia: " << distanciaRedondeada << " unidades" << endl;
}
