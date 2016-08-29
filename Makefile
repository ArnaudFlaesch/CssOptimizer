all: mrproper cssOptimizer clean

cssOptimizer : main.o list.o functions.o
	gcc main.o list.o functions.o -o cssOptimizer

main.o : main.c
	gcc -c -Wall main.c

list.o : list.c list.h
	gcc -c -Wall list.c list.h

functions.o : functions.c functions.h
	gcc -c -Wall functions.c functions.h

clean :
	find . -name '*.o' -delete
	find . -name '*.gch' -delete

mrproper :
	find . -name '*.o' -delete
	find . -name '*.gch' -delete
	rm -rf cssOptimizer