#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "z-function.h"
#include "Manacher.h"

// Valentina Castilla Melgoza A01028209
// Fausto Izquierdo
// Darío Peña
// Actividad Integradora 1
// 23 de Octubre del 2025

// Función para leer el contenido de un archivo
string readFromFile(const string& filename) {
    ifstream file(filename);
    string line, content;
    if (file.is_open()) {
        while (getline(file, line)) {
            content += line;
        }
        file.close();
    } else {
        cout << "Error: Could not open file " << filename << endl;
    }
    return content;
}


int main() {

    string t1 = readFromFile("transmission1.txt");
    string t2 = readFromFile("transmission2.txt");

    string m1 = readFromFile("mcode1.txt");
    string m2 = readFromFile("mcode2.txt"); 
    string m3 = readFromFile("mcode3.txt"); 

    // La complejidad del algoritmo manacher es de O(n) porque recorre la cadena una sola vez
    cout<<"Parte 1"<<endl;
    z(t1,m1);
    z(t1,m2);
    z(t1,m3);
    z(t2,m1);
    z(t2,m2);
    z(t2,m3);

    // La complejidad del algoritmo manacher es de O(n) porque igual recorre la cadena una sola vez
    cout<<endl<<"Parte 2"<<endl;
    manacher(t1);
    manacher(t2);
    
    return 0;
}
    