all: build/glc_4_ruecker.bin 

build/glc_4_ruecker.bin: glc_4_ruecker_05102023.c 
	g++ -o glc_4_ruecker.bin glc_4_ruecker_05102023.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean