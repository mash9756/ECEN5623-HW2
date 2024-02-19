#
#	
#
#	referenced stack overflow post here
#		https://stackoverflow.com/questions/14639794/getting-make-to-create-object-files-in-a-specific-directory
#
#

LIBS=-pthread
CC=gcc
CFLAGS=-Wall -Werror
PSOURCES=src/poster.c
POBJECTS=bin/poster.o
PTARGET=bin/poster

WSOURCES=src/waiter.c
WOBJECTS=bin/waiter.o
WTARGET=bin/waiter

all: build waiter poster

build:
	mkdir -p bin

waiter: waiter.o
	$(CC) $(LIBS) $(FLAGS) $(WOBJECTS) -o $(WTARGET)

waiter.o: build
	$(CC) $(LIBS) $(FLAGS) -c $(WSOURCES) -o $(WOBJECTS)

poster: poster.o
	$(CC) $(LIBS) $(FLAGS) $(POBJECTS) -o $(PTARGET)

poster.o: build
	$(CC) $(LIBS) $(FLAGS) -c $(PSOURCES) -o $(POBJECTS)

clean:
	rm -r bin