NAME		=	ft_ls

SRCS_FILES	=	main.c \
				ft_ls_parse.c \
				ft_ls.c \
				display.c \
				tools.c

LIBFT		=	libft.a

LIBFTPATH	=	./libft

CC			=	gcc

FLAGS		=	-Wall -Werror -Wextra

INCLUDES	=	includes -I libft/includes

SRCS = $(addprefix srcs/,$(SRCS_FILES))

all: $(NAME)

$(NAME): $(LIBFT)
	@echo "[Compiling $(NAME)]"
	@$(CC) -o $(NAME) $(SRCS) -I$(INCLUDES) -L$(LIBFTPATH) -lft

$(LIBFT):
	@make -C $(LIBFTPATH)

clean:
	@make clean -C $(LIBFTPATH)
	@echo "[Cleaning ft_ls folders]"

fclean: clean
	@make fclean -C $(LIBFTPATH)
	@echo "[Fully cleaning ft_ls folders]"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
