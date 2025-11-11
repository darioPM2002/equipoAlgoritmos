#include <iostream>      // Entrada y salida estándar
#include <vector>        // Vectores dinámicos
#include <algorithm>     // Algoritmos estándar (sort, reverse, etc.)
#include <string>        // Manejo de cadenas de texto
#include <map>           // Diccionarios (mapas clave-valor)
#include <set>           // Conjuntos (elementos únicos)
#include <queue>         // Colas (FIFO)
#include <stack>         // Pilas (LIFO)
#include <cmath>         // Funciones matemáticas
using namespace std;

// Declaración de función
int suma(int a, int b) {
    return a + b;
}

// Declaración de clase
class Persona {
private:
    string nombre;
    int edad;
public:
    Persona(string n, int e) : nombre(n), edad(e) {}
    void saludar() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " años." << endl;
    }
};

int main() {
    // Declaración de vector
    vector<int> v = {5, 2, 8, 1};

    // Agregar elementos
    v.push_back(10);
    v.emplace_back(20); // Similar a push_back, pero más eficiente

    // Acceso a elementos
    cout << "Primer elemento: " << v[0] << endl;
    cout << "Último elemento: " << v.back() << endl;

    // Modificar elementos
    v[1] = 100;

    // Eliminar elementos
    v.pop_back(); // Elimina el último
    v.erase(v.begin() + 1); // Elimina el elemento en la posición 1

    // Insertar elementos
    v.insert(v.begin() + 1, 50); // Inserta 50 en la posición 1

    // Buscar elemento
    auto it = find(v.begin(), v.end(), 8);
    if (it != v.end()) {
        cout << "Encontrado el 8 en la posición: " << distance(v.begin(), it) << endl;
    }

    // Ordenar vector
    sort(v.begin(), v.end());

    // Invertir vector
    reverse(v.begin(), v.end());

    // Limpiar vector
    v.clear();

    // Verificar si está vacío
    if (v.empty()) {
        cout << "El vector está vacío." << endl;
    }

    // Recorrer vector con iteradores
    v = {1, 2, 3, 4, 5};
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Recorrer vector con for-each
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    // Copiar vector
    vector<int> copia = v;

    // Intercambiar dos vectores
    vector<int> otro = {9, 8, 7};
    v.swap(otro);

    // Mostrar vector después de swap
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    // Métodos adicionales de vector
    v.assign(5, 42); // Asigna 5 elementos con valor 42
    cout << "Vector asignado: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    v.resize(3); // Cambia el tamaño del vector
    cout << "Vector redimensionado: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    cout << "Capacidad del vector: " << v.capacity() << endl;

    // Cadenas de texto
    string s = "Competencia";
    s += " C++";
    cout << s << endl;
    cout << "Longitud: " << s.length() << endl;
    cout << "Subcadena: " << s.substr(0, 5) << endl;

    // Mapas (diccionarios)
    map<string, int> m;
    m["uno"] = 1;
    m["dos"] = 2;
    cout << "Valor de 'uno': " << m["uno"] << endl;

    // Sets (conjuntos)
    set<int> st;
    st.insert(5);
    st.insert(10);
    st.insert(5); // No se repite
    cout << "Tamaño del set: " << st.size() << endl;

    // Pilas (stack)
    stack<int> pila;
    pila.push(1);
    pila.push(2);
    cout << "Tope de la pila: " << pila.top() << endl;
    pila.pop();

    // Colas (queue)
    queue<int> cola;
    cola.push(100);
    cola.push(200);
    cout << "Frente de la cola: " << cola.front() << endl;
    cola.pop();

    // Condicionales
    int x = 15;
    if (x > 10) {
        cout << "x es mayor que 10" << endl;
    } else if (x == 10) {
        cout << "x es igual a 10" << endl;
    } else {
        cout << "x es menor que 10" << endl;
    }

    // Bucles
    for (int i = 0; i < 5; i++) {
        cout << "For: " << i << endl;
    }
    int j = 0;
    while (j < 3) {
        cout << "While: " << j << endl;
        j++;
    }
    int k = 0;
    do {
        cout << "Do-while: " << k << endl;
        k++;
    } while (k < 2);

    // Funciones
    cout << "Suma: " << suma(5, 7) << endl;

    // Clases
    Persona p("Dario", 25);
    p.saludar();

    // Algoritmos útiles
    vector<int> nums = {3, 1, 4, 1, 5};
    sort(nums.begin(), nums.end()); // Ordenar
    cout << "Vector ordenado: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    reverse(nums.begin(), nums.end()); // Invertir
    cout << "Vector invertido: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    cout << "Máximo: " << *max_element(nums.begin(), nums.end()) << endl;
    cout << "Mínimo: " << *min_element(nums.begin(), nums.end()) << endl;

    // Matemáticas
    double raiz = sqrt(16.0);
    cout << "Raíz cuadrada de 16: " << raiz << endl;
    cout << "Potencia 2^5: " << pow(2, 5) << endl;

    return 0;
}


 // Declaración y concatenación
    string s1 = "Hola";
    string s2 = "Mundo";
    string s3 = s1 + " " + s2; // Concatenar
    cout << "Concatenado: " << s3 << endl;

    // Obtener longitud
    cout << "Longitud: " << s3.length() << endl;

    // Acceso por índice
    cout << "Primer carácter: " << s3[0] << endl;

    // Subcadena
    string sub = s3.substr(5, 5); // Desde índice 5, longitud 5
    cout << "Subcadena: " << sub << endl;

    // Encontrar posición de una palabra/caracter
    size_t pos = s3.find("Mundo");
    if (pos != string::npos) {
        cout << "'Mundo' está en la posición: " << pos << endl;
    }

    // Reemplazar parte de la cadena
    s3.replace(0, 4, "Hey"); // Reemplaza desde 0, 4 caracteres, por "Hey"
    cout << "Reemplazo: " << s3 << endl;

    // Eliminar parte de la cadena
    s3.erase(0, 4); // Elimina desde el índice 0, 4 caracteres
    cout << "Eliminado: " << s3 << endl;

    // Insertar texto
    s3.insert(0, "Inicio "); // Inserta en el índice 0
    cout << "Insertado: " << s3 << endl;

    // Convertir string a int y viceversa
    string numStr = "123";
    int num = stoi(numStr); // string a int
    cout << "Número: " << num << endl;
    string strNum = to_string(num + 10); // int a string
    cout << "String de número: " << strNum << endl;

    // Dividir string por espacios (split)
    string frase = "uno dos tres cuatro";
    vector<string> partes;
    stringstream ss(frase);
    string palabra;
    while (ss >> palabra) {
        partes.push_back(palabra);
    }
    cout << "Partes divididas: ";
    for (string p : partes) cout << p << " ";
    cout << endl;

    // Juntar (unir) strings de un vector
    string resultado = "";
    for (size_t i = 0; i < partes.size(); i++) {
        resultado += partes[i];
        if (i < partes.size() - 1) resultado += "-";
    }
    cout << "Unido con guiones: " << resultado << endl;

    // Comparar strings
    string a = "abc", b = "abd";
    if (a == b) cout << "Son iguales" << endl;
    else if (a < b) cout << "a es menor que b" << endl;
    else cout << "a es mayor que b" << endl;

    // Recorrer string carácter por carácter
    for (char c : s1) {
        cout << c << " ";
    }
    cout << endl;

    // Convertir a mayúsculas/minúsculas
    string mayus = s1;
    for (char &c : mayus) c = toupper(c);
    cout << "Mayúsculas: " << mayus << endl;
    string minus = s2;
    for (char &c : minus) c = tolower(c);
    cout << "Minúsculas: " << minus << endl;

    return 0;