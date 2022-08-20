import time
import datetime
from random import seed
from random import randint

def MergeSort(arr, inicio, fin):
    if ((fin - inicio) < 2):
       return
    mid = (fin - inicio) / 2
    MergeSort(arr, inicio, (inicio + mid))
    MergeSort(arr, (inicio + mid), fin)
    Merge(arr, inicio, (inicio + mid), fin)

def Merge(arr, inicio, mid, fin):
    size, i, j = (fin - inicio), inicio, mid
    sli = []
    for k in range (0, size):
        if i > (mid - 1) and j <= (fin - 1):
           sli.append(arr[j])
           j = j + 1
        elif j > (fin - 1) and i <= (mid - 1):
           sli.append(arr[i])
           i = i + 1
        elif arr[i] < arr[j]:
           sli.append(arr[i])
           i = i + 1
        else:
           sli.append(arr[j])
           j = j + 1
    i = inicio
    for k in range (0, size):
        arr[i] = sli[k]
        i = i + 1

def main():
    #a = [4, 1, 5, 8, 9, 3, 2, 6, 7]
    seed()
    pruebas = [100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000]
    #pruebas = [50000]
    for j in range (0, 15):
        tam = pruebas[j]
        print "Para ", tam, ":"
        arr = []
        for i in range (0, tam):
            arr.append(randint(0, 500000))
        #print arr
        t0 = datetime.datetime.now()
        inicio = time.time()
        MergeSort(arr, 0, tam)
        t1 = datetime.datetime.now()
        fin = time.time()
        procesamiento = fin - inicio
        td = t1 - t0
        print "Tiempo de ejecucion: " + format((procesamiento*1000), ".4f")
        print td.total_seconds()
        #print arr

main()
