@echo off
REM --- Parámetros ---
set "ENGINE_RES=%~1"
set "PROJECT_RES=%~2"

REM --- Depuración: Ver rutas ---
echo Origen: %ENGINE_RES%
echo Destino: %PROJECT_RES%

if "%ENGINE_RES%"=="" (
    echo Error: Falta la ruta de origen 
    exit /b 1
)

if "%PROJECT_RES%"=="" (
    echo Error: Falta la ruta de destino 
    exit /b 1
)

REM --- Verificar carpeta origen ---
if not exist "%ENGINE_RES%\*" (
    echo Error: No se encuentra la carpeta origen: %ENGINE_RES%
    exit /b 1
)

REM --- Crear carpeta destino si no existe ---
if not exist "%PROJECT_RES%" (
    mkdir "%PROJECT_RES%" || (
        echo Error: No se pudo crear la carpeta destino: %PROJECT_RES%
        exit /b 1
    )
    echo Carpeta creada: %PROJECT_RES%
)

REM --- Copiar archivos con robocopy ---
robocopy "%ENGINE_RES%" "%PROJECT_RES%" *.* /E /XN /NJH /NJS /NDL /NC /NS /NP
if %ERRORLEVEL% GEQ 8 (
    echo Error: Fallo al copiar archivos Robocopy error: %ERRORLEVEL%
    exit /b 1
)

echo Recursos copiados exitosamente a %PROJECT_RES%
pause
exit /b 0