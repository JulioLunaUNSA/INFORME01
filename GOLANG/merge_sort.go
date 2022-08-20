package main

import (
	"fmt"
	"math/rand"
 "time"
)

func MergeSort(arr []int, inicio int, fin int) {

   if ((fin - inicio) < 2) {
      return;
   }
   mid := (fin - inicio) / 2
   MergeSort(arr, inicio, (inicio + mid))
   MergeSort(arr, (inicio + mid), fin)
   Merge(arr, inicio, (inicio + mid), fin)
}

func Merge(arr []int, inicio int, mid int, fin int) {
   size, i, j := (fin - inicio), inicio, mid
   slice := make([]int, size, size)
   for k := 0; k < size; k++ {
      if i > (mid - 1) && j <= (fin - 1) {
         slice[k] = arr[j]
         j++
      } else if j > (fin - 1) && i <= (mid - 1) {
         slice[k] = arr[i]
         i++
      } else if arr[i] < arr[j] {
         slice[k] = arr[i]
         i++
      } else {
         slice[k] = arr[j]
         j++
      }
   }
   i = inicio;
   for k := 0; k < size; k++ {
      arr[i] = slice[k]
      i++
   }
}

func main() {
   //a := []int {4, 1, 5, 8, 9, 3, 2, 6, 7}
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
      MergeSort(arr, 0, tam)
      t1 := time.Now()
      fmt.Println(t1.Sub(t0))
   }
}