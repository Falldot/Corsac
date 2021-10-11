# Corsac Project

...

# Развертывание проекта

## Windows 10

1) Установка [MinGW-W64](http://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
    * Version: 8.1.0
    * Architecture: x86_64
    * Threads: win32
    * Exception: seh
    * Build revision: 1
    * Destination Folder: Select a folder that your Windows user owns.

2) Установка Development [SDL2](https://www.libsdl.org/download-2.0.php)
    * Version: 2.0.16 mingw
    * Распакуйте архив
    * Скопируйте директорию ```SDL2-2.0.16\x86_64-w64-mingw32``` в директорию с установленным MinGW ```C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\x86_64-w64-mingw32``` с заменой
    * Установите переменные среды ```C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin``` и ```C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\x86_64-w64-mingw32\bin```

3) Копирование модуля в проект
    * Скопируйте все директории с ранее известной вам с 2 пункта директории ```SDL2-2.0.16\x86_64-w64-mingw32``` в директорию проекта ```modules\SDL2``` предварительно создав