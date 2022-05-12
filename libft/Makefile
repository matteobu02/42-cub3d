NAME		=	libft.a

AR			=	ar -rc

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I $(INCLUDES)

SRCS		=	ft_putendl_fd.c	\
				ft_strcmp.c		\
				ft_strlen.c		\
				ft_strrstr.c

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	../includes/


all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)

clean:
			@rm -rf $(OBJS)
			@printf "\e[31;3mClean Libft files\e[0m\n"

fclean:		clean
			@rm -rf $(NAME)
			@printf "\e[31;3mClean Libft lib\e[0m\n"

re:			fclean all

.PHONY:		all clean fclean re
