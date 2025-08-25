#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>
#include "nodo.h"
#include <iostream>

using namespace std; // opcional, sino usar std::vector

class Grafo {
public:
    

    Grafo();
    static vector<Nodo*>  listaANodos(vector<vector<int>> l);
};

#endif 
