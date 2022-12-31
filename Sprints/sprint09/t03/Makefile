CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -c -o
SRC = $(wildcard src/*.c)
HEADER = $(wildcard inc/*.h)
OBJ = $(SRC:src/%.c=obj/%.o)

all: MINILIBMX

MINILIBMX: $(OBJ)
	ar rsc minilibmx.a $^

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) $@ $^

obj: 
	mkdir -p $@

uninstall:
	rm -rf obj
	rm -f minilibmx.a

clean:
	rm -rf $(OBJ)

reinstall: uninstall all
