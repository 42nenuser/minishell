CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror
RM = 			rm -f

SRC = 			ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c ft_putendl_fd.c \
				ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c \
				ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c ft_putnbr_fd.c \
				ft_strchr.c ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c ft_calloc.c \
				ft_isascii.c ft_itoa.c ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c \
				ft_strlcat.c ft_strmapi.c ft_strrchr.c ft_tolower.c

BNS =			ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
				ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = 			$(SRC:.c=.o)

BNSOBJ = 		$(BNS:.c=.o)

NAME = 			libft.a


all:			$(NAME)

$(NAME):		$(OBJ)
				ar rcs $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ) $(BNSOBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

bonus:			$(OBJ) $(BNSOBJ)
				ar rcs $(NAME) $(OBJ) $(BNSOBJ)