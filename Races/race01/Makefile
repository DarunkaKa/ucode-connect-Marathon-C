CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME = part_of_the_matrix
HEADERS = $(wildcard inc/*.h)
SOURCES = $(wildcard src/*.c)

all: $(NAME)

$(NAME): $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

uninstall:
	rm -f $(NAME)

clean:

reinstall: uninstall all
