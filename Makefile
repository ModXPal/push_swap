NAME=			push_swap	

SRC_PATH=		src/

LIBFT_PATH=		libft/

LIBFT_LIB=		libft.a

INCLUDE_PATH=	include/

SRC_FILES=		src/main.c \
				src/swap.c \
				src/push.c \
				src/rotate.c \
				src/reverse_rotate.c \

SRC_OBJS=		${SRC_FILES:.c=.o}

CC= 			gcc

CFLAGS=			-Wall -Wextra -Werror

RM=				rm -f

LIBFT_OBJS=		${LIBFT_PATH}*.o

LIBFTMAKE=		$(MAKE) -C ${LIBFT_PATH} bonus

all:			${NAME}

${NAME}:    	${SRC_OBJS} pmake
				${CC} ${SRC_OBJS} ${LIBFT_OBJS}

pmake:
				${LIBFTMAKE}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${SRC_OBJS}

fclean: 		clean
				${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         	fclean all

.PHONY:        all clean fclean re pmake
