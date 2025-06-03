package main

import (
	"fmt"
)

// swap intercambia dos elementos en el slice
func swap(array []int, i, j int) {
	aux := array[i]
	array[i] = array[j]
	array[j] = aux
}

// particion realiza la partición para quicksort
func particion(array []int, inicio, fin int) int {
	pivote := array[inicio]
	i := inicio + 1
	for j := i; j <= fin; j++ {
		if array[j] < pivote {
			swap(array, i, j)
			i++
		}
	}
	swap(array, inicio, i-1)
	return i - 1
}

// quickSort implementa el algoritmo QuickSort
func quickSort(array []int, inicio, fin int) {
	if inicio < fin {
		pivote := particion(array, inicio, fin)
		quickSort(array, inicio, pivote-1)
		quickSort(array, pivote+1, fin)
	}
}

// imprimirArreglo imprime los elementos del slice
func imprimirArreglo(array []int) {
	for _, valor := range array {
		fmt.Printf("%d ", valor)
	}
	fmt.Println()
}

func main() {
	arreglo := []int{15, 0, 2, 10, 20, 17, 5}
	imprimirArreglo(arreglo)
	quickSort(arreglo, 0, len(arreglo)-1)
	imprimirArreglo(arreglo)
}
