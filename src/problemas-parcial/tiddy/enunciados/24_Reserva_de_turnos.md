TITLE: Reserva de turnos
TAGS: [[Nivel avanzado]] Problema

\define uniquestate() $:/hide/b$(currentTiddler)$

Se dispone del archivo `RESERVAS.dat`, cuyos registros describen las reservas preliminares de turnos que los pacientes de un centro médico solicitaron para realizarse diferentes prácticas. Los turnos se asignan de lunes a viernes entre las 8 y las 20 horas, y tienen una duración de 20 minutos cada uno. Aunque dependiendo de cuál sea la práctica, el turno podría ser doble, triple o más extenso. Todas las reservas corresponden a turnos del mes venidero. El campo `fPra` tendrá una fecha del mes próximo, de lunes a viernes, y el campo `hPra` indicará una hora dentro del horario de 8 a 20, en fragmentos de 20 minutos. Por ejemplo: 8:00, 8:20, 8:40, 9:00, etc.


Cada práctica puede ser llevada a cabo por uno o varios profesionales (numerados a partir de 1). Por esta razón, los turnos de un día a una determinada hora para una práctica especificada no se considerarán agotados hasta que todos los profesionales que la realizan tengan dichos turnos tomados.

Los registros de `RESERVAS.dat` y `PRACTICAS.dat` (con las prácticas que pueden realizarse en el centro médico) tienen las siguientes estructuras:

```cpp
struct Reserva
{
   int idRes;
   int idPac;
   int idPra;
   Fecha fPra; // TAD
   Hora hPra;  // TAD
};
```

```cpp
struct Practica
{
   int idPra;
   char desc[100];
   int nTurnos; // cant. req.
   int nProf;   // cant. prof.
};
```

Considere que `Fecha` y `Hora` son TAD de biblioteca. Por lo tanto, puede diseñar y utilizar cualquiera de sus funciones, siempre y cuando primero escriba su prototipo respetando todos los lineamientos y consideraciones vistos en clase.


!!! Se pide: 

# Grabar en el archivo `TURNOS.dat` los turnos aceptados, considerando que un turno se aceptará sólo si:
## Existe la práctica y tiene asignado al menos un profesional (`nProf`>0).
## El turno solicitado no se solapa con otro previamente asignado.
## La cantidad de turnos que demanda la práctica no excede el horario de las 20 horas.
#	Grabar los turnos rechazados en `RECHAZADOS.dat`. <div>


```cpp
struct Reserva
{
   int idRes;
   int idPac;
   int idPra;
   Fecha fPra; // TAD
   Hora hPra;  // TAD
};
```


```cpp
struct Practica
{
   int idPra;
   char desc[100];
   int nTurnos; // cant. req.
   int nProf;   // cant. prof.
};
```
</div>

<!-- BOTON SOLUCION -->
<$reveal type="nomatch" state=<<uniquestate>> text="show"><$button set=<<uniquestate>> setTo="show">Ver solución propuesta</$button></$reveal>
<$reveal type="match" state=<<uniquestate>> text="show"><$button set=<<uniquestate>> setTo="hide">Ocultar solución</$button> <div>

<!-- SOLUCION -->

!!! Estructura de datos

La idea es tener una estructura de datos que nos permita gestionar la agenda de cada práctica, teniendo en cuenta que las prácticas puede ser llevadas a cabo por diversos profesionales los cuales atienden todos los días del mes en diferentes turnos.

En síntesis, la estructura de datos será la siguiente: 

```cpp

//   +-- idPractica   
//   |        +-- Dia del mes
//   |        |        +-- idProf
//   |        |        |     +-- 36 bool                   
//   |        |        |     |
Map<int, Map<int, Map<int, Array<bool>>>> m;
```
Gráficamente sería así:

```
m
├── idPractica_1
│   ├── día_1
│   │   ├── idProf_1
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   ├── idProf_2
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   └── ...
│   ├── día_2
│   │   ├── idProf_1
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   ├── idProf_2
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   └── ...
│   └── ...
├── idPractica_2
│   ├── día_1
│   │   ├── idProf_1
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   ├── idProf_2
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   └── ...
│   ├── día_2
│   │   ├── idProf_1
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   ├── idProf_2
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   └── ...
│   └── ...
└── ...
```

