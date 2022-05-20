# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:30:02 by lyaiche           #+#    #+#              #
#    Updated: 2022/05/20 17:38:52 by mbucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN_SRC	=	main.c

SRCS_SRC	=	parsing.c		\
				parsing_map.c	\
				free.c
				
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
NAME = cub3d
CFLAGS = -Wall -Wextra -Werror -g #${SANIFLAG}
SANIFLAG = -fsanitize=address

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
								@gcc ${CFLAGS} ${MAIN_OBJ} -L ${LIBFT} -lft -o ${NAME}
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
