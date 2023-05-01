SUBDIR	= srcs

OBJDIR	= objs

SRCS	= $(wildcard ${SUBDIR}/*.c)

OBJ		= $(patsubst ${SUBDIR}/%.c, ${OBJDIR}/%.o, ${SRCS})

NAME	= pipex

CFLAGS	= -Wall -Werror -Wextra -O2

CC = gcc

${NAME}:	${OBJ}
			make -C libft all
			${CC} ${OBJ} -o ${NAME} -Llibft -lft

${OBJDIR}/%.o:	${SUBDIR}/%.c | ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}:
		mkdir -p $@

all:	${NAME}

debug:	${OBJ}
		make -C libft all
		${CC} ${OBJ} -o ${NAME} -Llibft -lft -fsanitize=address

clean:
		rm -rf ${OBJDIR}
		make -C libft clean

fclean:	clean
		rm -f ${NAME}
		rm -f libft/libft.a

re:		fclean all

.PHONY: all fclean clean re