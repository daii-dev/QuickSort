#include <iostream> //biblioteca estandar para c++
#include <vector>
using namespace std;

void swap(int &a,int &b){
    int aux = a;
    a = b;
    b = aux;
}

int particion(vector<int>&array,int inicio, int fin){
    int pivote = array[inicio];
    int i = inicio + 1;
    for(int j = i; j <= fin; j++){
        if(array[j] < pivote){
            swap(array[i],array[j]);
            i++;
        }
    }
    swap(array[inicio],array[i-1]);
    return i-1;
}

void quickSort(vector<int>&array, int inicio, int final){
    if(inicio < final){
        int pivote = particion(array,inicio,final);
        quickSort(array,inicio,pivote-1);
        quickSort(array,pivote+1,final);
    }
}

void imprimirArreglo(vector<int>arreglo){  
    for(int i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int>arreglo = {15,0,2,10,20,17,5};
    imprimirArreglo(arreglo);
    quickSort(arreglo,0,arreglo.size()-1);
    imprimirArreglo(arreglo);
    return 0;
}