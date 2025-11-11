#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> 
#include <cmath>
using namespace std;

double comparacion(vector<vector<int>> matriz){



    double resultado =0;

    vector<double> listaResultados {};

    vector<int> parAcomparar ={};
for (size_t i = 0; i < matriz.size(); i++)
{

    parAcomparar= matriz[i];
    for (size_t j = 0; j < matriz.size(); j++)
    {
        if (parAcomparar == matriz[j])
        {
          
        }else{
            cout << "comparacion:  " << parAcomparar[0]<< " - "<< parAcomparar[1]<< "  ";
        cout << "con " << matriz[j][0]<< " - " << matriz[j][1]<<endl;
            resultado= sqrt(
                (pow(((parAcomparar[0])-(matriz[j][0])), 2))
                + (pow(((parAcomparar[1])-(matriz[j][1])), 2))
            );
            cout << "resultado"<<resultado<<endl;
            listaResultados.push_back(resultado);
        }

           sort(listaResultados.begin(), listaResultados.end());


        
        
    }
    
}
double resFinal=listaResultados.back();
return resFinal;


}


void CPYTO( vector<vector<int>> matriz){

    vector<vector<int>> elemSort= matriz;
 
    sort(elemSort.begin(), elemSort.end());


    int mitad = (int)(matriz.size()/2) ;
    
    for(int i = 0; i < elemSort.size(); i++)
    {
        cout << elemSort[i][0]<< " - " <<elemSort[i][1]<<endl ;
    }
    cout << "mitad: "<< mitad<<endl;
    
    cout << "Mitad izquirda:"<<endl;
    vector<vector<int>> mitadIz={};
    for (size_t i = 0; i < mitad; i++)
    {
       mitadIz.push_back(elemSort[i]);
         cout << elemSort[i][0]<<" - " <<elemSort[i][1] <<endl;
    }
cout << " "<<endl;
cout << "Mitad derecha:"<<endl;
    
    vector<vector<int>> mitadDer={};
        for (size_t i = mitad; i < elemSort.size(); i++)
    {
       mitadDer.push_back(elemSort[i]);
       cout << elemSort[i][0]<<" - " <<elemSort[i][1]<<endl ;
    }

    double menorIz= comparacion(mitadIz);
    double menorDer= comparacion(mitadDer);
    cout << "distancia menor eucaristica mitad izquierda: "<<menorIz <<endl;
    cout << "distancia menor eucaristica mitad derecha: "<< menorDer<<endl;

    double valorMinMitad= 0;
    if (menorIz>menorDer)
    {
         cout << "Valor mínimo mitades: " <<menorDer<<endl;
         valorMinMitad = menorDer;
    }else{
        cout << "Valor mínimo mitades: " <<menorIz<<endl;
        valorMinMitad = menorIz;
    }
    
 double resultadoMitades= sqrt(
                (pow(((matriz[mitad][0])-(matriz[mitad+1][0])), 2))
                + (pow(((matriz[mitad][1])-(matriz[mitad+1][1])), 2))
            );

cout << "distancia entre mitades: "<< resultadoMitades<< endl;
    
if (resultadoMitades>valorMinMitad)
    {
         cout << "Valor mínimo final: " <<valorMinMitad<<endl;
       
    }else{
        cout << "Valor mínimo final: " <<resultadoMitades<<endl;
    
    }



}



int main(int argc, char const *argv[])
{
    CPYTO(
        {
        {4,5},
        {3,3},
        {3,1},
        {1,1},
        {2,1},
    
    });   
    return 0;
}
