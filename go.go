package main

import (
	"fmt"
	"runtime"
	"time"
)

func quickSort(arr []int, low, high int) {
	if low < high {
		p := partition(arr, low, high)
		quickSort(arr, low, p-1)
		quickSort(arr, p+1, high)
	}
}

func partition(arr []int, low, high int) int {
	pivot := arr[high]
	i := low - 1
	for j := low; j < high; j++ {
		if arr[j] < pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}

func main() {
	arr := []int{29, 10, 14, 37, 13, 2}

	// Forzar recolección de basura para limpiar antes de medir memoria
	runtime.GC()

	// Leer memoria antes
	var mStart runtime.MemStats
	runtime.ReadMemStats(&mStart)

	start := time.Now()

	quickSort(arr, 0, len(arr)-1)

	elapsed := time.Since(start)

	// Leer memoria después
	var mEnd runtime.MemStats
	runtime.ReadMemStats(&mEnd)

	// Calcular uso de memoria
	usedBytes := mEnd.Alloc - mStart.Alloc
	usedMB := float64(usedBytes) / (1024 * 1024)

	//fmt.Println("Arreglo ordenado:", arr)
	fmt.Printf("Tiempo de ejecución: %s\n", elapsed)
	fmt.Printf("Memoria usada: %d bytes (%.5f MB)\n", usedBytes, usedMB)
}
