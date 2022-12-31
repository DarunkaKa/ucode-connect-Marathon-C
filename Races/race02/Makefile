CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc
NAME = way_home
HEADERS = $(wildcard inc/*.h)
SOURCES = $(wildcard src/*.c)

all: $(NAME)

$(NAME): $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

uninstall:
	rm -f $(NAME)

clean:

reinstall: uninstall all
