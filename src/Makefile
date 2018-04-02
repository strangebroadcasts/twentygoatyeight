CC	= /opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j

.PHONY: all clean build test
all: test build

test:
	gcc game.c -c -o tests/game.o
	gcc tests/tests.c tests/game.o -o tests/tests
	tests/tests

build: main.gb
	cp main.gb ../bin/

%.o:	%.c
	$(CC) -c -o $@ $<

%.s:	%.c
	$(CC) -S -o $@ $<

%.o:	%.s
	$(CC) -c -o $@ $<

main.gb: tiles.o main.o game.o
	$(CC) -o main.gb tiles.o main.o game.o

clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm
	rm -f tests/game.o tests/tests