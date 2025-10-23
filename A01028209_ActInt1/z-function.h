#include <iostream>
#include <vector>

using namespace std;

// Función Z para encontrar patrones en un texto, en el nuestro sólo imprime el primer indice donde lo encontró
void z(const string& text, const string& pattern = "")
{

  //SÓLO SE PUEDE TRABAJAR SI LE MANDAMOS PATRON, SI NO FALSE
  if (pattern.empty()) {
    cout << "false" << endl;
    return;
  }

  //CONCATENAACIÓN Y VECTOR Z LLENADO CON 0 INICIALMENTE
  string concat = pattern + "$" + text;
  vector<int> z(concat.size(), 0);




  //REVISAMOS SI HAY COINCIDENCIAS ENTRE PATRÓN Y TEXTO PLANO
  for (int i = 1; i < concat.size(); ++i) {
    int count = 0;
    while (i + count < concat.size() && concat[count] == concat[i + count]) {
      ++count;
    }
    z[i] = count;
  }

  //IMPRIMIMOS EL PRIMER ÍNDICE DONDE SE ENCUENTRA EL PATRÓN, EN CASO DE QUE SE HAYA ENCONTRADO
  bool found = false;
  for (int i = 1; i < z.size(); ++i) {
    if (z[i] == pattern.size()) {
      found = true;

      cout << "true" << " " << (i - pattern.size() - 1) << endl;
      //CON ESTE RETRUN SÓLO IMPRIMIMOS LA PRIMER COINCIDENCIA
      return;
    }
  }
  if (!found) {
    cout << "false" << endl;
  }
}
