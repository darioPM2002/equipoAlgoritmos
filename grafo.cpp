#include "grafo.h"
#include <iostream>
#include <string>
#include <vector>

Grafo::Grafo()
{
    indexRespuesta = {};
}

bool existeNodo(const std::vector<Nodo *> &nodos, int idBuscado)
{
    for (const auto &nodo : nodos)
    {
        if (nodo->getId() == idBuscado)
        {
            return true;
        }
    }
    return false;
}
void Grafo::listaANodos(vector<vector<int>> l)
{
    vector<Nodo *> nodos;
    for (size_t i = 0; i < l.size(); i++)
    {
        if (existeNodo(nodos, l[i][0]))
        {
        }
        else
        {
            cout << "Creando nodo " << l[i][0] << endl;

            nodos.push_back(new Nodo(l[i][0]));
        }
        if (existeNodo(nodos, l[i][1]))
        {
        }
        else
        {
            cout << "Creando nodo " << l[i][1] << endl;
            nodos.push_back(new Nodo(l[i][1]));
        }
    }

    this->nodosCreados = nodos;
}

void Grafo::listaArevision(vector<int> l, int indexList)
{
    Nodo *n1 = getNodoById(l[0]);
    Nodo *n2 = getNodoById(l[1]);
    int peso = l[2];
    int index = indexList;
    if (this->revisionLinea(n1, n2, peso))
    {

        this->indexRespuesta.push_back(indexList);
    }
}

Nodo *Grafo::getNodoById(int id)
{
    for (auto *nodo : nodosCreados)
    {
        if (nodo->getId() == id)
        {
            return nodo;
        }
    }
    return nullptr;
}

bool Grafo::revisionLinea(Nodo *n, Nodo *nr, int peso)
{
    if (nr->getConexiones().size() == 0)
    {
        n->conectar(nr, peso);
        nr->conectar(n, peso);
        cout << "Conectando nodo " << n->getId() << " con nodo " << nr->getId() << " con peso " << peso << endl;
        return true;
    }
    else
    {
        if (buscarNodoRecursivo(n, nullptr, nr->getId()) == false)
        {
            n->conectar(nr, peso);
            nr->conectar(n, peso);
            cout << "Conectando nodo " << n->getId() << " con nodo " << nr->getId() << " con peso " << peso << endl;
            return true;
        }
        return false;
    }
}

void Grafo::imprmirRespuesta(vector<vector<int>> listaPesos)
{
    int peso = 0;
    std::cout << "Conexiones usadas: ";
    for (size_t i = 0; i < this->indexRespuesta.size(); i++)
    {
        int index = this->indexRespuesta[i];
        std::cout << "[" << listaPesos[index][0] << "," << listaPesos[index][1] << "," << listaPesos[index][2] << "]";
        peso += listaPesos[index][2];

        if (i < this->indexRespuesta.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ". Peso final: " << peso << std::endl;
}

bool Grafo::buscarNodoRecursivo(Nodo *actual, Nodo *padre, int idBuscado)
{
    if (!actual)
        return false;
    if (actual->getId() == idBuscado)
        return true;

    for (const auto &conexion : actual->getConexiones())
    {
        Nodo *vecino = conexion.nodoVecino;
        if (vecino != padre)
        {
            if (buscarNodoRecursivo(vecino, actual, idBuscado))
            {
                return true;
            }
        }
    }
    return false;
}