//Wrappearemos// `Practica` para agregar a cada práctica una agenda de turnos:

```cpp
struct RPractica
{
   Practica p;

   //  dia
   Map<int,AgendaDiaria> agendaDiaria;
};
```

Para que sea un poco más simple, utilizaremos un `struct` para encapsular a cada uno de estos `Map`.

```cpp
struct AgendaProf
{
   // turno
   Array<bool> turnosDisponibles;
};

struct AgendaDiaria
{
   // prof
   Map<int,AgendaProf> agendaProf;
};
```

!!! Codificación

Con la estructura de datos creada podemos analizar el `main`:

```cpp
int main()
{
   // subo las practicas y la agenda de cada una
   Map<int,RPractica> practicas = subirPracticas();

   // archivos TURNOS y RECHAZADOS
   FILE* fAcept = fopen("TURNOS.dat","w+b");
   FILE* fRech = fopen("RECHAZADOS.dat","w+b");

   // recorro y proceso las reservas
   FILE* f = fopen("RESERVAS.dat","r+b");
   Reserva r = read<Reserva>(f);
   while( !feof(f) )
   {
      procesarReserva(r,practicas,fAcept,fRech);
      r = read<Reserva>(f);
   }

   fclose(fRech);
   fclose(fAcept);
   fclose(f);
   return 0;
}
```

La función `procesarReserva` analiza la reserva, determina si será rechazada o aceptada y la graba en el archivo correspondiente. En caso de aceptarla también actualiza la agenda de la práctica.

```cpp
void procesarReserva(Reserva r,Map<int,RPractica>& practicas,FILE* fAcept,FILE* fRech)
{
   RPractica* rp = mapGet<int,RPractica>(practicas,r.idPra);

   // motivo rechazo: A
   if( rp==NULL || rp->p.nProf==0 )
   {
      // rechazo
      Rechazado rech = {r.idRes,'A'};
      write<Rechazado>(fRech,rech);
      return;
   }

   // motivo rechazo: C
   int nTurnos = rp->p.nTurnos;
   Hora hFin = horaSumarMinutos(r.hPra,nTurnos*20);
   Hora hMax = hora(20,0);

   if( horaCmp(hFin,hMax)>0 )
   {
      // rechazo
      Rechazado rech = {r.idRes,'C'};
      write<Rechazado>(fRech,rech);
      return;
   }

   // motivo rechazo: B
   int idProf = verificarSolapamiento(r,practicas);
   if( idProf<0 )
   {
      Rechazado rech = {r.idRes,'B'};
      write<Rechazado>(fRech,rech);
      return;
   }

   // turno aceptado
   Turno turno;
   turno.idPac = r.idPac;
   turno.idPra = r.idPra;
   turno.idProf = idProf;
   turno.f = r.fPra;
   turno.hd = r.hPra;

   int nMin = rp->p.nTurnos*20;
   turno.hh = horaSumarMinutos(r.hPra,nMin);

   write<Turno>(fAcept,turno);
}
```

La verdadera complejidad está en establecer si hay solapamiento o bien no hay turnos disponibles. Recordemos que hay que analizar las agendas de todos los profesionales.

La función `verificarSolapamiento` hace el análisis y retorna qué profesional será el encargado de realizar la práctica. En caso de solapamiento o falta de turnos retornará negativo.









