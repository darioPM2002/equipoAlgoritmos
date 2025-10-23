#include <iostream>
#include <vector>

using namespace std;

// Algoritmo de Manacher para encontrar el palíndromo más largo en una cadena
void manacher(string s)
{
  string ms = "$";
  int counter = 0;
  char L;
  char R;
  int sumLR = 1;

  for (char c : s) {
    ms += c;
    ms += '$';
  }
  vector<int> result(ms.size(), 0);
  for (int i = 1; i < ms.size(); i++) {
    if (i - sumLR < 0 || i + sumLR >= ms.size()) {
      result[i] = counter;
      counter = 0;
      sumLR = 1;
    }
    else {
      L = ms[i - sumLR];
      R = ms[i + sumLR];
      while (L == R) {
        counter++;
        sumLR++;
        if (i - sumLR >= 0 && i + sumLR < ms.size()) {
          L = ms[i - sumLR];
          R = ms[i + sumLR];
        } else {
          break;
        }
      }
      result[i] = counter;
      sumLR = 1;
      counter = 0;
    }
  }
  // Obtener valores maximos del vector result (palindromo mas largo)
  int maxLength = 0;
  int posMax = 0;
  for (int i = 0; i < result.size(); i++) {
    if (result[i] > maxLength) {
      maxLength = result[i];
      posMax = i;
    }
  }
  int inicioPal = ((posMax-maxLength)/2) + 1;
  int finalPal = (inicioPal + maxLength) - 1;
  cout << inicioPal << " " << finalPal << endl;
}
