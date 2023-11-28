CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

LIBFT_FILES = ft_strchr.c ft_atoi.c ft_strlen.c
PRINTF_FILES = ft_printf.c fprinter_1.c	fprinter_2.c

LIBFT_SRC = $(addprefix	libft/,	$(LIBFT_FILES))
SRC = $(LIBFT_SRC) $(PRINTF_FILES)

OFILES = $(SRC:.c=.o)

LIBFT_DEP = libft/libft.h
PRINTF_DEP = ft_printf.h $(LIBFT_SRC)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

all: $(NAME)

bonus: all

$(LIBFT_SRC:.c=.o): %.o: %.c $(LIBFT_DEP)
	$(CC) $(CFLAGS)	-c $< -o $@

$(PRINTF_FILES:.c=.o): %.o: %.c	$(PRINTF_DEP)
	$(CC) $(CFLAGS)	-c $< -o $@

clean:
	rm -f $(OFILES)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all	bonus clean	fclean re
