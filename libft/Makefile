NAME	=	libft.a

AR		=	ar -rc

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_putendl_fd.c	\
			ft_strlen.c

OBJS	=	$(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
