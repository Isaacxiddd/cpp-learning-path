TITLE: Prestadores médicos
TAGS: Problema [[Nivel básico]]

Se desea medir la evolución del rendimiento que tuvo un centro de salud,  contrastando las prestaciones médicas que se realizaron durante los dos últimos años. Para esto, disponemos de los archivos: `PRESTA19.dat` y `PRESTA20.dat`, que contienen la información de las prácticas que realizaron los médicos y técnicos que trabajan (o trabajaron) en dicho centro de salud durante los años 2019 y 2020 respectivamente. Y el archivo `PRACTICAS.dat`, que describe el catálogo de todas prestaciones disponibles.

```cpp
// Archivos: PRESTA19.dat y PRESTA20.dat
struct Presta
{
   int idPres; 
   int idPrac; 
   long long fechaHora; // aaaammddhhmm
   int minutos;
};
```
```cpp
// Archivo: PRACTICAS.dat
struct Practica
{
   int idPrac; 
   char descr[50];
};
```

Los archivos `PRESTA19.dat` y `PRESTA20.dat` se encuentran ordenados  ascendentemente por `idPres`+`fechaHora`.

!!! Se pide:

# Un listado, ordenado decrecientemente por `idPres`, de los prestadores que se incorporaron en 2020.

# Para los prestadores que sí trabajaron durante 2019 y 2020, un listado de las prácticas que realizaron; ordenado decrecientemente por `fechaHora`.

# Para los prestadores que sólo trabajaron durante 2019, un listado indicando la cantidad de prácticas realizadas

Se desea medir la evolución del rendimiento que tuvo un centro de salud,  contrastando las prestaciones médicas que se realizaron durante los dos últimos años. Para esto, disponemos de los archivos: `PRESTA19.dat` y `PRESTA20.dat`, que contienen la información de las prácticas que realizaron los médicos y técnicos que trabajan (o trabajaron) en dicho centro de salud durante los años 2019 y 2020 respectivamente. Y el archivo `PRACTICAS.dat`, que describe el catálogo de todas prestaciones disponibles.

```cpp
// Archivos: PRESTA19.dat y PRESTA20.dat
struct Presta
{
   int idPres; 
   int idPrac; 
   long long fechaHora; // aaaammddhhmm
   int minutos;
};
```
```cpp
// Archivo: PRACTICAS.dat
struct Practica
{
   int idPrac; 
   char descr[50];
};
```

Los archivos `PRESTA19.dat` y `PRESTA20.dat` se encuentran ordenados  ascendentemente por `idPres`+`fechaHora`.

!!! Se pide:

# Un listado, ordenado decrecientemente por `idPres`, de los prestadores que se incorporaron en 2020.

# Para los prestadores que sí trabajaron durante 2019 y 2020, un listado de las prácticas que realizaron; ordenado decrecientemente por `fechaHora`.

# Para los prestadores que sólo trabajaron durante 2019, un listado indicando la cantidad de prácticas realizadas