all: build/modul_06_string.bin 

build/modul_06_string.bin: modul_06_string.c 
	g++ -o modul_06_string.bin modul_06_string.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean