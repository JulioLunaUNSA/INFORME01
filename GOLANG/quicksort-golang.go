package main

import (
	//"fmt"
	//"math"
	"math/rand"
	"time"
)

func generaLista(size int) []int {

	slice := make([]int, size, size)
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < size; i++ {
		slice[i] = rand.Intn(99999) - rand.Intn(99999)
	}
	return slice
}

func particionado(lista []int, menor int, mayor int) ([]int, int) {
	pivot := lista[mayor]
	i := menor
	for j := menor; j < mayor; j++ {
		if lista[j] < pivot {
			lista[i], lista[j] = lista[j], lista[i]
			i++
		}
	}
	lista[i], lista[mayor] = lista[mayor], lista[i]
	return lista, i
}

func quickSort(lista []int, menor, mayor int) []int {
	if menor < mayor {
		var p int
		lista, p = particionado(lista, menor, mayor)
		lista = quickSort(lista, menor, p-1)
		lista = quickSort(lista, p+1, mayor)
	}
	return lista
}

/*
func main() {

	var tam int
   pruebas := []int {100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000}
	//pruebas := []int {100}
	for j := 0; j < 15; j++ {
		tam = pruebas[j]
      fmt.Println("Para ", tam, ":")
		lista := generaLista(tam)
		//fmt.Printf("El array desordenado es: %v\n", lista)
		t0 := time.Now()
		quickSort(lista, 0, len(lista)-1)
		t1 := time.Now()
		//fmt.Printf("El array ordenado es: %v\n", lista)
      fmt.Println(t1.Sub(t0))
		//fmt.Println(time.Duration(time.Since(t1).Milliseconds()))
	}

	/*
	lista := generaLista(5)
	var procesamiento []time.Duration
	promedio := 0.0
	sumatoria := 0.0
	desviacion := 0.0
	desviacionEstandar := 0.0

	for i := 0; i < 5; i++ {
		start := time.Now()
		quickSort(lista, 0, len(lista)-1)
		fmt.Println(lista)
		procesamiento = append(procesamiento, time.Duration(time.Since(start).Milliseconds()))
	}

	for _, item := range procesamiento {
		sumatoria += float64(item)
	}

	promedio = sumatoria / float64(len(procesamiento))

	for _, item := range procesamiento {
		desviacion += math.Pow(float64(item)-promedio, 2)
	}

	desviacionEstandar = math.Sqrt(float64(desviacion / float64(len(procesamiento))))
	fmt.Println("Promedio de tiempo de ejecucion :", promedio)
	fmt.Println("Desviacion Estandar :", desviacionEstandar)
}
*/
