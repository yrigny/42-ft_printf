CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

CFILES = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

CFILES_B = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OFILES = $(CFILES:.c=.o)

OFILES_B = $(CFILES_B:.c=.o)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

all: $(NAME)

bonus: $(NAME) $(OFILES_B)
	ar rs $(NAME) $(OFILES_B)

so:
	$(CC) -fPIC $(CFLAGS) $(CFILES) $(CFILES_B)
	gcc -shared -o libft.so $(OFILES) $(OFILES_B)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES) $(OFILES_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
