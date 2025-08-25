#include "nodo.h"
#include "grafo.h"
#include <vector>

int main(int argc, char const *argv[]) {

    Nodo * n1 = new Nodo(1);
    Nodo * n2 = new Nodo(2);
    Nodo * n3 = new Nodo(3);

    n1->conectar(n2, 10);
    n1->conectar(n3, 20);

    n1->imprimir();
    vector<Nodo*> numerosNodos;
    
    vector<Nodo*> nodos;
    nodos = Grafo::listaANodos({{1, 2}, {2, 3}, {3, 1}});

    for (size_t i = 0; i < nodos.size(); i++)
    {
        nodos[i]->imprimir();
    }
    

    return 0;
}
