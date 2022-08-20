// quicksort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime> 
#include <chrono>

using namespace std;
using std::vector;

unsigned t0, t1;

vector<int> generarLista(int tamanio) {

	vector<int>lista;
	
	for (int i = 0; i < tamanio; i++) {
		lista.push_back(rand());
	}
	return lista;
}

void swap(int &a, int &b) {
	int aux = a;
	a = b;
	b = aux;
}

int particion(vector<int>&array, int inicio, int fin) {
	int pivote = array[inicio];
	int i = inicio + 1;
	for (int j = i; j <= fin; j++) {
		if (array[j] < pivote) {
			swap(array[i], array[j]);
			i++;
		}
	}
	swap(array[inicio], array[i - 1]);
	return i - 1;
}

void quickSort(vector<int>&arreglo, int inicio, int fin) {
	if (inicio < fin) {
		int pivote = particion(arreglo, inicio, fin);
		quickSort(arreglo, inicio, pivote - 1);
		quickSort(arreglo, pivote + 1, fin);
	}
}


int main()
{
	//int arr[] = { 9, 3, 4, 2, 1, 8 };
   int tam;
   double tiempo;
   //cout << RAND_MAX << endl;
   srand(time(0));
   int pruebas[15] = {100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000};
   //int pruebas[1] = {100};
   for (int j = 0; j < 15; j++) {
      tam = pruebas[j];
      cout << "Para " << tam << ":" << endl;
      vector<int> arr = generarLista(tam);

      t0 = clock();
      auto start = chrono::high_resolution_clock::now();
	   quickSort(arr, 1, arr.size() - 1);
      auto end = chrono::high_resolution_clock::now();
      t1 = clock();
      //for (int i = 0; i < arr.size(); i++) {
	   //	 cout << arr[i] << ",";
	   //}
      tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
      cout << "Execution Time: " << tiempo << endl;
      chrono::duration<double, std::milli> float_ms = end - start;
      auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
      chrono::duration<long, std::micro> int_usec = int_ms;
      cout << "Execution Time 2: " << float_ms.count() << "( " << int_ms.count() << " milliseconds )" << endl;
   }
	
      //vector<double> procesamiento;
	   //double procesamiento;
	   //double time = 0;

	#pragma region promedio y desviacion

	//Al intentar ejecutar 5 veces el codig se produce un desboramiento de pila al llegar a
	//tercera iteracion.
		/*double sumatoria = 0;
		double promedio = 0;
		double sumatoria2 = 0;
		double variancia = 0;
		double desviacionEstandar = 0;*/
	
		/*for (int i = 0; i < 5; i++)
		{
			t0 = clock();
			quickSort(arr, 1, tamanio - 1);

			for (int i = 0; i < tamanio; i++) {
				cout << arr[i] << ",";
			}
			cout << endl;
			t1 = clock();
			time = (double(t1 - t0) / CLOCKS_PER_SEC);
			procesamiento.push_back(time);
		}*/

		/*for (int i = 0; i < 2; i++)
		{
			sumatoria += procesamiento[i];
		}

		for (int i = 0; i < 2; i++)
		{
			sumatoria2 = sumatoria2 + (arr[i] - promedio)*(arr[i] - promedio);
		}

		promedio = sumatoria / procesamiento.size();
		variancia = (double)sumatoria2 / procesamiento.size();
		desviacionEstandar = sqrt(variancia);*/
	#pragma endregion
	
	//t0 = clock();
	//quickSort(arr, 1, arr.size() - 1);

	//for (int i = 0; i < arr.size(); i++) {
	//	cout << arr[i] << ",";
	//}
	//cout << endl;
	//t1 = clock();
	//time = (double(t1 - t0) / CLOCKS_PER_SEC);
	//procesamiento = time;
	
	
	//cout << "Promedio de tiempo de ejecucion: " << procesamiento << endl;
	//cout << "Desviacion Estandar: " << desviacionEstandar;
	return 0;
}
