CC = gcc
FLAG = -c 



all: main.o readText.o deleteCopy.o specialSymbols.o 
	$(CC) main.o readText.o deleteCopy.o specialSymbols.o 

main.o: main.c readText.h deleteCopy.h specialSymbols.h deleteOdd.h
	$(CC) $(FLAG) main.c

readText.o: readText.h readText.c
	$(CC) $(FLAG) readText.c

deleteCopy.o: deleteCopy.h deleteCopy.c
	$(CC) $(FLAG) deleteCopy.c

specialSymbols.o: specialSymbols.h specialSymbols.c
	$(CC) $(FLAG) specialSymbols.c

clean:
	rm -rf *.o a.out




