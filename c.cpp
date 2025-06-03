#include <iostream> //biblioteca estandar para c++
#include <vector>
using namespace std;

void swap(int &a,int &b){
    int aux = a;
    a = b;
    b = aux;
}

int particion(vector<int>& array, int inicio, int fin){
    int pivote = array[fin];  // se selecciona como pivote el último elemento
    int i = inicio - 1;
    for(int j = inicio; j < fin; j++){
        if(array[j] < pivote){
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[fin]);  // coloca el pivote en su posición correcta
    return i + 1;  // devuelve la posición del pivote
}

void quickSort(vector<int>& array, int inicio, int fin){
    if(inicio < fin){
        int pivote = particion(array, inicio, fin);
        quickSort(array, inicio, pivote - 1);
        quickSort(array, pivote + 1, fin);
    }
}

void imprimirArreglo(vector<int> arreglo){  
    for(int i = 0; i < arreglo.size(); i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arreglo = {15,0,2,10,20,17,5};
    imprimirArreglo(arreglo);
    quickSort(arreglo, 0, arreglo.size() - 1);
    imprimirArreglo(arreglo);
    return 0;
}
