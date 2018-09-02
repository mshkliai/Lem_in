NAME = lem-in

GNL = ./gnl/get_next_line.c

SRC = add_room.c join_free.c len_c.c main.c \
	new_room.c parsing.c pass_ant.c room_dup.c \
	se.c short_way.c spacer.c out_error.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

HEADER = list_lem_in.h

all: $(NAME)

$(NAME):
	cd printf && make
	gcc $(FLAGS) -c -I $(HEADER) -c $(SRC) $(GNL)
	gcc -o $(NAME) $(FLAGS) $(OBJ) get_next_line.o ./printf/libftprintf.a

clean:
	cd printf && make fclean
	rm -f $(OBJ) get_next_line.o

fclean: clean
	rm -f $(NAME)

re: fclean all
