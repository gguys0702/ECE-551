myProgram:test-power.o power.o
	gcc -o myProgram test-power.o power.o -lm
test-power.o:test-power.c
	gcc -std=gnu99 -pedantic -Wall -c test-power.c
power.o: power.c
	gcc -std=gnu99 -pedantic -Wall -c power.c


