NAME = minirt
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
HEADER = minirt.h

LIBFT = ./libft/libft.a
LIBFT_PATH = libft

SRC =	minirt.c error.c	\
		verify/verify_file.c verify/verify_0.c verify/verify_1.c \
		verify/utils_camera.c verify/utils0.c

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
