CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc
CP = mx_cp
INC = $(wildcard inc/*.h)
SRC = $(wildcard src/*.c)

all: $(CP)

$(CP): $(INC) $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

uninstall:
	rm -f $(CP)

clean:

reinstall: uninstall all

