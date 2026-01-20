CC = gcc
CFLAGS = -std=c89 -Wall -g `pkg-config libxml-2.0 --cflags`
LDFLAGS = `pkg-config libxml-2.0 --libs`

all: bm.out

bm.out: bm.c base.o facility.o
	$(CC) $(CFLAGS) -o bm.out bm.c base.o facility.o $(LDFLAGS)

base.o: base.c base.h
	$(CC) $(CFLAGS) -c base.c

facility.o: facility.c facility.h
	$(CC) $(CFLAGS) -c facility.c

clean:
	rm -f *.o bm.out