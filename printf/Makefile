# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/08 15:36:33 by mshkliai          #+#    #+#              #
#    Updated: 2018/05/10 14:01:36 by mshkliai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = ./libft/

SRC = itoa_base.c d_strlen.c conv_s.c conv_d.c demo_itoa.c eco.c prewidth.c \
conv_c.c width.c conv_o_2.c conv_x_2.c  conv_p.c conv_u.c help_d.c flag.c \
wat_flag.c conv_nu_c.c conv_nu_s.c len_c.c conv_i.c demo_itoa_2.c len_to.c \
len_uni.c len_wchr.c unsign.c ft_printf.c integer.c validator.c check_null.c

DRC_LIB = ft_atoi.c ft_bzero.c ft_countwords.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c \
ft_lstdelone.c ft_lstend.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
ft_putnbr_fd.c ft_putnbr.c ft_putrts.c ft_putstr_fd.c ft_putstr.c \
ft_rtsdup.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen_fd.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
ft_toupper.c

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c -I $(HEADER) -c $(SRC) $(addprefix $(LIB), $(DRC_LIB))
	ar rc $(NAME) $(SRC:.c=.o) $(DRC_LIB:.c=.o)
	ranlib $(NAME)

clean:
	rm -f $(DRC_LIB:.c=.o) $(SRC:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:all clean fclean re
