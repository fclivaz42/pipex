SUBDIR	= srcs

OBJDIR	= objs

SRCS	= $(wildcard ${SUBDIR}/*.c)

OBJ		= $(patsubst ${SUBDIR}/%.c, ${OBJDIR}/%.o, ${SRCS})

NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra -O2

CC = gcc

${NAME}:	${OBJ}
			ar rc ${NAME} ${OBJ}

${OBJDIR}/%.o:	${SUBDIR}/%.c | ${OBJDIR}
				${CC} ${CFLAGS} -c $< -o $@

${OBJDIR}:
		mkdir -p $@

norminette:
		@norminette ./ > /dev/null && echo "Norminette OK!"

all:	${NAME}

clean:
		rm -rf ${OBJDIR}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all fclean clean re
