# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 16:27:20 by tfaure            #+#    #+#              #
#    Updated: 2017/04/22 23:05:45 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libft.a
SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	  ft_tolower.c ft_strstr.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	  ft_strnstr.c ft_itoa.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c ft_strchr.c ft_strrchr.c ft_strtolower.c ft_strtoupper.c \
	  ft_strrev.c ft_max.c ft_min.c ft_realloc.c get_next_line.c ft_map.c \
	  err_found.c semalloc.c free_splited_str.c len_of_tab.c ft_atof.c


CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
