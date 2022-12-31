CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
NAME = calc
SRC = $(wildcard src/*.c)
HEADER = $(wildcard inc/*.h)

all: $(NAME)

$(NAME): $(HEADER) $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

uninstall:
	rm -f $(NAME)

clean:
	
reinstall: uninstall all
