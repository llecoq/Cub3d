# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 14:41:53 by llecoq            #+#    #+#              #
#    Updated: 2021/02/25 13:46:47 by llecoq           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

H = libft.h

CC = gcc

AR = ar

ARFLAGS = rc

CFLAGS = -Wall -Wextra -Werror 

SRC=ft_strlen.c ft_atoi.c ft_strlcpy.c ft_strlcat.c ft_memcmp.c ft_strjoin.c\
	ft_strncmp.c ft_strnstr.c ft_memset.c ft_memmove.c ft_strdup.c ft_strtrim.c\
	ft_split.c ft_strchr.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_putchar_fd.c\
	ft_strrchr.c ft_toupper.c ft_tolower.c ft_memchr.c ft_substr.c ft_calloc.c\
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_itoa.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c get_next_line.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\

OBJ = $(SRC:.c=.o)

BONUS			= 

BONUS_OBJS		= $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c	$(H)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
