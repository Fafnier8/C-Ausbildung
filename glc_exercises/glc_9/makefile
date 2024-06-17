all: build/glc_9_ruecker.bin 

build/glc_9_ruecker.bin: glc_9_ruecker.c 
	g++ -o glc_9_ruecker.bin glc_9_ruecker.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean