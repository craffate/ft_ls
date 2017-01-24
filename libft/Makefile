NAME		=	libft.a

SRCS		=	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_isspace.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putendl_fd.c \
				ft_strmap.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strmapi.c \
				ft_putendl.c \
				ft_strjoin.c \
				ft_itoa.c \
				ft_strtrim.c \
				ft_absval.c \
				ft_factorial.c \
				ft_strsplit.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_itoa_base.c \
				ft_putwchar.c \
				ft_putwstr.c \
				ft_wstrlen.c \
				ft_wstrcat.c \
				ft_wstrdup.c \
				ft_wstrnew.c \
				ft_wcharlen.c \
				ft_wstrjoin.c \
				ft_wstrchr.c \
				ft_wstrcmp.c \
				ft_wstrncmp.c

GNL_SRCS	=	get_next_line.c

PF_SRCS		=	ft_printf.c \
				ft_parse.c \
				ft_save.c \
				ft_is.c \
				ft_is2.c \
				ft_preprocess.c \
				ft_preprocess2.c \
				ft_process.c \
				ft_process2.c \
				ft_process3.c \
				ft_colors.c \
				ft_toolbox.c \
				ft_toolbox2.c

OBJS		=	$(addprefix srcs/, $(SRCS:.c=.o))

GNL_OBJS	=	$(addprefix get_next_line/, $(GNL_SRCS:.c=.o))

PF_OBJS		=	$(addprefix ft_printf/, $(PF_SRCS:.c=.o))

INCS		=	./includes

CC			=	clang

FLAGS		=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(PF_OBJS)
	@echo "[Compiling $(NAME)]"
	@ar -rcs $(NAME) $(OBJS) $(GNL_OBJS) $(PF_OBJS)
	@ranlib $(NAME)

srcs/%.o: srcs/%.c
	@echo "[Converting $@]"
	@$(CC) -o $@ -c $< $(FLAGS) -I$(INCS)

get_next_line/%.o: get_next_line/%.c
	@echo "[Converting $@]"
	@$(CC) -o $@ -c $< $(FLAGS) -I$(INCS)

ft_printf/%.o: ft_printf/%.c
	@echo "[Converting $@]"
	@$(CC) -o $@ -c $< $(FLAGS) -I$(INCS)

clean:
	@echo "[Cleaning libft folders]"
	@rm -f $(OBJS) $(GNL_OBJS) $(PF_OBJS)

fclean: clean
	@echo "[Fully cleaning libft folders]"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean
