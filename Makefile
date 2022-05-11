# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:30:02 by lyaiche           #+#    #+#              #
#    Updated: 2022/05/11 17:52:18 by lyaiche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=======================================#
#[CUB3D] Fonctions partie principale#
#=======================================#

SRCS = 	

MAIN = 

SRCS_OBJ = ${addprefix ${OBJDIR}, ${SRCS_SRC:%.c=%.o}}

MAIN_OBJ = ${addprefix ${OBJDIR}, ${MAIN_SRC:%.c=%.o}} ${SRCS_OBJ}

#====#
#Tags#
#====#

NAME = cub3D
CFLAGS = -Wall -Wextra -Werror ${SANIFLAG} -D BUFFER_SIZE=${BUFFER_SIZE}
OBJDIR = ./objs/
SRCDIR = ./main/
SRCSDIR = ./srcs/
INCLUDES = ./includes/
CC = gcc
SANIFLAG = -fsanitize=address -g
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
BUFFER_SIZE = 100

#=========#
#Commandes#
#=========#	

${OBJDIR}%.o : ${SRCDIR}%.c
								@${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${OBJDIR}%.o : ${SRCSDIR}%.c
								@${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

$(NAME) :						${OBJDIR}
								make -C libft
								@gcc ${CFLAGS} ${SRCS} -o ${NAME}

${OBJDIR}:						
								@mkdir -p ${OBJDIR}

all : $(NAME)

clean :
								make clean -C libft
								rm -rf ${OBJDIR}

fclean :						clean
								make fclean -C libft
								rm -f ${NAME}

re : 							fclean all

.PHONY :						all clean fclean re