```cpp
int verificarSolapamiento(Reserva r,Map<int,RPractica>& practicas)
{
   // obtengo el nro de turno. Ej: si hPra es 9:20 => nro sera: 5
   int nro = horaDiv(r.hPra,hora(8,00),20);

   // dia de la practica
   int dia = fechaGetDia(r.fPra);

   // obtengo la practica
   RPractica* rp = mapGet<int,RPractica>(practicas,r.idPra);

   // agenda diaria
   AgendaDiaria* aDiaria = mapGet<int,AgendaDiaria>(rp->agendaDiaria,dia);

   // itero por los profesionales
   for(int i=1; i<=rp->p.nProf; i++)
   {
      // agenda dia prof i
      AgendaProf* aProf = mapGet<int,AgendaProf>(aDiaria->agendaProf,i);

      // solapamiento ?

      bool pasaProf = false;
      for(int i=nro; i<rp->p.nTurnos;i++)
      {
         if(!arrayGet<bool>(aProf->turnosDisponibles,i) )
         {
            pasaProf = true;
            break; // siguiente profesional
         }
      }

      if( pasaProf )
      {
         continue;
      }

      // todo ok=> marco los turnos como ocupados
      for(int i=nro; i<rp->p.nTurnos;i++)
      {
         arraySet<bool>(aProf->agenda,i,false);
      }

      return i;
   }

   return -1;
}
```









Sólo queda ver cómo creamos la agenda, inicialmente con todos los turnos libres (`true`).

```cpp
Map<int,AgendaDiaria> crearAgendaDiaria(Practica practica)
{
   Map<int,AgendaDiaria> ret = map<int,AgendaDiaria>();

   // itero los dias
   for(int d=1; d<=31; d++)
   {
      AgendaDiaria adiar;
      adiar.agenda = map<int,AgendaProf>();

      // itero los profesionales
      for(int p=1; p<=practica.nProf; p++)
      {
         Array<bool> turnos = array<bool>();

         // itero los turnos (de 8 a 20 en turnos de 20 min)=>36
         for(int t=1; t<=36; t++)
         {
            arrayAdd<bool>(turnos,true); // todos libres
         }

         AgendaProf aprof;
         aprof.agenda = turnos;

         mapPut<int,AgendaProf>(adiar.agenda,p,aprof);
      }

      mapPut<int,AgendaDiaria>(ret,d,adiar);
   }

   return ret;
}
```











<!-- /SOLUCION -->
</div></$reveal>




\define uniquestate() $:/hide/b$(currentTiddler)$

Se dispone del archivo `RESERVAS.dat`, cuyos registros describen las reservas preliminares de turnos que los pacientes de un centro médico solicitaron para realizarse diferentes prácticas. Los turnos se asignan de lunes a viernes entre las 8 y las 20 horas, y tienen una duración de 20 minutos cada uno. Aunque dependiendo de cuál sea la práctica, el turno podría ser doble, triple o más extenso. Todas las reservas corresponden a turnos del mes venidero. El campo `fPra` tendrá una fecha del mes próximo, de lunes a viernes, y el campo `hPra` indicará una hora dentro del horario de 8 a 20, en fragmentos de 20 minutos. Por ejemplo: 8:00, 8:20, 8:40, 9:00, etc.


Cada práctica puede ser llevada a cabo por uno o varios profesionales (numerados a partir de 1). Por esta razón, los turnos de un día a una determinada hora para una práctica especificada no se considerarán agotados hasta que todos los profesionales que la realizan tengan dichos turnos tomados.

Los registros de `RESERVAS.dat` y `PRACTICAS.dat` (con las prácticas que pueden realizarse en el centro médico) tienen las siguientes estructuras:

```cpp
struct Reserva
{
   int idRes;
   int idPac;
   int idPra;
   Fecha fPra; // TAD
   Hora hPra;  // TAD
};
```

```cpp
struct Practica
{
   int idPra;
   char desc[100];
   int nTurnos; // cant. req.
   int nProf;   // cant. prof.
};
```

Considere que `Fecha` y `Hora` son TAD de biblioteca. Por lo tanto, puede diseñar y utilizar cualquiera de sus funciones, siempre y cuando primero escriba su prototipo respetando todos los lineamientos y consideraciones vistos en clase.


!!! Se pide: 

