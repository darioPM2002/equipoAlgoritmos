#include <iostream>
#include <map>
#include <string>
#include <cmath>

long long hashPoly(const std::string &palabra) {
    // Mapa de caracteres a índices
    std::map<char, int> indexABC = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5},
        {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10},
        {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'*', 15},
        {'o', 16}, {'p', 17}, {'q', 18}, {'r', 19}, {'s', 20},
        {'t', 21}, {'u', 22}, {'v', 23}, {'w', 24}, {'x', 25},
        {'y', 26}, {'z', 27}
    }; 

    long long resultado = 0;
    long long m = 1000000009;
    int p = 31;

    for (size_t i = 0; i < palabra.size(); i++) {
        char c = palabra[i];
        if (indexABC.count(c)) { 
            resultado = (resultado + (long long)(indexABC.at(c)) * (long long)pow(p, i)) % m;
        }
    }

    return resultado;
}

int main() {

  
    std::string palabra = "ababcabcabababd";
    std::cout << "Hash: " << hashPoly(palabra) << std::endl;
    //  std::cou << palabra[0] std::endl;


    return 0;
}
