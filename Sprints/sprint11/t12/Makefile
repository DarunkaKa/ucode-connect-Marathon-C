CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc
CAT = playlist
INC = $(wildcard inc/*.h)
SRC = $(wildcard src/*.c)

all: $(CAT)

$(CAT): $(INC) $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

uninstall:
	rm -f $(CAT)

clean:

reinstall: uninstall all

