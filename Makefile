CC = gcc
CFLAGS = -Wall -Iinclude $(shell sdl2-config --cflags) -I.
LDFLAGS = -export-dynamic $(shell sdl2-config --libs)
SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c,obj/%.o,$(SOURCES))
EXECUTABLE = bin/game

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
