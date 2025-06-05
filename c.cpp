#include <iostream>
#include <vector>
#include <chrono> // librería para medir el tiempo
#include <iomanip> // librería para controlar la precisión de la salida
#include <windows.h> // librería para obtener información sobre el proceso
#include <psapi.h>   // librería para el uso de GetProcessMemoryInfo

using namespace std;
using namespace chrono; // para usar chrono

// Función para obtener el uso de memoria del proceso
void mostrarMemoria() {
    // Obtener el handle del proceso actual
    HANDLE hProcess = GetCurrentProcess();
    
    // Estructura para almacenar información sobre el uso de memoria
    PROCESS_MEMORY_COUNTERS pmc;
    
    // Obtener la información de memoria
    if (GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
        cout << "Memoria utilizada: " << pmc.WorkingSetSize / 1024 << " KB" << endl; // Trabajando en memoria
    } else {
        cout << "Error al obtener el uso de memoria." << endl;
    }
}

void swap(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int particion(vector<int>& array, int inicio, int fin) {
    int pivote = array[inicio];
    int i = inicio + 1;
    for (int j = i; j <= fin; j++) {
        if (array[j] < pivote) {
            swap(array[i], array[j]);
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[inicio], array[i - 1]);
    return i - 1;
}

void quickSort(vector<int>& array, int inicio, int final) {
    if (inicio < final) {
        int pivote = particion(array, inicio, final);
        quickSort(array, inicio, pivote - 1);
        quickSort(array, pivote + 1, final);
    }
}

int main() {
    vector<int> arreglo = {18, 13, 99, 64, 33, 40, 2, 93, 25, 60, 88, 90};
    
    /*
    int n = 1000000;
    vector<int> arreglo(n);

    // Llenar el arreglo con números aleatorios entre 0 y 999999
    for (int i = 0; i < n; i++) {
        arreglo[i] = rand() % n;
    }
    */
    // Mostrar memoria antes de la ejecución
    mostrarMemoria();

    // Inicia la medición del tiempo
    auto start = high_resolution_clock::now();

    // Ejecutar el algoritmo QuickSort
    quickSort(arreglo, 0, arreglo.size() - 1);

    // Finaliza la medición del tiempo
    auto stop = high_resolution_clock::now();

    // Calcula la duración en nanosegundos
    auto duration = duration_cast<nanoseconds>(stop - start);

    // Mostrar el tiempo de ejecución en nanosegundos
    cout << "Tiempo de ejecución: " << fixed << setprecision(6) << duration.count() << " nanosegundos" << endl;

    // Mostrar memoria después de la ejecución
    mostrarMemoria();

    return 0;
}
