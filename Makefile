CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = ft_printf

CFILES = libft/ft_strchr.c \
	libft/ft_calloc.c \
	libft/ft_memset.c \
	libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_strlen.c \
	libft/ft_memcpy.c \
	ft_printf.c \
	fprinter_1.c

HEADER = libft/libft.h \
	printf.h

OFILES = $(CFILES:.c=.o)

