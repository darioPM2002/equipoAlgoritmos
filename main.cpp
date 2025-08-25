#include "nodo.h"
#include "grafo.h"
#include <vector>

int main(int argc, char const *argv[]) {

    Nodo * n1 = new Nodo(1);
    Nodo * n2 = new Nodo(2);
    Nodo * n3 = new Nodo(3);

    vector<vector<int>> listaPesosOrdenada;
    listaPesosOrdenada = {
        {6, 7, 1}, 
        {2, 8, 2}, 
        {5, 6, 2},
        {2, 5, 4},
        {0, 1, 4},
        {6, 8, 6},
        {2, 3, 7},
        {7, 8, 7},
        {0, 7, 8},
        {1, 2, 8},
        {3, 4, 9},
        {4, 5, 10},
        {1, 7, 11},
        {3, 5, 14},
    
    };
    

    
    vector<Nodo*> nodos;
    Grafo g;

    g.listaANodos(listaPesosOrdenada);
    for (size_t i = 0; i < listaPesosOrdenada.size(); i++)
    {
         g.listaArevision(listaPesosOrdenada[i], i);
    }
    
   
    //nodos[0]
    g.imprmirRespuesta(listaPesosOrdenada);        
    //g.revisionLinea(nodos[0], nodos[1], 0);

    

    return 0;
}
