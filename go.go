package main

import (
	"fmt"
	"math/rand"
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
	n := 10000
	arr := make([]int, n)

	// Llenar el arreglo con números aleatorios entre 0 y 999999
	rand.Seed(time.Now().UnixNano())

	// Medir tiempo de ejecución
	startTime := time.Now()

	quickSort(arr, 0, n-1)

	duration := time.Since(startTime)
	fmt.Printf("Tiempo de ejecución: %v\n", duration)

	// Medir memoria usada
	var memStats runtime.MemStats
	runtime.ReadMemStats(&memStats)
	// Memoria en bytes
	fmt.Printf("Memoria usada: %v bytes (%v MB)\n", memStats.Alloc, float64(memStats.Alloc)/1024/1024)
}
