# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 08:16:18 by kkaiyawo          #+#    #+#              #
#    Updated: 2023/08/01 18:09:59 by kkaiyawo         ###   ########.fr        #
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
SRC_FILE		=	color.c draw.c file.c hook.c init.c intersect.c minirt.c\
					obj_camera.c obj_cylinder_intersect.c obj_cylinder.c\
					obj_plane.c obj_sphere.c raycast.c raytrace.c shade.c\
					shadow.c translate.c obj_cone.c\
					ps_error.c ps_getinfo_go_get.c ps_getinfo_utils_get.c \
					ps_verify_i_c_comment.c ps_verify_utils_brightness.c\
					ps_verify_utils_resolution_1.c ps_verify_verify_1.c\
					ps_getinfo_get_info.c ps_getinfo_go_get_more.c ps_print_test.c\
					ps_verify_utils0.c ps_verify_utils_resolution_0.c \
					ps_verify_verify_0.c ps_verify_verify_file.c\
					algebra1.c algebra2.c algebra3.c algebra4.c
HEADER_FILE		=	minirt.h algebra.h color.h

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
CFLAG			=	-g -Wall -Wextra -Werror -O3 #-fsanitize=address
MLX_LIB			=	-lm -framework OpenGL -framework AppKit
MLX_INCL		=	-Imlx
RM				=	rm -f

all:			${LIB_AR} ${BUILD_DIR} ${NAME}

${LIBFT_AR}:
					find ${LIBFT_DIR} -maxdepth 0 -exec make -C {} \;

${MLX_AR}:
					find ${MLX_DIR} -maxdepth 0 -exec make -C {} \;

cleanlib:
					find ${LIBFT_DIR} -maxdepth 0 -exec make clean -C {} \;
					find ${MLX_DIR} -maxdepth 0 -exec make clean -C {} \;

fcleanlib:
					find ${LIBFT_DIR} -maxdepth 0 -exec make fclean -C {} \;
					find ${MLX_DIR} -maxdepth 0 -exec make clean -C {} \;

${NAME}:		${SRC_OBJ}
					${CC} ${CFLAG} ${MLX_LIB} ${SRC_OBJ} ${LIB_AR} -o ${NAME}

${BUILD_DIR}:
					mkdir -p ${BUILD_DIR}

${BUILD_DIR}%.o:${SRC_DIR}%.c
					${CC} ${CFLAG} ${MLX_INCL} -I${SRC_DIR} -c -o $@ $^

clean:			cleanlib
					${RM} ${SRC_OBJ}

fclean:			clean fcleanlib
					${RM} ${NAME}

firetruckclean:
					${RM} ${SRC_OBJ}
					${RM} ${NAME}

re:				fclean all

test:			all
					./${NAME} files/wrong.rt

.PHONY:			all library clean fclean re
