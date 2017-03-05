NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRC =


OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@
	@echo "Compiling Object Files"

$(LIBFT):
	@make -c libft

$(NAME): $(LIBFT) $(OBJ)
	gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all
