#ifndef NODO_H
#define NODO_H

#include <string>
#include <vector>

class Nodo; // Declaración adelantada

struct Conexion {
    Nodo* nodoVecino;
    int peso;
};

class Nodo {
public:
    int id;
    std::vector<Conexion> adyacentes;
    
    Nodo(int id);
    int getId() const { return id; }
    std::vector<Conexion> getConexiones() const { return adyacentes; }
    void conectar(Nodo* vecino, int peso);
    void imprimir() const;
};

#endif
