NAME		=	cub3D

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g -I $(INCLUDES)

SRCS		=	srcs/main.c

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	./includes/


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -L ./libft/ -lft -o $(NAME)

clean:
			rm -rf $(OBJS)
			make -C ./libft/ clean

fclean:		clean
			rm -rf $(NAME)
			make -C ./libft/ fclean

re:			fclean all

.PHONY:		all clean fclean re
