@echo off
setlocal

pushd %~dp0

set config=Debug
if not "%1"=="" set config=%1
if "%2"=="/F" rmdir /s /q build bin\x86

call :build x86 Win32
call :build x64 x64

REM copy licenses
type NUL > bin\LICENSE
call :copy_license ac_matcher LICENSE
call :copy_license lua-aho-corasick ac\LICENSE

goto :end

rem %1 - BUILD_DIR
rem %2 - ARCH
:build
set build_dir=%~dp0build\%1
mkdir %build_dir%

set install_prefix=%build_dir%\install
cmake -B %build_dir% -DCMAKE_INSTALL_PREFIX:STRING=%install_prefix:\=/% -A %2 --log-level VERBOSE
cmake --build %build_dir% --config %config% --target install

set bin_dir=bin\%1
mkdir %bin_dir%
xcopy %install_prefix%\bin\ac_matcher.* %bin_dir% /F /Y

exit /b

REM %1 - project name
REM %2 - LICENSE to append
:copy_license
echo +------------------------------ >> bin\LICENSE
echo ^|  %1 >> bin\LICENSE
echo +------------------------------ >> bin\LICENSE
type %2 >> bin\LICENSE
echo: >> bin\LICENSE

exit /b

:end
popd

