# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 09:04:03 by kkaiyawo          #+#    #+#              #
#    Updated: 2023/07/16 03:44:34 by psaeyang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c\
			ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_atoi.c ft_isalpha.c\
			ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c\
			ft_strncmp.c ft_substr.c ft_bzero.c ft_isascii.c ft_memmove.c\
			ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c\
			ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c\
			ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c\
			get_next_line.c get_next_line_utils.c split_blank.c ft_atof.c \
			ft_isspace.c

SRCSB		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS		= ${SRCS:.c=.o}

OBJSB		= ${SRCSB:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

AR			= ar rcs

NAME		= libft.a

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

bonus:		${OBJS} ${OBJSB}
			${AR} ${NAME} ${OBJS} ${OBJSB}

clean:
			${RM} ${OBJS}

cleanb:		clean
			${RM} ${OBJSB}

fclean:		clean
			${RM} ${NAME}

fcleanb:	cleanb fclean

re:			fclean ${NAME}

reb:		fcleanb bonus

.PHONY:		all clean fclean re bonus
