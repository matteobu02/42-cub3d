# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:30:02 by lyaiche           #+#    #+#              #
#    Updated: 2022/06/22 16:28:59 by mbucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN_SRC	=	main.c

SRCS_SRC	=	get_file_info.c		\
				check_file_info.c	\
				parsing_map.c		\
				parsing_utils.c		\
				parsing_utils2.c	\
				free.c				\
				degtorad.c   		\
				fixang.c            \
				keyhook.c           \
				moves.c				\
				launch.c            \
				draw_map.c          \
				draw_cube.c         \
				getpix.c            \
				put_pixel.c         \
				raycast.c           \
				draw_frame.c        \
				onedirection.c		\
				
				
SRCS_OBJ	=	${addprefix ${OBJDIR}, ${SRCS_SRC:%.c=%.o}}

MAIN_OBJ	=	${addprefix ${OBJDIR}, ${MAIN_SRC:%.c=%.o}} ${SRCS_OBJ}

#====#
#Tags#
#====#

OBJDIR = ./objs/
SRCDIR = ./main/
COMMONDIR = ./srcs/
INCLUDES = ./includes/
LIBFT = ./libft/
NAME = cub3D
CFLAGS = -Wall -Wextra -Werror -g #${SANIFLAG} 
SANIFLAG = -fsanitize=address
MLXFLAG = -lmlx -framework OpenGL -framework AppKit

#=========#
#Commandes#
#=========#					

all:							${NAME}

${OBJDIR}%.o : ${SRCDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}
${OBJDIR}%.o : ${CHECKDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${OBJDIR}%.o : ${COMMONDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${NAME}: 						${OBJDIR} ${MAIN_OBJ}
								@make -C libft
								@gcc ${CFLAGS} ${MLXFLAG} ${MAIN_OBJ} -L ${LIBFT} -lft -o ${NAME}
								@printf "\e[32;3m$@ successfully built\e[0m\n"

${OBJDIR}:						
								@mkdir -p ${OBJDIR}

clean:
								@rm -rf ${OBJDIR}
								@make -C ${LIBFT} clean
								@printf "\e[31;3mClean files\e[0m\n"

fclean:							clean
								@rm -f ${NAME}
								@make -C ${LIBFT} fclean
								@printf "\e[31;3mClean exec\e[0m\n"

re:								fclean all

.PHONY:							all clean fclean re
