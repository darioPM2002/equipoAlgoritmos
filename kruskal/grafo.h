#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>
#include "nodo.h"
#include <iostream>

using namespace std; // opcional, sino usar std::vector

class Grafo {
public:
    vector<Nodo*> nodosCreados;
    std::vector<int> indexRespuesta;
    Grafo();
    bool buscarNodoRecursivo(Nodo* actual, Nodo* padre, int idBuscado);
    void  listaANodos(vector<vector<int>> l);
    vector<Nodo*> getNodos() const { return nodosCreados; }
    void  listaArevision(vector<int> l, int indexList );
    Nodo*  getNodoById(int id);
    bool  revisionLinea(Nodo* n, Nodo* nr, int peso);
    void  imprmirRespuesta (vector<vector<int>> listaPesos);
};

#endif 
