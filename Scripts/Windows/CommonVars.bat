rem @echo off

set DEVEL_DIR=e:\f

REM Directory where this file is located
set BUILD_SCRIPT_DIR=%~dp0

set GIT_EXE="c:\Program Files\Git\bin\git.exe"
set PATCH_EXE="c:\Program Files\Git\usr\bin\patch.exe"
set CMAKE_EXE="c:\Program Files\CMake\bin\cmake.exe"
set CPACK_EXE="c:\Program Files\CMake\bin\cpack.exe"
set CTEST_EXE="c:\Program Files\CMake\bin\ctest.exe"

set QT5_DIR_X64=C:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5

set CMAKE_GENERATOR_X64="Visual Studio 17 2022"

set FIRSTTASKCUSTOMAPP_SOURCE_DIR=%DEVEL_DIR%\FirstTaskApp
set FIRSTTASKCUSTOMAPP_SUPERBUILD_BIN_DIR_DBG_X64=%DEVEL_DIR%\fD
set FIRSTTASKCUSTOMAPP_SUPERBUILD_BIN_DIR_REL_X64=%DEVEL_DIR%\fR
set SLICER_BIN_DIR_DBG_X64=%FIRSTTASKCUSTOMAPP_SUPERBUILD_BIN_DIR_DBG_X64%\Slicer-build
set SLICER_BIN_DIR_REL_X64=%FIRSTTASKCUSTOMAPP_SUPERBUILD_BIN_DIR_REL_X64%\Slicer-build

set PATH=%PATH%;c:\Program Files\Git\bin;c:\Program Files\Git\usr\bin
