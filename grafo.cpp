#include "grafo.h"
#include <iostream>
#include <string>
#include <vector>


Grafo::Grafo()
{
}

bool existeNodo(const std::vector<Nodo*>& nodos, int idBuscado) {
    for (const auto& nodo : nodos) {
        if (nodo->getId() == idBuscado) {
            return true;
        }
    }
    return false;
}
vector<Nodo *>Grafo::listaANodos(vector<vector<int>> l)
{
    vector<Nodo *> nodos;
    for (size_t i = 0; i < l.size(); i++)
    {
        if (existeNodo(nodos, l[i][0]))
        {
          
        }else{
            cout << "Creando nodo " << l[i][0] << endl;
          
            nodos.push_back(new Nodo(l[i][0]));
        }
          if (existeNodo(nodos, l[i][1]))
        {
          
        }else{
             cout << "Creando nodo " << l[i][1] << endl;
            nodos.push_back(new Nodo(l[i][1]));

        }
        
        
    }
    


    return nodos;
}
