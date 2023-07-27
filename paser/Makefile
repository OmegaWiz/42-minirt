NAME = minirt
CC = gcc -g #-fsanitize=address
CFLAGS = -Wall -Werror -Wextra
HEADER = minirt.h

LIBFT = ./libft/libft.a
LIBFT_PATH = libft

SRC =	minirt.c error.c print_test.c	\
		verify/verify_file.c verify/verify_0.c verify/verify_1.c \
		verify/utils0.c verify/i_c_comment.c \
		verify/utils_resolution_0.c verify/utils_resolution_1.c \
		get_info/get_info.c get_info/go_get.c get_info/go_get_more.c \
		get_info/utils_get.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(OBJ) $(LIBFT) -o $(NAME)
$(LIBFT) :
			make -C $(LIBFT_PATH)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all


.PHONY: all clean fclean re
