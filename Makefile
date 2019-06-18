output: HW1b.o
	gcc HW1b.o -o output

HW1b.o: HW1b.c
	gcc -c HW1b.c

clean:
	rm *.0 output
