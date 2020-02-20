SRCS	= ft_printf.c ft_printf_pointer.c ft_printf_int.c ft_printf_misc.c ft_printf_str.c ft_printf_char.c ft_printf_percent.c ft_printf_uint.c ft_printf_x.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			make -C ./libft/
			cp libft/libft.a ${NAME}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}
all:		${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re
