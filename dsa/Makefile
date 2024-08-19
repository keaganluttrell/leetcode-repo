TARGET = bin/main

SRC_SRC = $(wildcard src/*.c)
SRC_LIB = $(wildcard lib/*.c)

OBJ_SRC = $(patsubst src/%.c, obj/%.o, $(SRC_SRC))
OBJ_LIB = $(patsubst lib/%.c, obj/%.o, $(SRC_LIB))

OBJ = $(OBJ_SRC) $(OBJ_LIB)

DIRS = bin obj 

run: clean default
	./$(TARGET)

test: clean default

default: dirs $(TARGET)

clean:
	rm -rf obj/*.o
	rm -rf bin/*

dirs:
	mkdir -p $(DIRS)

$(TARGET): $(OBJ)
	gcc -g -o $@ $?

obj/%.o : src/%.c
	gcc -g -c $< -o $@ -Iinclude 

obj/%.o : lib/%.c
	gcc -g -c $< -o $@ -Iinclude 
