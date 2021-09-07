NAME =		libftprintf.a

FLAGS = 	-Wall -Wextra -Werror

SRC =		ft_printf.c \
			sources/ft_printf_utils.c \
			sources/ft_printf_num.c \
			sources/ft_printf_num_utils.c \
			sources/ft_printf_str.c \
			sources/ft_printf_conv_proc.c

OBJ = 		$(SRC:.c=.o)

all: 	    $(NAME)

$(NAME):	$(OBJ) includes/ft_printf.h ./libft/libft.h
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) ./libft/libft.a $(OBJ) $?

.c.o:
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

clean :
			$(MAKE) clean -C ./libft
			rm -rf $(OBJ)

fclean : 	clean
			$(MAKE) fclean -C ./libft
			rm -rf $(NAME)

re : 		fclean all
