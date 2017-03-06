NAME = fillit

CFLAGS += -Wall -Wextra -Werror

SRC = read.c \

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

.PHONY = all clean

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@
	@echo "Compiling Object Files"

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

testerror: re
	./$(NAME) examples/bad_ttmn_00
	./$(NAME) examples/bad_ttmn_01
	./$(NAME) examples/bad_ttmn_02
	./$(NAME) examples/bad_ttmn_03
	./$(NAME) examples/bad_ttmn_04
	./$(NAME) examples/bad_ttmn_05
	./$(NAME) examples/bad_ttmn_06
	./$(NAME) examples/bad_ttmn_07
	./$(NAME) examples/bad_ttmn_08
	./$(NAME) examples/bad_ttmn_09
	./$(NAME) examples/ko_00
	./$(NAME) examples/ko_01
	./$(NAME) examples/ko_02
	./$(NAME) examples/bad_26_blocks
	./$(NAME) examples/error_0
	./$(NAME) examples/error_1
	./$(NAME) examples/error_2
	./$(NAME) examples/error_3
	./$(NAME) examples/error_4
	./$(NAME) examples/error_5
	./$(NAME) examples/error_6
	./$(NAME) examples/error_7
	./$(NAME) examples/error_8
	./$(NAME) examples/error_9
	./$(NAME) examples/error_10
	./$(NAME) examples/error_11
	./$(NAME) examples/error_12
	./$(NAME) examples/error_13
	./$(NAME) examples/error_14
	./$(NAME) examples/error_15
	./$(NAME) examples/error_16
	./$(NAME) examples/error_17
	./$(NAME) examples/error_18
	./$(NAME) examples/error_19
	./$(NAME) examples/error_20
	./$(NAME) examples/error_21
	./$(NAME) examples/error_22
	./$(NAME) examples/error_23
	./$(NAME) examples/error_24
	./$(NAME) examples/error_25

test: re
	./$(NAME) examples/12_hard
	./$(NAME) examples/ok_00
	./$(NAME) examples/ok_01
	./$(NAME) examples/ok_02
	./$(NAME) examples/ok_03
	./$(NAME) examples/ok_04
	./$(NAME) examples/ok_09_block
	./$(NAME) examples/ok_11_blocks
	./$(NAME) examples/ok_13_blocks
	./$(NAME) examples/ok_25_blocks
	./$(NAME) examples/ok_26_blocks
	./$(NAME) examples/good_ttmn_00
	./$(NAME) examples/good_ttmn_01
	./$(NAME) examples/good_ttmn_02
	./$(NAME) examples/good_ttmn_03
	./$(NAME) examples/valid_0
	./$(NAME) examples/valid_1
	./$(NAME) examples/valid_2
	./$(NAME) examples/valid_3
	./$(NAME) examples/valid_4
	./$(NAME) examples/valid_5
	./$(NAME) examples/valid_6
	./$(NAME) examples/valid_7
	./$(NAME) examples/valid_8
	./$(NAME) examples/valid_9
	./$(NAME) examples/valid_10
	./$(NAME) examples/valid_11
	./$(NAME) examples/valid_12
	./$(NAME) examples/valid_13
	./$(NAME) examples/valid_14
	./$(NAME) examples/valid_15
	./$(NAME) examples/valid_16
	./$(NAME) examples/valid_17
	./$(NAME) examples/valid_18
	./$(NAME) examples/valid_19
	./$(NAME) examples/valid_20
	./$(NAME) examples/valid_21
