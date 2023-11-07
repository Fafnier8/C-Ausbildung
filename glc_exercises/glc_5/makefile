all: build/glc_5_ruecker.bin 

build/glc_5_ruecker.bin: glc_5_ruecker_01112023.c 
	g++ -o glc_5_ruecker.bin glc_5_ruecker_01112023.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean