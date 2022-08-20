#Universidad Nacional de San Agustin
#Maestria en Ciencias de la Computacion
#Buscador de Numeros Primos en Phyton
#Curso Algoritmos y Estructuras de Datos

import time
import datetime

def Buscador_Primos(n):
    #n=int(input("Introduce un numero: "))
    for i in range(2,n+1):
        contador=0
        for j in range(1,n+1):
            if i%j==0:
               contador+=1
        if contador==2:
           #print(i)
           continue

def main():
    pruebas = [100, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000]
    for j in range (0, 15):
        numero = pruebas[j]
        print "Para ", numero, ":"
        t0 = datetime.datetime.now()
        inicio = time.time()
        Buscador_Primos(numero)
        t1 = datetime.datetime.now()
        fin = time.time()
        procesamiento = fin - inicio
        td = t1 - t0
        print "Tiempo de ejecucion: " + format((procesamiento*1000), ".4f")
        print td.total_seconds()

main()