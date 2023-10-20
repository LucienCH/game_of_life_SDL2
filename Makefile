CC = gcc
CFLAGS = -Wall -Iinclude `sdl2-config --cflags --libs` -I.
LDFLAGS =
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
