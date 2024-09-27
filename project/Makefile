NAME = minishell
SRC = ${wildcard srcs/*.c}
OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Werror -Wall -Wextra -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

%.o : %.c 
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

all : $(NAME)

$(NAME) : ${OBJ}
	make re -C ./libft
	$(CC) ${OBJ} -lreadline -Llibft -lft -o ${NAME}

clean:
	make clean -C ./libft
	rm -f ${OBJ}

fclean: clean
		make fclean -C ./libft
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re