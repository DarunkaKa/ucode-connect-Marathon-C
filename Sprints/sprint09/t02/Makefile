CC = clang
CFLAGS = -c -std=c11 -Wall -Wextra -Werror -Wpedantic
SRC = $(addprefix src/,mx_atoi.c mx_isdigit.c mx_isspace.c mx_strlen.c mx_printchar.c mx_printstr.c mx_printint.c mx_strcmp.c mx_strcpy.c)
HEADER = $(addprefix inc/,header.h)
OBJ = mx_atoi.o mx_isdigit.o mx_isspace.o mx_strlen.o mx_printchar.o mx_printstr.o mx_printint.o mx_strcmp.o mx_strcpy.o

all: MINILIBMX

MINILIBMX: $(HEADER) $(SRC)
	$(CC) $(CFLAGS) $(SRC)
	mkdir -p obj
	mv $(OBJ) obj
	ar rsc minilibmx.a $(addprefix obj/,$(OBJ))

uninstall:
	rm -rf obj
	rm -f minilibmx.a

clean:
	rm -rf $(addprefix obj/,$(OBJ))

reinstall: uninstall all
