LIBFT = ./libft/libft.a

NAME	= libftprintf.a

SRCS	= 	ft_printf.c\
			sources/ft_char.c\
			sources/ft_hexa.c\
			sources/ft_int.c\
			sources/ft_params_search.c\
			sources/ft_percent.c\
			sources/ft_pointer.c\
			sources/ft_string.c\
			sources/ft_uint.c\

OBJS 	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS 	= -Wall -Wextra -Werror -Iincludes -c

$(NAME): ${OBJS}
		${MAKE} -C ./libft
		cp libft/libft.a ${NAME}
		ar rc ${NAME} ${OBJS}

all:	${NAME} ${OBJS}

clean:
		${MAKE} clean -C ./libft
		rm -f ${OBJS}

fclean:	clean
		${MAKE} fclean -C ./libft
		rm -f ${NAME}

re:		fclean all