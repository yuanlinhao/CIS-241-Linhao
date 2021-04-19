COMPILER = gcc

sort: main.o sorter.o
	$(COMPILER) -g main.o sorter.o file_lib.o -o sort

main.o: main.c
	$(COMPILER) -std=c99 -g -c main.c -o main.o
	
sorter.o: sorter.c
	$(COMPILER) -std=c99 -g -c sorter.c -o sorter.o
		
clean:
	$(RM) -f sort main.o sorter.o