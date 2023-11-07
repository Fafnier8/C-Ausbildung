all: build/modul_07_pointer.bin 

build/modul_07_pointer.bin: modul_07_pointer.c 
	g++ -o modul_07_pointer.bin modul_07_pointer.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean