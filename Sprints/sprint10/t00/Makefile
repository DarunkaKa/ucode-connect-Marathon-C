CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc
READ_FILE = read_file
SRC = $(wildcard src/*.c)
INC = $(wildcard inc/*.h)


all: $(READ_FILE)

$(READ_FILE): $(INC) $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

uninstall:
	rm -f $(READ_FILE)

clean:

reinstall: uninstall all

