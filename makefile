cmake:
	mkdir build && cd build && cmake -G "MinGW Makefiles" .. && cmake --build .

start:
	rmdir /S /Q build
	make cmake
	build/Corsac.exe