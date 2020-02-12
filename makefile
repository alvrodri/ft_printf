SRCS	= ft_printf.c ft_printf_specific.c ft_printf_pointer.c
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
re:			fclean bonus
.PHONY:		all clean fclean re
