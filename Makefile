CC = gcc
FLAG = -c 



all: main.o readText.o deleteCopy.o specialSymbols.o deleteOdd.o changeNumber.o transliterationTxt.o printTxt.o
	$(CC) main.o readText.o deleteCopy.o specialSymbols.o deleteOdd.o changeNumber.o transliterationTxt.o printTxt.o

main.o: main.c readText.h deleteCopy.h specialSymbols.h deleteOdd.h changeNumber.h printTxt.h
	$(CC) $(FLAG) main.c

readText.o: readText.h readText.c
	$(CC) $(FLAG) readText.c

deleteCopy.o: deleteCopy.h deleteCopy.c
	$(CC) $(FLAG) deleteCopy.c

specialSymbols.o: specialSymbols.h specialSymbols.c
	$(CC) $(FLAG) specialSymbols.c

deleteOdd.o: deleteOdd.h deleteOdd.c
	$(CC) $(FLAG) deleteOdd.c 

changeNumber.o: changeNumber.h changeNumber.c
	$(CC) $(FLAG) changeNumber.c 

transliterationTxt.o: transliterationTxt.h transliterationTxt.c
	$(CC) $(FLAG) transliterationTxt.c

printTxt.o: printTxt.h printTxt.c
	$(CC) $(FLAG) printTxt.c 

clean:
	rm -rf *.o a.out
