SHELL=/bin/sh
CC=gcc
#CC=nvcc
CFLAGS= -O3

default:	sysCT tools/input-generator tools/text-file-creator

libs/vec.o:	libs/vec.c libs/vec.h
			$(CC) $(CFLAGS) -c libs/vec.c -o libs/vec.o

libs/LDSE.o:	libs/LDSE.c libs/LDSE_private.h libs/LDSE.h
			$(CC) $(CFLAGS) -c libs/LDSE.c -o libs/LDSE.o

libs/libCT.o: libs/libCT.c libs/libCT.h libs/libCT_private.h
		$(CC) -c libs/libCT.c -o libs/libCT.o $(CFLAGS)

tools/input-generator:	tools/input-generator.c
		$(CC) $(CFLAGS) tools/input-generator.c -o tools/input-generator

tools/text-file-creator:	tools/text-file-creator.c
		$(CC) $(CFLAGS) tools/text-file-creator.c -o tools/text-file-creator

sysCT:	sysCT.c  sysCT.h libs/libCT.o libs/LDSE.o libs/vec.o
	$(CC) $(CFLAGS) sysCT.c libs/libCT.o libs/LDSE.o libs/vec.o -o sysCT

clean:
	rm -f sysCT tools/input-generator tools/text-file-creator *.o libs/*.o core a.out *.*~ Makefile~

all: aplicacao
