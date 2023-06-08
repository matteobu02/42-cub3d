NAME		=	cub3D
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I ${INCLUDES} -I libft/includes
SRCDIR		=	./srcs/
OBJDIR		=	./objs/
INCLUDES	=	./includes/
OS			=	$(shell uname)

ifeq ($(OS), Linux)
	MLXFLAGS = -lmlx -lm -lX11 -lXext
else
	MLXFLAGS = -lmlx -lm -framework AppKit -framework OpenGL
endif

SRCS	=	main.c				\
			get_file_info.c		\
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
				
				
OBJS	=	${addprefix $(OBJDIR), $(SRCS:%.c=%.o)}


# ===== #


all:			$(NAME)

$(NAME):		$(OBJDIR) $(OBJS)
				@make -C libft/
				$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -L libft -lft -o $(NAME)

bonus:			$(OBJDIR) $(OBJS)
				# TODO

clean:
				rm -rf $(OBJDIR)
				@make -C libft/ clean

fclean:			
				@make -C libft/ fclean
				rm -rf $(NAME) $(OBJDIR)

re:				fclean all

$(OBJDIR)%.o:	$(SRCDIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
				@mkdir -p $(OBJDIR)

.PHONY:			re clean fclean objs all
