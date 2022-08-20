#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<ctime>
#include <iostream>
#include <chrono>

using namespace std;

void bucketSort(int array[], int n)
{
    int i, j;
    int *count = NULL;
    int mymax = array[0] + 1;

    /*obtiene el elemento mayor */
    for (i = 1; i < n; ++i)
    {
        if (mymax < (array[i] + 1))
        {
            mymax = array[i] + 1;
        }
    }

    /*con calloc esta reservando mymax bloques en memoria*/
    count = (int *) calloc(mymax, sizeof(*count));

    for (i = 0; i < n; i++)
    {
        (count[array[i]])++;
    }

    for (i = 0, j = 0; i < mymax; i++)
    {
        for (; count[i] > 0; (count[i])--)
        {
            array[j++] = i;
        }
        
    }
    free(count);  
}

int main() {

   int n, i, MAXIMO;
   MAXIMO = 500000;
   int* arr;

   //printf("Ingresa cantidad de numeros aleatorios: ");
   //scanf("%d", &n);

   //printf("Ingresa el valor maximo de numero aleatorio : ");
   //scanf("%d", &MAXIMO);

   int tam;
   unsigned t0, t1;
   double tiempo;
   //cout << RAND_MAX << endl;
   srand(time(0));
   int pruebas[15] = {100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000};
   for (int j = 0; j < 15; j++) {
      tam = pruebas[j];
      cout << "Para " << tam << ":" << endl;
      //int array[tam] = { 0 };
      arr = new int[tam];

      for ( i = 0; i < tam; ++i )
      {
         arr[i] = rand() % MAXIMO;
      }
    
      //printf("\nEl array ordenado es: \n");
      t0 = clock();
      auto start = chrono::high_resolution_clock::now();
      bucketSort(arr, tam);

      //for (i = 0; i < tam; i++)
      //{
      //   printf("%d ", arr[i]);
      //}
      //printf("\n");
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