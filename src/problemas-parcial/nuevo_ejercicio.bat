@echo off
setlocal enabledelayedexpansion

set BASE=%~dp0
set COUNT=0

for /d %%D in ("%BASE%ejercicio *") do (
    set /a COUNT+=1
)

set /a NEXT=COUNT+1
set NOMBRE=ejercicio %NEXT%
set DESTINO=%BASE%%NOMBRE%

mkdir "%DESTINO%"
copy "%BASE%_plantilla\principal.hpp" "%DESTINO%\principal.hpp" >nul
copy "%BASE%_plantilla\principal.cpp" "%DESTINO%\principal.cpp" >nul

echo Creado: %NOMBRE%

endlocal