# Grabar en el archivo `TURNOS.dat` los turnos aceptados, considerando que un turno se aceptará sólo si:
## Existe la práctica y tiene asignado al menos un profesional (`nProf`>0).
## El turno solicitado no se solapa con otro previamente asignado.
## La cantidad de turnos que demanda la práctica no excede el horario de las 20 horas.
#	Grabar los turnos rechazados en `RECHAZADOS.dat`. <div>


```cpp
struct Reserva
{
   int idRes;
   int idPac;
   int idPra;
   Fecha fPra; // TAD
   Hora hPra;  // TAD
};
```


```cpp
struct Practica
{
   int idPra;
   char desc[100];
   int nTurnos; // cant. req.
   int nProf;   // cant. prof.
};
```
</div>

<!-- BOTON SOLUCION -->
<$reveal type="nomatch" state=<<uniquestate>> text="show"><$button set=<<uniquestate>> setTo="show">Ver solución propuesta</$button></$reveal>
<$reveal type="match" state=<<uniquestate>> text="show"><$button set=<<uniquestate>> setTo="hide">Ocultar solución</$button> <div>

<!-- SOLUCION -->

!!! Estructura de datos

La idea es tener una estructura de datos que nos permita gestionar la agenda de cada práctica, teniendo en cuenta que las prácticas puede ser llevadas a cabo por diversos profesionales los cuales atienden todos los días del mes en diferentes turnos.

En síntesis, la estructura de datos será la siguiente: 

```cpp

//   +-- idPractica   
//   |        +-- Dia del mes
//   |        |        +-- idProf
//   |        |        |     +-- 36 bool                   
//   |        |        |     |
Map<int, Map<int, Map<int, Array<bool>>>> m;
```
Gráficamente sería así:

```
m
├── idPractica_1
│   ├── día_1
│   │   ├── idProf_1
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   ├── idProf_2
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   └── ...
│   ├── día_2
│   │   ├── idProf_1
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   ├── idProf_2
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   └── ...
│   └── ...
├── idPractica_2
│   ├── día_1
│   │   ├── idProf_1
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   ├── idProf_2
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   └── ...
│   ├── día_2
│   │   ├── idProf_1
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   ├── idProf_2
│   │   │   ├── turno_1 (de 8:00 a 8:20)
│   │   │   ├── turno_2 (de 8:20 a 8:40)
│   │   │   └── ...
│   │   └── ...
│   └── ...
└── ...
```

//Wrappearemos// `Practica` para agregar a cada práctica una agenda de turnos:

```cpp
struct RPractica
{
   Practica p;

   //  dia
   Map<int,AgendaDiaria> agendaDiaria;
};
```

Para que sea un poco más simple, utilizaremos un `struct` para encapsular a cada uno de estos `Map`.

```cpp
struct AgendaProf
{
   // turno
   Array<bool> turnosDisponibles;
};

struct AgendaDiaria
{
   // prof
   Map<int,AgendaProf> agendaProf;
};
```

!!! Codificación

Con la estructura de datos creada podemos analizar el `main`:

```cpp
int main()
{
   // subo las practicas y la agenda de cada una
   Map<int,RPractica> practicas = subirPracticas();

   // archivos TURNOS y RECHAZADOS
   FILE* fAcept = fopen("TURNOS.dat","w+b");
   FILE* fRech = fopen("RECHAZADOS.dat","w+b");

   // recorro y proceso las reservas
   FILE* f = fopen("RESERVAS.dat","r+b");
   Reserva r = read<Reserva>(f);
   while( !feof(f) )
   {
      procesarReserva(r,practicas,fAcept,fRech);
      r = read<Reserva>(f);
   }

   fclose(fRech);
   fclose(fAcept);
   fclose(f);
   return 0;
}
```

La función `procesarReserva` analiza la reserva, determina si será rechazada o aceptada y la graba en el archivo correspondiente. En caso de aceptarla también actualiza la agenda de la práctica.

