package main

/*
import (
   "fmt"
   "time"
)
*/

func Buscador_Primos(primMax int) {

    var primNum, primcount int

    //fmt.Print("Introduce un numero: ")
    //fmt.Scanln(&primMax)

    //fmt.Println("Numeros primos entre 1 y ", primMax, " son ")
    for primNum = 1; primNum <= primMax; primNum++ {
        primcount = 0
        for i := 2; i < primNum/2; i++ {
            if primNum%i == 0 {
                primcount++
                break
            }
        }
        if primcount == 0 && primNum != 1 {
            //fmt.Print(primNum, " ")
        }
    }
    //fmt.Println()
}

/*
func main() {
   var numero int
   pruebas := []int {100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000}
	//pruebas := []int {100}
   for j := 0; j < 15; j++ {
      numero = pruebas[j]
      fmt.Println("Para ", numero, ":")
      t0 := time.Now()
		Buscador_Primos(numero)
      t1 := time.Now()
      fmt.Println(t1.Sub(t0))
   }
}
*/