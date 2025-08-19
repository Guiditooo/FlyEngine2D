@echo off
REM --- Parámetros ---
set "OUT_DIR=%~1"                          # $(OutDir)
set "GLFW3_DLL_DEST=%~2"                   # Ruta completa destino glfw3.dll
set "GLEW32_DLL_DEST=%~3"                  # Ruta completa destino glew32.dll
set "PROJECT_DIR=%~4"                       # $(ProjectDir)

REM --- Extraer carpetas base de las rutas destino ---
for %%A in ("%GLFW3_DLL_DEST%") do set "GLFW3_DIR=%%~dpA"
for %%A in ("%GLEW32_DLL_DEST%") do set "GLEW32_DIR=%%~dpA"

REM --- Copiar DLL y LIB del Engine (como antes) ---
copy /y "%OUT_DIR%\FlyEngine2D.dll" "$(SolutionDir)FlyEngine2D_Game\Dependencies\FlyEngine2D\dll\"
copy /y "%OUT_DIR%\FlyEngine2D.lib" "$(SolutionDir)FlyEngine2D_Game\Dependencies\FlyEngine2D\library\"

REM --- Copiar GLFW/GLEW (solo si no existen) ---
if not exist "%GLFW3_DLL_DEST%" (
    copy "%PROJECT_DIR%Dependencies\GLFW\dll\glfw3.dll" "%GLFW3_DIR%"
    echo [OK] glfw3.dll copiado a %GLFW3_DIR%
)

if not exist "%GLEW32_DLL_DEST%" (
    copy "%PROJECT_DIR%Dependencies\GLEW\dll\glew32.dll" "%GLEW32_DIR%"
    echo [OK] glew32.dll copiado a %GLEW32_DIR%
)

echo Proceso completado.