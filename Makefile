NAME = lem-in

all: $(NAME)
	
SRC = add_room.c join_free.c len_c.c main.c \
	new_room.c parsing.c pass_ant.c room_dup.c \
	se.c short_way.c spacer.c out_error.c get_next_line.c

S_SRC = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Werror -Wextra

OBJ = $(S_SRC:.c=.o)

PRINTF = ./printf/libftprintf.a

END = \033[0m

GREEN = \033[0;32m

RED = \033[0;31m

A = \033[1;36m

$(NAME): $(OBJ) $(HEADER)
	@cd printf && \
	echo "\n\033[1;32m          Compiling \033[1;31mPRINTF...$(END)$(END)\n" \
	&& make
	@gcc -o $(NAME) $(FLAGS) $(OBJ) $(PRINTF) && \
		echo "$(GREEN)Objective files and libftprintf.a $(A)-->$(RED) lem-in\
	$(END)$(END)$(END)"

$(OBJ): %.o: %.c
	@gcc -c $< -o $@ $(FLAGS) && \
		echo "$(GREEN)$<$(A) --> $(RED)$@$(END)$(END)$(END)"

clean:
	@rm -f $(OBJ)
	@cd printf && make fclean && echo "\033[0;36mRemoved .o files$(END)"

fclean: clean
	@rm -f $(NAME) && echo "\033[1;34mRemoved $(NAME)$(END)"

re: fclean all

.PHONY:all clean fclean re