NAME 	= libft.a
SRCS 	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS 	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -Iincludes -c

$(NAME): ${OBJS}
		ar rc ${NAME} ${OBJS}

all:	${NAME} ${OBJS}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all