CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

# Source files
LIBFT_FILES	= ft_strchr.c ft_calloc.c ft_memset.c ft_atoi.c	ft_bzero.c ft_strlen.c ft_memcpy.c
PRINTF_FILES = ft_printf.c fprinter_1.c	fprinter_2.c

# Prefixing	libft directory	to libft files
LIBFT_SRC =	$(addprefix	libft/,	$(LIBFT_FILES))
SRC	= $(LIBFT_SRC) $(PRINTF_FILES)

# Object files
OFILES = $(SRC:.c=.o)

# Dependencies
LIBFT_DEP =	libft/libft.h
PRINTF_DEP = ft_printf.h $(LIBFT_SRC)

# Main rule	to create the library file
$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

# Standard rules
all: $(NAME)

bonus: all

# Compiling	libft object files
$(LIBFT_SRC:.c=.o):	%.o: %.c $(LIBFT_DEP)
	$(CC) $(CFLAGS)	-c $< -o $@

# Compiling	printf object files
$(PRINTF_FILES:.c=.o): %.o:	%.c	$(PRINTF_DEP)
	$(CC) $(CFLAGS)	-c $< -o $@

# Clean	object files
clean:
	rm -f $(OFILES)

# Remove the library file
fclean:	clean
	rm -f $(NAME)

# Recompile	everything from	scratch
re:	fclean all

# Phony	targets
.PHONY:	all	bonus clean	fclean re
