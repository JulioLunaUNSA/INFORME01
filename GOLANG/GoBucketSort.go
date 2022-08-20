package main

/*
import (
	"fmt"
	//"os"
	//"strconv"
	"math/rand"
	"time"
)
*/

func insertionSort(array []int) {
	for i := 0; i < len(array); i++ {
		temp := array[i]
		j := i - 1
		for ; j >= 0 && array[j] > temp; j-- {
			array[j+1] = array[j]
		}
		array[j+1] = temp
	}
}

func bucketSort(array []int, bucketSize int) []int {
	var max, min int
	for _, n := range array {
		if n < min {
			min = n
		}
		if n > max {
			max = n
		}
	}
	nBuckets := int(max-min)/bucketSize + 1
	buckets := make([][]int, nBuckets)
	for i := 0; i < nBuckets; i++ {
		buckets[i] = make([]int, 0)
	}

	for _, n := range array {
		idx := int(n-min) / bucketSize
		buckets[idx] = append(buckets[idx], n)
	}

	sorted := make([]int, 0)
	for _, bucket := range buckets {
		if len(bucket) > 0 {
			insertionSort(bucket)
			sorted = append(sorted, bucket...)
		}
	}

	return sorted
}

/*
func main() {

	//array := []int{8, 5, 6, 12, 7, 3}
	/*
	for _, arg := range os.Args[1:] {
		if n, err := strconv.ParseFloat(arg, 64); err == nil {
			array = append(array, n)
		}
	}
	*/
	/*
	var tam int
   rand.Seed(time.Now().UnixNano())
   pruebas := []int {100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000}
	//pruebas := []int {100}
	for j := 0; j < 15; j++ {
      tam = pruebas[j]
      fmt.Println("Para ", tam, ":")
      arr := make([]int, tam, tam)
      for i := 0; i < tam; i++ {
         arr[i] = rand.Intn(500000)
      }
		t0 := time.Now()
	   //fmt.Printf("El array desordenado es: %v\n", arr)
	   arr = bucketSort(arr, 5)
		t1 := time.Now()
		//fmt.Printf("El array ordenado es: %v\n", arr)
      fmt.Println(t1.Sub(t0))
	}
}
*/