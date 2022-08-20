#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void Merge(int* arr, int inicio, int mid, int fin) {
	int size = (fin - inicio);
   int i = inicio;
   int j = mid;
   int* slice = new int[size];

	for (int k = 0; k < size; k++) {
		if (i > (mid - 1) && j <= (fin - 1)) {
			slice[k] = arr[j];
			j++;
		} else if (j > (fin - 1) && i <= (mid - 1)) {
			slice[k] = arr[i];
			i++;
		} else if (arr[i] < arr[j]) {
			slice[k] = arr[i];
			i++;
		} else {
			slice[k] = arr[j];
			j++;
		}
	}
   i = inicio;
   for (int k = 0; k < size; k++) {
      arr[i] = slice[k];
      i++;
   }
	return;
}

void MergeSort(int* arr, int inicio, int fin) {

   if ((fin - inicio) < 2) {
		return;
	}
   int mid = (fin - inicio) / 2;
   MergeSort(arr, inicio, (inicio + mid));
   MergeSort(arr, (inicio + mid), fin);
   Merge(arr, inicio, (inicio + mid), fin);
	return;
}


int main() {
   //int arr[9] = {4, 1, 5, 8, 9, 3, 2, 6, 7};
   int n;
   int* arr;
   int tam;
   unsigned t0, t1;
   double tiempo;
   //cout << RAND_MAX << endl;
   srand(time(0));
   int pruebas[15] = {100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000};
   //int pruebas[1] = {50000};
   for (int j = 0; j < 15; j++) {
      tam = pruebas[j];
      cout << "Para " << tam << ":" << endl;
      arr = new int[tam];
      for (int i = 0; i < tam; i++) {
         arr[i] = rand()*rand();
      }
      t0 = clock();
      auto start = chrono::high_resolution_clock::now();
      MergeSort(arr, 0, tam);
      auto end = chrono::high_resolution_clock::now();
      t1 = clock();
      tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
      cout << "Execution Time: " << tiempo << endl;
      chrono::duration<double, std::milli> float_ms = end - start;
      auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      chrono::duration<long, std::micro> int_usec = int_ms;
      cout << "Execution Time 2: " << float_ms.count() << "( " << int_ms.count() << " milliseconds )" << endl;
      delete arr;
   }
   /*
   // Para 100
   tam = 100;
   cout << "Para " << tam << ":" << endl;
   arr = new int[tam];
   for (int i = 0; i < tam; i++) {
      arr[i] = rand();
   }
   //for (int i = 0; i < tam; i++) {
   //   cout<<arr[i]<<"\t";
   //}
   t0=clock();
   MergeSort(arr, 0, tam);
   t1 = clock();
   //for (int i = 0; i < tam; i++) {
   //   cout<<arr[i]<<"\t";
   //}
   tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "Execution Time: " << tiempo << endl;
   //cout << endl;
   // Para 1000
   tam = 1000;
   cout << "Para " << tam << ":" << endl;
   arr = new int[tam];
   for (int i = 0; i < tam; i++) {
      arr[i] = rand();
   }
   t0=clock();
   MergeSort(arr, 0, tam);
   t1 = clock();
   //for (int i = 0; i < tam; i++) {
   //   cout<<arr[i]<<"\t";
   //}
   tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "Execution Time: " << tiempo << endl;
   //cout << endl;
   // Para 2000
   tam = 2000;
   cout << "Para " << tam << ":" << endl;
   arr = new int[tam];
   for (int i = 0; i < tam; i++) {
      arr[i] = rand();
   }
   t0=clock();
   MergeSort(arr, 0, tam);
   t1 = clock();
   //for (int i = 0; i < tam; i++) {
   //   cout<<arr[i]<<"\t";
   //}
   tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "Execution Time: " << tiempo << endl;
   //cout << endl;
   // Para 3000
   tam = 3000;
   cout << "Para " << tam << ":" << endl;
   arr = new int[tam];
   for (int i = 0; i < tam; i++) {
      arr[i] = rand();
   }
   t0=clock();
   MergeSort(arr, 0, tam);
   t1 = clock();
   //for (int i = 0; i < tam; i++) {
   //   cout<<arr[i]<<"\t";
   //}
   tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "Execution Time: " << tiempo << endl;
   //cout << endl;
   // Para 4000
   tam = 4000;
   cout << "Para " << tam << ":" << endl;
   arr = new int[tam];
   for (int i = 0; i < tam; i++) {
      arr[i] = rand();
   }
   t0=clock();
   MergeSort(arr, 0, tam);
   t1 = clock();
   //for (int i = 0; i < tam; i++) {
   //   cout<<arr[i]<<"\t";
   //}
   tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "Execution Time: " << tiempo << endl;
   //cout << endl;
   // Para 5000
   tam = 5000;
   cout << "Para " << tam << ":" << endl;
   arr = new int[tam];
   for (int i = 0; i < tam; i++) {
      arr[i] = rand();
   }
   t0=clock();
   MergeSort(arr, 0, tam);
   t1 = clock();
   //for (int i = 0; i < tam; i++) {
   //   cout<<arr[i]<<"\t";
   //}
   tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "Execution Time: " << tiempo << endl;
   //cout << endl;
   // Para 6000
   tam = 6000;
   cout << "Para " << tam << ":" << endl;
   arr = new int[tam];
   for (int i = 0; i < tam; i++) {
      arr[i] = rand();
   }
   t0=clock();
   MergeSort(arr, 0, tam);
   t1 = clock();
   tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
   cout << "Execution Time: " << tiempo << endl;
   */
   //cin.ignore();
   //cin.get();
   return 0;
}