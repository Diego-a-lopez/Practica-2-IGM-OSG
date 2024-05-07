# Implementación de Rotación de Cubo con OpenSceneGraph

Este proyecto implementa el ejemplo de un cubo giratorio utilizando OpenSceneGraph (OSG).

## Descripción de la Tarea

Este proyecto es la segunda tarea del curso, donde el objetivo es implementar el ejemplo de un cubo giratorio utilizando OpenSceneGraph (OSG) con varias características agregadas incrementalmente.

- **Implementación Básica:** Implementar el cubo giratorio con la iluminación predeterminada de OSG habilitada.
- **Agregar Segundo Cubo:** Agregar un segundo cubo giratorio a la escena.
- **Agregar Segunda Luz:** Agregar una segunda fuente de luz para iluminar los cubos, junto con una pequeña geometría para representarla en la pantalla.
- **Agregar Textura(s):** Aplicar textura(s) a los cubos.

## Descargo de Responsabilidad de Derechos de Autor

Este código es parte de una tarea para el curso IGM en el programa MUEI en la Universidade da Coruña. Se atribuye a Diego Antonio López López (diego.a.lopez@udc.es) y Alejandro Rodríguez Vaquero (a.vaquero@udc.es). El código es gratuito para su uso y distribución con fines educativos.

## Instrucciones

### Requisitos Previos
- OpenSceneGraph (OSG)

### Cómo Compilar
#### Usando Makefile
Para compilar el código usando el Makefile proporcionado, ejecute el siguiente comando:
```
make
```
O usando make `<nombre_de_archivo>` para las versiones anteriores
```
make <nombre_de_archivo>
```
Reemplace `<nombre_de_archivo>` con el nombre del archivo fuente sin la extensión (`spinningcubeVx`).

#### Compilación Manual
Alternativamente, puede compilar manualmente el código utilizando el siguiente comando:
Reemplace `<nombre_ejecutable>` con el nombre deseado para el ejecutable y `<archivo_fuente>` con el nombre del archivo fuente (`spinningcubeVx.cpp`).
```
g++ -o <nombre_ejecutable> <archivo_fuente> -losg -losgViewer -losgDB -losgUtil -losgGA -lOpenThreads
```
### Cómo Ejecutar
Para ejecutar el ejecutable compilado, use el siguiente comando:
(Este comando solo hace run al ultimo archivo el cual esta cargado en el makefile como la variable TARGET)
```
make run
```
#### Ejecución Manual
Alternativamente, puede ejecutar manualmente el código utilizando el siguiente comando:
```
./<nombre_de_archivo>
```
### Archivos

en la carpeta "historicos" se mantiene una version de los archivos anteriores donde:

- `spinningcubeV1.cpp`: Implementación básica del cubo giratorio.
- `spinningcubeV2.cpp`: Implementación con un segundo cubo agregado.
- `spinningcubeV3.cpp`: Implementación con una segunda fuente de luz agregada.
- `spinningcubeV4.cpp`: Implementación con texturas aplicadas a los cubos.

## Imágenes del Gráfico de Escena
Gráfico de la escena OSG
![Diagrama-OSG](Diagrama-OSG.png)

## Muestra de ejecución
Preview del código en ejecución

![Preview](Preview.png)

