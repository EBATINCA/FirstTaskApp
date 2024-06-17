REM Convenience script to copy Python-based code to build directory so that the application
REM does not have to be built during development when no C++ component is changed

@call %~dp0\CommonVars.bat

for %%M IN (FirstTask) DO (
  copy /Y %FIRSTTASKCUSTOMAPP_SOURCE_DIR%\Modules\%%M\%%M.py %SLICER_BIN_DIR_REL_X64%\lib\FirstTask-5.6\qt-scripted-modules
  copy /Y %FIRSTTASKCUSTOMAPP_SOURCE_DIR%\Modules\%%M\Resources\*.* %SLICER_BIN_DIR_REL_X64%\lib\FirstTask-5.6\qt-scripted-modules\Resources
  copy /Y %FIRSTTASKCUSTOMAPP_SOURCE_DIR%\Modules\%%M\Resources\UI\*.ui %SLICER_BIN_DIR_REL_X64%\lib\FirstTask-5.6\qt-scripted-modules\Resources\UI
  REM copy /Y %FIRSTTASKCUSTOMAPP_SOURCE_DIR%\Modules\%%M\Resources\Icons\*.* %SLICER_BIN_DIR_REL_X64%\lib\FirstTask-5.6\qt-scripted-modules\Resources\Icons
)

REM for %%M IN (FirstTask) DO (
  REM copy /Y %FIRSTTASKCUSTOMAPP_SOURCE_DIR%\Modules\%%M\Resources\*.* %SLICER_BIN_DIR_DBG_X64%\lib\FirstTask-5.6\qt-scripted-modules\Resources
  REM copy /Y %FIRSTTASKCUSTOMAPP_SOURCE_DIR%\Modules\%%M\%%M.py %SLICER_BIN_DIR_DBG_X64%\lib\FirstTask-5.6\qt-scripted-modules
  REM copy /Y %FIRSTTASKCUSTOMAPP_SOURCE_DIR%\Modules\%%M\Resources\UI\*.ui %SLICER_BIN_DIR_DBG_X64%\lib\FirstTask-5.6\qt-scripted-modules\Resources\UI
  REM copy /Y %FIRSTTASKCUSTOMAPP_SOURCE_DIR%\Modules\%%M\Resources\Icons\*.* %SLICER_BIN_DIR_DBG_X64%\lib\FirstTask-5.6\qt-scripted-modules\Resources\Icons
REM )
