CC = gcc
CFLAGS = -std=c99 -Wall `sdl2-config --cflags --libs`
LDFLAGS =

SOURCES = game.c
EXECUTABLE = game

all: $(SOURCES)
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(EXECUTABLE)
