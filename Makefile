# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 08:16:18 by kkaiyawo          #+#    #+#              #
#    Updated: 2023/07/05 08:32:22 by kkaiyawo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### EXECUTABLE ###
NAME			=	miniRT

### DIRECRTORIES ###
SRC_DIR			=	./src/
LIB_DIR			=	./lib/
BUILD_DIR		=	./build/
LIBFT_DIR		=	${LIB_DIR}libft
MLX_DIR			=	${LIB_DIR}mlx

### FILES ###
SRC_FILE		=	miniRT.c hook.c\
					algebra1.c algebra2.c algebra3.c algebra4.c
HEADER_FILE		=	miniRT.h

### LIBRARIES ###
LIBFT_AR			=	${LIBFT_DIR}/libft.a
MLX_AR				=	${MLX_DIR}/libmlx.a
LIB_AR				=	${LIBFT_AR} ${MLX_AR}

### PATH ###
SRC				=	${addprefix ${BUILD_DIR},${SRC_FILE}}

### OBJECTS ###
SRC_OBJ			=	${SRC:.c=.o}
BONUS_OBJ		=	${BONUS:.c=.o}

### COMPILATION ###
CC				=	gcc
CFLAG			=	-g -Wall -Wextra -Werror -O3
MLX_LIB			=	-lm -framework OpenGL -framework AppKit
MLX_INCL		=	-Imlx
RM				=	rm -f

all:			${LIB_AR} ${BUILD_DIR} ${NAME}

${LIBFT_AR}:
					find ${LIBFT_DIR} -maxdepth 0 -exec make bonus -C {} \;

${MLX_AR}:
					find ${MLX_DIR} -maxdepth 0 -exec make -C {} \;

cleanlib:
					find ${LIBFT_DIR} -maxdepth 0 -exec make cleanb -C {} \;
					find ${MLX_DIR} -maxdepth 0 -exec make clean -C {} \;

fcleanlib:
					find ${LIBFT_DIR} -maxdepth 0 -exec make fcleanb -C {} \;
					find ${MLX_DIR} -maxdepth 0 -exec make clean -C {} \;

${NAME}:		${SRC_OBJ}
					${CC} ${CFLAG} ${MLX_LIB} ${SRC_OBJ} ${LIB_AR} -o ${NAME}

${BUILD_DIR}:
					mkdir -p ${BUILD_DIR}

${BUILD_DIR}%.o:${SRC_DIR}%.c
					${CC} ${CFLAG} ${MLX_INCL} -I${HEADER_FILE} -c -o $@ $^

clean:			cleanlib
					${RM} ${SRC_OBJ}

fclean:			clean fcleanlib
					${RM} ${NAME}

re:				fclean all

.PHONY:			all library clean fclean re