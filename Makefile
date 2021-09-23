NAME=		push_swap	

SRC_PATH=	src/

LIBFT_PATH=	libft/

LIBFT_LIB=	libft/libft.a

INCLUDE_PATH=	include/

SRC_FILES=	src/main.c \
		src/swap.c \
		src/push.c \
		src/rotate.c \
		src/reverse_rotate.c \
		src/big_sort.c \
		src/big_sort_utils.c \
		src/check_input.c \
		src/shorter_path.c \
		src/sort.c \
		src/utils.c \
		src/free.c \

SRC_OBJS=	${SRC_FILES:.c=.o}

CC= 		clang	

CFLAGS=		-Wall -Wextra -Werror

RM=		rm -f

all:		${NAME}

${NAME}:    	${SRC_OBJS} 
			$(MAKE) -C $(LIBFT_PATH)
			${CC} ${SRC_OBJS} ${LIBFT_LIB} -o $(NAME)

clean:
			@$(MAKE) -C ${LIBFT_PATH} clean
			${RM} ${SRC_OBJS}

fclean: 	clean
			${RM} ${NAME} ${LIBFT_LIB}

re:         	fclean all

.PHONY:        all clean fclean re
