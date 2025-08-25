#include "nodo.h"
#include <iostream>


Nodo::Nodo(int id)
    : id(id){}

void Nodo::conectar(Nodo* vecino, int peso) {
    adyacentes.push_back(Conexion{vecino, peso});
}

void Nodo::imprimir() const {
    std::cout << "Nodo " << id;
  
    std::cout << " Conexiones v ";
     std::cout << std::endl;
    for (auto nodoVecino : adyacentes) {
     
        std::cout <<"Conexion a nodo: " <<nodoVecino.nodoVecino->id << " ";
        std::cout << " Peso de la conexion == "<< nodoVecino.peso << " ";
        std::cout << std::endl;
    }
     std::cout << "Nodo " << id;
     std::cout << " Conexiones ^ ";
     std::cout << std::endl;
      std::cout << std::endl;
}