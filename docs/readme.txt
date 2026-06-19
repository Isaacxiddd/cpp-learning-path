
VSCode compila el programa pero no lo ejecuta con CTRL+F11
El problema es que el proyecto está mal importado. Para confirmarlo puedes verificar lo siguiente: 
Si compilaste (por ejemplo)  principal.cpp, verifica si en VSCode, debajo de este archivo, aparece principal.exe. Eso confirmaría que el proyecto está mal importado. 
Solución intermedia: no lo ejecutes con CTRL+F11, ejecútalo desde la terminal integrada en VSCode, escribiendo:
./principal.exe [ENTER].
