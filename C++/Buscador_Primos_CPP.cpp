//Universidad Nacional de San Agustin
//Maestria en Ciencias de la Computacion
//Buscador de Numeros Primos en Python
//Curso Algoritmos y Estructuras de Datos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <chrono>

using namespace std;
// Función principal
void Buscador_Primos(int numero)
{
   //int numero;
   int valores;
   int primo=0;
   int divisores=0;
   //printf("Introduce un numero: ");
   //scanf(" %d",&numero);
   for(valores=1;valores<=numero;valores++)
   {
       primo=0;
       for(divisores=2;divisores<valores-1 && primo==0;divisores++)
       {
        if(valores%divisores==0) primo=1;
        }
       if(primo==0)continue;
         //printf("%d \n",valores);
   }
   return;
}

int main(int argc,char *argv[]) {
   int numero;
   unsigned t0, t1;
   double tiempo;
   srand(time(0));
   int pruebas[15] = {100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000};
   for (int j = 0; j < 15; j++) {
      numero = pruebas[j];
      cout << "Para " << numero << ":" << endl;
      t0 = clock();
      auto start = chrono::high_resolution_clock::now();
      Buscador_Primos(numero);
      auto end = chrono::high_resolution_clock::now();
      t1 = clock();
      tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
      cout << "Execution Time: " << tiempo << endl;
      chrono::duration<double, std::milli> float_ms = end - start;
      auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      chrono::duration<long, std::micro> int_usec = int_ms;
      cout << "Execution Time 2: " << float_ms.count() << "( " << int_ms.count() << " milliseconds )" << endl;
   }
   system("PAUSE");
   return 0;
}