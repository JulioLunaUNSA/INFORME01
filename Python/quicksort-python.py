import time
#import statistics
import random
import datetime
import sys
from random import seed

sys.setrecursionlimit(5000)

def generarLista(tamanio):

    lista = []
    for x in range(tamanio):
        lista.append(random.randrange(0, 99999, 1))
        
    return lista
        

def particionado(lista, menor, mayor):

    pivote = lista[menor]
    izq = menor + 1
    der = mayor

    while True:

        while izq <= der and lista[izq] <= pivote:
            izq += 1

        while izq <= der and lista[der] >= pivote:
            der -= 1

        if der < izq:
            break
        else:
            lista[izq], lista[der] = lista[der], lista[izq]

    lista[menor], lista[der] = lista[der], lista[menor]

    return der

def quicksort(lista, menor, mayor):
    
    if menor < mayor:

        pivote = particionado(lista, menor, mayor)
        quicksort(lista, menor, pivote - 1)
        quicksort(lista, pivote + 1, mayor)
    
def main():
    seed()

    pruebas = [100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000]
    #pruebas = [1000]
    for j in range (0, 15):
        procesamiento = 0
        tam = pruebas[j]
        print "Para ", tam, ":"
        lista = generarLista(tam)
        t0 = datetime.datetime.now()
        inicio = time.time()
        quicksort(lista, 0, len(lista)-1)
        t1 = datetime.datetime.now()
        fin = time.time()
        procesamiento = fin - inicio
        td = t1 - t0
        #print(lista)
        #print("Tiempo de ejecucion: ", procesamiento)
        print "Tiempo de ejecucion: " + format((procesamiento*1000), ".4f")
        print td.total_seconds()


    ##lista = [9,1,4,7,5,3,8,23]
    #lista = generarLista(50000)
    #procesamiento = 0

    ##for x in range(5):
    ##    inicio = time.time()
    ##    quicksort(lista, 0, len(lista)-1)
    ##    print(lista)
    ##    fin = time.time()
    ##    procesamiento.append(fin - inicio)
      
    #inicio = time.time()
    #quicksort(lista, 0, len(lista)-1)
    #print(lista)
    #fin = time.time()
    #procesamiento = fin - inicio
    ##desviacion = statistics.pstdev(procesamiento)
    ##promedio = statistics.mean(procesamiento)
    #print("Tiempo de ejecucion: ", procesamiento)
    ##print("Desviacion estandar: ", desviacion)

main()


