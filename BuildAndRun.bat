@echo off
SET CMAKE_GENERATOR="Unknown Generator"
reg query "HKEY_CLASSES_ROOT\VisualStudio.DTE.16.0" >> nul 2>&1
if %ERRORLEVEL% NEQ 0 (
	SET CMAKE_GENERATOR="Visual Studio 15 2017"
) else (
	SET CMAKE_GENERATOR="Visual Studio 16 2019"
)
cmake -G %CMAKE_GENERATOR% -S . -B "proj"