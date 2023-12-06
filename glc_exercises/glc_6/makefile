all: build/glc_6_ruecker.bin 

build/glc_6_ruecker.bin: glc_6_ruecker_28112023.c 
	g++ -o glc_6_ruecker.bin glc_6_ruecker_28112023.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean