
# coding: utf-8

# In[213]:


## PROGRAMA CREADO POR JUAN MOLINA
## INTELIGENCIA ARTIFICIAL, 5TO SEMESTRE.

from math import sqrt

## VARIABLES GLOBALES INICIO ##
lista = [17, 15, 23, 7, 9, 13]
longitudLista = len(lista)
listaOrdenada = sorted(lista)
LongitudListaOrdenada = len(listaOrdenada)
## VARIABLES GLOBALES FIN ##

## FUNCION PROMEDIO
def _promedio():
    promedio = sum(lista) / longitudLista
    return promedio

## FUNCION MODA
def _moda():
    moda = []
    seRepite = 0
    for i in lista:
        if lista.count(i) > seRepite:
            seRepite = lista.count(i)
            
    for i in lista:
        if lista.count(i) == seRepite and i not in moda:
            moda.append(i)
            
    if moda == lista:
        moda = 'Hay más de un dato que se repite.'
    return moda

## FUNCION MEDIANA
def _mediana():
    if longitudLista % 2 == 0:
        mediana =  (listaOrdenada[(LongitudListaOrdenada // 2) - 1] + listaOrdenada[LongitudListaOrdenada // 2]) // 2
    else:
        mediana = listaOrdenada[LongitudListaOrdenada // 2]
    return mediana

## FUNCION VARIANZA
def _varianza():
    resta = []
    mediaMuestra = sum(lista) // longitudLista
    for i in lista:
        resta.append(pow((i - mediaMuestra), 2))
    sumaOperacion = sum(resta)
    varianza = sumaOperacion / (longitudLista - 1)
    return varianza

## FUNCION DESVIACION ESTANDAR
def _desviacionEstandar():
    desviacionEstandar = sqrt(_varianza())
    return desviacionEstandar

print()
print("------------------------------------------------")
print("Lista:", lista)
print("Lista Ordenada:", listaOrdenada)
print("------------------------------------------------")
print("Total Datos:", longitudLista)
print("Promedio:", _promedio())
print("------------------------------------------------")
print("Dato que más se repite (MODA):", _moda())
print("------------------------------------------------")
print("Dato central (MEDIANA):", _mediana())
print("------------------------------------------------")
print("Varianza:", _varianza())
print("------------------------------------------------")
print("Desviación Estandar:", _desviacionEstandar())
print("------------------------------------------------")

