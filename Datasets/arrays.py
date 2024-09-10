import random
random.seed(42)
#funcionque genera arreglos aleatorios
def arreglo_alea(tamaños, nombre_archivo):
    with open(nombre_archivo, 'w') as archivo:
        for _ in range(tamaños):
            numero = random.randint(0, 99999)  # Números entre 0 y 99999
            archivo.write(f"{numero} ")

#funcion que genera arreglos semi ordenados
def arreglo_semiordenado(tamaños, nombre_archivo):
    with open(nombre_archivo, 'w') as archivo:
        for i in range(1, tamaños + 1):
            if i % 10 == 0:
                numero = random.randint(0, 99999)  # Cada 10 elementos un número aleatorio
                archivo.write(f"{numero} ")
            else:
                archivo.write(f"{i} ")



# Tamaños de los data sets
tamaños_grande = 10**6  
tamaños_mediano = 10**5 

# Creación de los data sets de tamaño grande
arreglo_alea(tamaños_grande, "aleatorio_grande.txt")
arreglo_semiordenado(tamaños_grande, "semi_ordenado_grande.txt")

# Creación de los data sets de tamaño mediano (10^5)
arreglo_alea(tamaños_mediano, "aleatorio_mediano.txt")
arreglo_semiordenado(tamaños_mediano, "semi_ordenado_mediano.txt")
