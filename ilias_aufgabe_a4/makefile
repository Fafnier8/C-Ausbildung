all: build/ilias_aufgabe_a4_ruecker.bin 

build/ilias_aufgabe_a4_ruecker.bin: ilias_aufgabe_a4_ruecker.c 
	g++ -o ilias_aufgabe_a4_ruecker.bin ilias_aufgabe_a4_ruecker.c -lncurses

build:
	mkdir -p build

clean:
	rm -rf build

.PHONY: all clean