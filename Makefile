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
SOURCES=src/*.c
OBJECTS=bin/process.o
TARGET=bin/process

all: build process

build:
	mkdir -p bin

process: process.o
	$(CC) $(LIBS) $(FLAGS) $(OBJECTS) -o $(TARGET)

process.o:
	$(CC) $(LIBS) $(FLAGS) -c $(SOURCES) -o $(OBJECTS)

clean:
	rm -r bin

# blah: blah.o
# 	cc blah.o -o blah # Runs third

# blah.o: blah.c
# 	cc -c blah.c -o blah.o # Runs second

# # Typically blah.c would already exist, but I want to limit any additional required files
# blah.c:
# 	echo "int main() { return 0; }" > blah.c # Runs first