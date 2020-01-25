all: frequency 

frequency_lib.o: frequency_lib.c frequency_lib.h 
	gcc -Wall -g -fPIC -c frequency_lib.c
main: main1.c frequency_lib.h 
	gcc -Wall -g -c main.c
frequency: frequency_libd main.o
	gcc -Wall -g -o frequency main.o ./frequency_lib.so
frequency_libd: frequency_lib.o 
	gcc -shared -o frequency_lib.so frequency_lib.o

.PHONY: clean all

clean:
	rm *.o *.a *.so frequency