```cpp
void procesarReserva(Reserva r,Map<int,RPractica>& practicas,FILE* fAcept,FILE* fRech)
{
   RPractica* rp = mapGet<int,RPractica>(practicas,r.idPra);

   // motivo rechazo: A
   if( rp==NULL || rp->p.nProf==0 )
   {
      // rechazo
      Rechazado rech = {r.idRes,'A'};
      write<Rechazado>(fRech,rech);
      return;
   }

   // motivo rechazo: C
   int nTurnos = rp->p.nTurnos;
   Hora hFin = horaSumarMinutos(r.hPra,nTurnos*20);
   Hora hMax = hora(20,0);

   if( horaCmp(hFin,hMax)>0 )
   {
      // rechazo
      Rechazado rech = {r.idRes,'C'};
      write<Rechazado>(fRech,rech);
      return;
   }

   // motivo rechazo: B
   int idProf = verificarSolapamiento(r,practicas);
   if( idProf<0 )
   {
      Rechazado rech = {r.idRes,'B'};
      write<Rechazado>(fRech,rech);
      return;
   }

   // turno aceptado
   Turno turno;
   turno.idPac = r.idPac;
   turno.idPra = r.idPra;
   turno.idProf = idProf;
   turno.f = r.fPra;
   turno.hd = r.hPra;

   int nMin = rp->p.nTurnos*20;
   turno.hh = horaSumarMinutos(r.hPra,nMin);

   write<Turno>(fAcept,turno);
}
```

La verdadera complejidad está en establecer si hay solapamiento o bien no hay turnos disponibles. Recordemos que hay que analizar las agendas de todos los profesionales.

La función `verificarSolapamiento` hace el análisis y retorna qué profesional será el encargado de realizar la práctica. En caso de solapamiento o falta de turnos retornará negativo.









```cpp
int verificarSolapamiento(Reserva r,Map<int,RPractica>& practicas)
{
   // obtengo el nro de turno. Ej: si hPra es 9:20 => nro sera: 5
   int nro = horaDiv(r.hPra,hora(8,00),20);

   // dia de la practica
   int dia = fechaGetDia(r.fPra);

   // obtengo la practica
   RPractica* rp = mapGet<int,RPractica>(practicas,r.idPra);

   // agenda diaria
   AgendaDiaria* aDiaria = mapGet<int,AgendaDiaria>(rp->agendaDiaria,dia);

   // itero por los profesionales
   for(int i=1; i<=rp->p.nProf; i++)
   {
      // agenda dia prof i
      AgendaProf* aProf = mapGet<int,AgendaProf>(aDiaria->agendaProf,i);

      // solapamiento ?

      bool pasaProf = false;
      for(int i=nro; i<rp->p.nTurnos;i++)
      {
         if(!arrayGet<bool>(aProf->turnosDisponibles,i) )
         {
            pasaProf = true;
            break; // siguiente profesional
         }
      }

      if( pasaProf )
      {
         continue;
      }

      // todo ok=> marco los turnos como ocupados
      for(int i=nro; i<rp->p.nTurnos;i++)
      {
         arraySet<bool>(aProf->agenda,i,false);
      }

      return i;
   }

   return -1;
}
```









Sólo queda ver cómo creamos la agenda, inicialmente con todos los turnos libres (`true`).

```cpp
Map<int,AgendaDiaria> crearAgendaDiaria(Practica practica)
{
   Map<int,AgendaDiaria> ret = map<int,AgendaDiaria>();

   // itero los dias
   for(int d=1; d<=31; d++)
   {
      AgendaDiaria adiar;
      adiar.agenda = map<int,AgendaProf>();

      // itero los profesionales
      for(int p=1; p<=practica.nProf; p++)
      {
         Array<bool> turnos = array<bool>();

         // itero los turnos (de 8 a 20 en turnos de 20 min)=>36
         for(int t=1; t<=36; t++)
         {
            arrayAdd<bool>(turnos,true); // todos libres
         }

         AgendaProf aprof;
         aprof.agenda = turnos;

         mapPut<int,AgendaProf>(adiar.agenda,p,aprof);
      }

      mapPut<int,AgendaDiaria>(ret,d,adiar);
   }

   return ret;
}
```











<!-- /SOLUCION -->
</div></$reveal>


