TARGET = jumpingBannanas
LIBS = -lGL -lGLU -lglut -lm 
CC = gcc
CFLAGS = -std=c99 -Wall -g

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBS) -o $@

clean:  
	-rm -f *.o
	-rm -f $(TARGET)

