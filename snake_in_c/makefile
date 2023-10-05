all: build/snake_in_c_ruecker.bin 

build/snake_in_c_ruecker.bin: snake_in_c_ruecker.c 
	g++ -o snake_in_c_ruecker.bin snake_in_c_ruecker.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean


