all: build/glc_8_ruecker.bin 

build/glc_8_ruecker.bin: glc_8_ruecker.c 
	g++ -o glc_8_ruecker.bin glc_8_ruecker.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean