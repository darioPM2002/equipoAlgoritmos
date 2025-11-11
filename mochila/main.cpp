#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> crearMatriz(int x, int y){
    vector<vector<int>> matriz(y, vector<int>(x, 0));
    return matriz;
}

void imprimirMatriz(const vector<vector<int>>& matriz){
    for (size_t i = 0; i < matriz.size(); i++) {
        for (size_t j = 0; j < matriz[i].size(); j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void imprimirMatrizTranspuesta(const vector<vector<int>>& matriz){
    int filas = matriz.size();
    
    int cols = matriz[0].size();
    for (int x = 0; x < cols; x++) {
        for (int i = 0; i < filas; i++) {
            cout << matriz[i][x] << " ";
        }
        cout << endl;
    }
}

void imprimirMatrizInversa(const vector<vector<int>>& matriz){
    int filas = matriz.size();
    int cols = matriz[0].size();
    
    for (int x = cols-1; x >= 0; x--) {
        for (int i = 0; i < filas; i++) {
            cout << matriz[i][x] << " ";
        }
        cout << endl;
    }
}

void mochila(vector<vector<int>>& matriz, const vector<vector<int>>& pesosValor) {
    int n = matriz.size() - 1; 
    int W = matriz[0].size() - 1;

    for (int i = 1; i <= n; i++) {
        int v = pesosValor[i][0];
        int w = pesosValor[i][1];
        for (int x = 1; x <= W; x++) {
            if (x - w >= 0)
                matriz[i][x] = max(matriz[i-1][x], matriz[i-1][x-w] + v);
            else
                matriz[i][x] = matriz[i-1][x];
        }
    }
}

int main() {
    int W = 10; 
    vector<vector<int>> pesosValor = {
        {0,0},   
        {30,6},   
        {14,3},   
        {16,4},   
        {9,2},   
    };
    int n = pesosValor.size(); 
    vector<vector<int>> miMatriz = crearMatriz(W+1, n);

    mochila(miMatriz, pesosValor);

    cout << "Matriz Respuesta):" << endl;
    imprimirMatrizInversa(miMatriz);

    cout << "Valor óptimo: " << miMatriz[n-1][W] << endl;
    return 0;
}
