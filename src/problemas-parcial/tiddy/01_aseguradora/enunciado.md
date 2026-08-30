TITLE: Aseguradora de riesgos del trabajo
TAGS: Problema [[Nivel básico]]

Una ART (Aseguradora de Riesgos del Trabajo) ajusta anualmente las tarifas que sus clientes (empresas) deben pagar según la cantidad de accidentes denunciados por los empleados de las empresas aseguradas.

Se dispone de los archivos `EMPRESAS.dat`, con la información de las empresas que contratan los servicios de la ART, y `ACCIDENTES.dat`, con los accidentes de denunciados.

```cpp
struct Empresa
{
   int idEmpresa;
   char razonSocial[100];
   int cantTrabAsegurados; 
};
```

```cpp
struct Accidente
{
   int idEmpresa;
   int legajo;
   Fecha fecha; 
   int cantDiasLicencia;
};
```

El archivo `ACCIDENTES.dat` contiene un registro por cada accidente denunciado por los trabajadores de las empresas aseguradas, y almacena la información correspondiente al año anterior al actual. Un mismo trabajador podría haber sufrido más de un accidente durante dicho periodo laboral. Si una persona trabaja para más de una empresa, tendrá un legajo diferente para cada una de ellas.

Se dispone de la función porcentaje, cuyo prototipo veremos enseguida, 
que retorna el porcentaje de reajuste en función de la cantidad de trabajadores asegurados y la cantidad de accidentes denunciados por dichos trabajadores.

```cpp
double porcentaje(int cantTrabajadores,int cantAccidentes);
```

Considere que `Fecha` es un TAD, y sus funciones (todas las que estime 
necesarias) están a disposición y pueden ser utilizadas sin necesidad de desarrollarlas.

!!! Se pide:

# Imprimir el siguiente listado, con una línea por cada una de las empresas que contratan los servicios de la ART. <div>

|>|LISTADO DE PORCENTAJE DE REAJUSTE|
|Razón social |Porcentaje (%)|
|xxxxxxxxxxxxxxx | 99.99|
|xxxxxxxxxxxxxxx | 99.99|
|xxxxxxxxxxxxxxx | 99.99|
|: | :|
</div>

# Emitir un listado, ordenado por `idEmpresa`, detallando los trabajadores accidentados e indicando el total de días que estuvieron ausentes por los accidentes laborales sufridos.<div>

|>|Razón social: xxxxxxxxxxxxxxxxx|
|Legajo |Total de días ausente |
| 99999| 999|
| 99999| 999|
| :| :|
</div>
