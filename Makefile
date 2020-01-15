all: frequency frequency_r

frequency_lib.o: frequency_lib.c frequency_lib.h 
	gcc -Wall -g -fPIC -c frequency_lib.c
main1: main1.c frequency_lib.h 
	gcc -Wall -g -c main1.c
main2: main2.c frequency_lib.h 
	gcc -Wall -g -c main2.c
frequency: frequency_libd main1.o
	gcc -Wall -g -o frequency main1.o ./frequency_lib.so
frequency_r: frequency_libd main2.o
	gcc -Wall -g -o frequency_r main2.o ./frequency_lib.so
frequency_libd: frequency_lib.o 
	gcc -shared -o frequency_lib.so frequency_lib.o

.PHONY: clean all

clean:
	rm *.o *.a *.so frequency frequency_r