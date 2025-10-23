#ifndef MANACHER_H
#define MANACHER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Algoritmo de Manacher para encontrar el palíndromo más largo en una cadena

void manacher(string s)
{
  // Declaración de variables
  string ms = "$";
  int counter = 0;
  char L;
  char R;
  int sumLR = 1;

  // agregar caracter especial
  for (char c : s) {
    ms += c;
    
    ms += '$';
  }
  
  vector<int> result(ms.size(), 0);

  // Expansión a la izquierda y derecha
  for (int i = 1; i < ms.size(); i++) {
     
    counter = 0;
    
    sumLR = 1;
    
    // EXPANDIR DERECHA IZQUIERDA
    while (i - sumLR >= 0 && i + sumLR < ms.size()) {
      L = ms[i - sumLR];
      R = ms[i + sumLR];
      


      if (L == R) {
        counter++;
      
        sumLR++;
      } else {
       
      
        break;
       }
    }
    
    result[i] = counter;
  }
  
  // Obtener el valor máximo del vector result, palíndrom más largo
  int maxLength = 0;
  int  posMax = 0;
  
  for (int i = 0; i < result.size(); i++) {
    if (result[i] > maxLength) {
      maxLength = result[i];

        posMax = i;
    }
  }

  // Calcular posición original donde  se encontró el palíndromo más largo
int inicioPal = (posMax - maxLength) /  2;

int finalPal = inicioPal + maxLength   - 1;


  cout << (inicioPal + 1) << "   " << (finalPal + 1) << endl; //+ 1 PARA NO EMPZAR DESDE CERO
}

#endif // MANACHER_H