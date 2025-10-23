
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Construye el arreglo de sufijos para un string
vector<int> suffixArray(const string &s)
{
 
  int n = s.length();
 
  vector<pair<string, int>> suffixes;

  for (int i = 0; i < n; i++)
  {


    suffixes.push_back({s.substr(i), i});
  }

  // Ordena los sufijos alfabéticamente
  sort(suffixes.begin(), suffixes.end());

  vector<int> suffixArr(n);

  for (int i = 0; i < n; i++)
  {
    suffixArr[i] = suffixes[i].second; // Guardamos la posición del sufijo
  }

  return suffixArr;
}

// Arreglo LCP (Longest Common Prefix)
vector<int> LCPArray(const string &s, const vector<int> &suffixArr)
{
  int n = s.length();

  vector<int> lcp(n, 0); // Inicializa el vector con ceros

  for (int i = 0; i < n - 1; i++)
  {
    int suffix1_start = suffixArr[i];
    int suffix2_start = suffixArr[i + 1];
  
    int currentLCP = 0; // Contador de cuántos caractéres son iguales

    // Ver cuántos caracteres son iguales
    while (suffix1_start + currentLCP < n &&
  
      suffix2_start + currentLCP < n &&
  
           s[suffix1_start + currentLCP] == s[suffix2_start + currentLCP])
    {
      currentLCP++; // Incrementar la longitud del prefijo común
    }


    lcp[i] = currentLCP; // Guardar la longitud del LCP
  }

  return lcp;
}

void longestCommonSubstring(const string &s1, const string &s2)
{
  string combined = s1 + "#" + s2;

  int n1 = s1.length();

  vector<int> suffixArr = suffixArray(combined);
  
  vector<int> lcp = LCPArray(combined, suffixArr);

  int maxLen = 0;    // Longitud del LCS
  
  int maxPosS1 = -1; // Posición inicial del LCS en s1 

  int maxPosS2 = -1; // Posición inicial del LCS en s2 

  // Buscar el LCP más largo de sufijos de strings diferentes
  for (int i = 0; i < lcp.size() - 1; i++)
  {
    int pos1 = suffixArr[i];     // Posición inicial del primer sufijo
    
    int pos2 = suffixArr[i + 1]; // Posición inicial del segundo sufijo


    bool from1 = (pos1 < n1); // true si pos1 está en el string 1 (s1)
    bool from2 = (pos2 > n1); // true si pos2 está en el string 2 (s2)

    // Solo considerar LCP cuando los sufijos vienen de cadenas diferentes
    if (from1 == from2 && lcp[i] > maxLen)
    {
      maxLen = lcp[i]; // Actualizar la longitud máxima

      // Almacenar ambas posiciones
      if (from1)
      {
        // from1 es true, from2 es true
        // pos1 está en s1, pos2 está en s2
        maxPosS1 = pos1;
        maxPosS2 = pos2;
      }
      else
      {
        // from1 es false, from2 es false
        // pos1 está en s2, pos2 está en s1
        maxPosS1 = pos2;
        maxPosS2 = pos1;
      }
    }
  }
  // Si no se encontró ninguna subcadena
  if (maxLen == 0)
    cout << "No se encontré ningún substring en común" << endl;

  // Convertir la posición de S2 de "combined" a "s2"
  // Índice en s2 = Índice en combined - longitud de s1 - longitud de #
  int startS2_in_S2 = maxPosS2 - n1 - 1;

  // Retornar posiciones indexadas desde 1 (inicio y fin en s1 y s2)
  // return {maxPosS1 + 1, maxPosS1 + maxLen, startS2_in_S2 + 1, startS2_in_S2 + maxLen};
  cout << "La posicion de inicio y fin en el primer archivo de transmision es " << maxPosS1 + 1 << " y " << maxPosS1 + maxLen << " respectivamente" << endl;
  cout << "La posicion de incio y fin en el segundo archivo de transmision es " << startS2_in_S2 + 1 << " y " << startS2_in_S2 + maxLen << ", respectivamente" << endl;
}