all: build/glc_7_ruecker.bin 

build/glc_7_ruecker.bin: glc_7_ruecker.c 
	g++ -o glc_7_ruecker.bin glc_7_ruecker.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean