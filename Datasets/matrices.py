import random

def generar_dataset(tamañosss, archivo_salida):
    with open(archivo_salida, 'w') as archivo:
        archivo.write(f"{tamañosss}\n")
        
        # Generar la matriz A
        for i in range(tamañosss):
            fila = " ".join(str(random.randint(0, 100)) for _ in range(tamañosss))
            archivo.write(f"{fila}\n")
        
        # Generar la matriz B
        for i in range(tamañosss):
            fila = " ".join(str(random.randint(0, 100)) for _ in range(tamañosss))
            archivo.write(f"{fila}\n")

# Establecer una semilla fija para generar valores reproducibles
random.seed(42)

# Tamaño grande de la matriz
tamaños_grande = 1000
archivo_grande = "matrices_grandes.txt"

# Tamaño pequeño de la matriz
tamaños_pequeño = 100
archivo_pequeño = "matrices_pequeñas.txt"

# Generar el dataset de tamaño grande
generar_dataset(tamaños_grande, archivo_grande)
# Generar el dataset de tamaño pequeño
generar_dataset(tamaños_pequeño, archivo_pequeño)
