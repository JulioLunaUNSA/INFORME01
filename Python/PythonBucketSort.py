#BucketSort

def bucketSort(array, NroCubetas):
	max_ele = max(array)
	min_ele = min(array)

	#determinar rango
	rango = (max_ele - min_ele) / NroCubetas
	temp = []

	#crear cubetas vacias
	for i in range(NroCubetas):
		temp.append([])

	#agregar elemenots en cada cubeta
	for i in range(len(array)):
		diff = (array[i] - min_ele) / rango - int((array[i] - min_ele) / rango)

		#determinar la cubeta para agregar numero
		if(diff == 0 and array[i] != min_ele):
			temp[int((array[i] - min_ele) / rango) - 1].append(array[i])

		else:
			temp[int((array[i] - min_ele) / rango)].append(array[i])

	#ordenar cubetas independientes
	for i in range(len(temp)):
		if len(temp[i]) != 0:
			temp[i].sort()

	#elementos ordenados
	k = 0
	for lista in temp:
		if lista:
			for i in lista:
				array[k] = i
				k = k+1

import random
import datetime
from random import seed
from random import randint

def main():
    #array = []
    NroCubetas = 5

    seed()
    pruebas = [100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000]
    #pruebas = [100]
    for j in range (0, 15):
        tam = pruebas[j]
        print "Para ", tam, ":"
        arr = []
        for i in range (0, tam):
            arr.append(randint(0, 500000))
        #print("El array desordenado es:", arr)
        t0 = datetime.datetime.now()
        bucketSort(arr, NroCubetas)
        t1 = datetime.datetime.now()
        td = t1 - t0
        #print("El array ordenado es:", arr)
        print td.total_seconds()

    #for i in range(5):
    #    array.append(random.uniform(0, 100))

    

main()